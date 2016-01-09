// CodeQrForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeQrForm.h"
#include "QRCodeEncode.h"
#include "QRCodeEncode.h"
#include "CStringConvert.h"
// CCodeQrForm

IMPLEMENT_DYNCREATE(CCodeQrForm, CForm)

CCodeQrForm::CCodeQrForm()
: CForm(CCodeQrForm::IDD)
, m_strQR(_T(""))
, m_bDataEncoded(0)
, m_nSymbleSize(0)
, m_strComboLevel(_T(""))
, m_strComboMaskingNo(_T(""))
, m_strComboVersion(_T(""))
, m_strEditModuleSize(_T(""))
, m_bCheckAutoExtent(TRUE)
, m_strStaticBmpSize(_T(""))
, m_strStaticMaskingNo(_T(""))
, m_strStaticVersion(_T(""))
, m_bInitControl(FALSE)
{
	m_pSymbleDC = NULL;
}

CCodeQrForm::~CCodeQrForm()
{
	//����
	if (m_pSymbleDC != NULL)
	{
		m_pSymbleDC->SelectObject(m_pOldBitmap);

		delete m_pSymbleBitmap;
		delete m_pSymbleDC;
	}
}

//��ʼ��form
void CCodeQrForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	if (! m_bInitControl)
	{
		// �ݴ�ȼ�ѡ���Ĭ��ֵ
		m_comboLevel.SetCurSel(1);

		// �汾ѡ���Ĭ��ֵ
		m_comboVersion.SetCurSel(0);

		// �汾ѡ����ұ߾�̬�ı�Ĭ��ֵ
		m_strStaticVersion = _T("");

		// �����Զ����Ÿ�ѡ��
		m_checkAutoExtent.EnableWindow(FALSE);

		// ��ģͼ��ѡ����Ĭ��ֵ
		m_comboMaskingNo.SetCurSel(0);

		// ��ģͼ��ѡ����ұ߾�̬�ı�Ĭ��ֵ
		m_strStaticMaskingNo = _T("");

		// ͼ���С�����Ĭ��ֵ
		m_strEditModuleSize = _T("4");

		// ͼ���С�����Χ
		m_spinModuleSize.SetRange(1, 20);

		// ͼ����ߴ羲̬��Ĭ��ֵ
		m_strStaticBmpSize=_T("");

		// ���ð�ť
		m_buttonCopy.EnableWindow(FALSE);
		m_buttonSave.EnableWindow(FALSE);

		// ���������Ĭ��ֵ
		m_strQR = _T("����ѧ����");

		// �����ÿؼ���ֵ
		UpdateData(FALSE);
		
		// ����һ��Ĭ�϶�ά��
		CreateQRImage();
		
		// ��ʼ�����
		m_bInitControl = TRUE;
	}
}


void CCodeQrForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_QR_STRING, m_strQR);
	DDX_Control(pDX, IDC_EDIT_QR_STRING, m_editQR);
	DDX_Control(pDX, IDC_COMBOLEVEL, m_comboLevel);
	DDX_Control(pDX, IDC_COMBOVERSION, m_comboVersion);
	DDX_Control(pDX, IDC_STATICVERSION, m_staticVersion);
	DDX_Control(pDX, IDC_CHECKAUTOEXTENT, m_checkAutoExtent);
	DDX_Control(pDX, IDC_COMBOMASKINGNO, m_comboMaskingNo);
	DDX_Control(pDX, IDC_STATICMASKINGNO, m_staticMaskingNo);
	DDX_Control(pDX, IDC_EDITMODULESIZE, m_editModuleSize);
	DDX_Control(pDX, IDC_SPINMODULESIZE, m_spinModuleSize);
	DDX_Control(pDX, IDC_STATICBMPSIZE, m_staticBmpSize);
	DDX_Control(pDX, IDC_BUTTONCOPY, m_buttonCopy);
	DDX_Control(pDX, IDC_BUTTONSAVE, m_buttonSave);
	DDX_CBString(pDX, IDC_COMBOLEVEL, m_strComboLevel);
	DDX_CBString(pDX, IDC_COMBOMASKINGNO, m_strComboMaskingNo);
	DDX_CBString(pDX, IDC_COMBOVERSION, m_strComboVersion);
	DDX_Text(pDX, IDC_EDITMODULESIZE, m_strEditModuleSize);
	DDX_Check(pDX, IDC_CHECKAUTOEXTENT, m_bCheckAutoExtent);
	DDX_Text(pDX, IDC_STATICBMPSIZE, m_strStaticBmpSize);
	DDX_Text(pDX, IDC_STATICMASKINGNO, m_strStaticMaskingNo);
	DDX_Text(pDX, IDC_STATICVERSION, m_strStaticVersion);
}

BEGIN_MESSAGE_MAP(CCodeQrForm, CForm)
	ON_EN_CHANGE(IDC_EDIT_QR_STRING, &CCodeQrForm::OnEnChangeEditQrString)
	ON_CBN_SELCHANGE(IDC_COMBOLEVEL, &CCodeQrForm::OnSelChangeLevel)
	ON_CBN_SELCHANGE(IDC_COMBOVERSION, &CCodeQrForm::OnSelChangeVersion)
	ON_BN_CLICKED(IDC_CHECKAUTOEXTENT, &CCodeQrForm::OnAutoExtent)
	ON_CBN_SELCHANGE(IDC_COMBOMASKINGNO, &CCodeQrForm::OnSelChangeMaskNo)
	ON_EN_CHANGE(IDC_EDITMODULESIZE, &CCodeQrForm::OnChangeDrawSize)
	ON_EN_KILLFOCUS(IDC_EDITMODULESIZE, &CCodeQrForm::OnKillFocusDrawSize)
	ON_BN_CLICKED(IDC_BUTTONCOPY, &CCodeQrForm::OnCopy)
	ON_BN_CLICKED(IDC_BUTTONSAVE, &CCodeQrForm::OnSave)
END_MESSAGE_MAP()



// ������������ĵ�CTRL+A��ݼ��޷���Ӧ������
BOOL CCodeQrForm::PreTranslateMessage(MSG* pMsg)
{
	if(WM_KEYDOWN == pMsg->message && _T('A') == pMsg->wParam && HIBYTE(GetKeyState(VK_CONTROL)))
	{
		// ���� m_editQR��CTRL+A
		if(GetFocus()->GetSafeHwnd() == m_editQR.m_hWnd)
		{
			m_editQR.SetSel(0, -1);
			return CFormView::PreTranslateMessage(pMsg);
		}
	}
	return CForm::PreTranslateMessage(pMsg);
}

// CCodeQrForm ���

#ifdef _DEBUG
void CCodeQrForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeQrForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeQrForm ��Ϣ�������


// �ı���������ݸı�ʱִ�еĲ���������һ��QR��ͼ��
void CCodeQrForm::OnEnChangeEditQrString()
{

	// ����QR��ά��ͼ��
	CreateQRImage();

}

// ����QR��ά��ͼ��
void CCodeQrForm::CreateQRImage()
{
	UpdateData();// ��ȡ�ؼ��ϵ����ݵ�����

	int nLevel = m_comboLevel.GetCurSel(); //��ȡ����ȼ�
	int nVersion = m_comboVersion.GetCurSel(); //��ȡ���õİ汾
	int nMaskingNo = m_comboMaskingNo.GetCurSel() - 1; //��ȡ��ģͼ��

	//����һ��CQR_Encode����
	CQR_Encode* pQR_Encode = new CQR_Encode;


	//���ɶ�ά������
	// CStrT2CStrA�ǽ��ַ�������ת���ɶ��ֽڱ������CStringConvert.h
	m_bDataEncoded = pQR_Encode->EncodeData(nLevel, nVersion, m_bCheckAutoExtent, nMaskingNo, CStrT2CStrA(m_strQR));

	if (m_bDataEncoded)//����ַ�������ɹ���ִ��
	{
		if (m_pSymbleDC != NULL)
		{
			m_pSymbleDC->SelectObject(m_pOldBitmap);

			delete m_pSymbleBitmap;
			delete m_pSymbleDC;
		}

		m_nSymbleSize = pQR_Encode->m_nSymbleSize + (QR_MARGIN * 2);

		m_pSymbleBitmap = new CBitmap;
		m_pSymbleBitmap->CreateBitmap(m_nSymbleSize, m_nSymbleSize, 1, 1, NULL);

		m_pSymbleDC = new CDC;
		m_pSymbleDC->CreateCompatibleDC(NULL);

		m_pOldBitmap = m_pSymbleDC->SelectObject(m_pSymbleBitmap);

		// ͼ�����
		m_pSymbleDC->PatBlt(0, 0, m_nSymbleSize, m_nSymbleSize, WHITENESS);

		// �����ͼ
		for (int i = 0; i < pQR_Encode->m_nSymbleSize; ++i)
		{
			for (int j = 0; j < pQR_Encode->m_nSymbleSize; ++j)
			{
				if (pQR_Encode->m_byModuleData[i][j])
				{
					m_pSymbleDC->SetPixel(i + QR_MARGIN, j + QR_MARGIN, RGB(0, 0, 0));
				}
			}
		}

		// ˢ�½����ϡ��汾��ѡ����ұ�()��ֵ
		if (nVersion != pQR_Encode->m_nVersion) m_strStaticVersion.Format(_T("(%d)"), pQR_Encode->m_nVersion);
		else m_strStaticVersion.Empty();


		// ˢ�½����ϡ���ģͼ����ѡ����ұ�()��ֵ
		if (nMaskingNo == -1) m_strStaticMaskingNo.Format(_T("(%d)"), pQR_Encode->m_nMaskingNo);
		else m_strStaticMaskingNo.Empty();


		// ��������ť����ʹ��
		m_buttonCopy.EnableWindow();
		m_buttonSave.EnableWindow();

	}
	else
	{
		// ���ѡ����ұ�()��ֵ
		m_strStaticVersion =_T("");
		m_strStaticMaskingNo =_T("");

		// ����������ť
		m_buttonCopy.EnableWindow(FALSE);
		m_buttonSave.EnableWindow(FALSE);
	}

	// �ͷ�pQR_Encode����
	delete pQR_Encode;

	// ��ʾͼ��ֱ���
	ShowBitmapSize();

	// �ڽ����ϻ����Ѵ����Ķ�ά��ͼ��
	CDC *pDC=GetDC();
	OnDraw(pDC);
	ReleaseDC(pDC);

	//ˢ�¿ؼ���ֵ
	UpdateData(FALSE);
}

// ���¼��㲢��ʾͼ��ֱ���
void CCodeQrForm::ShowBitmapSize()
{
	m_strStaticBmpSize.Empty();
	if (m_bDataEncoded)
	{
		int nModuleSize = GetDlgItemInt(IDC_EDITMODULESIZE);

		if (nModuleSize >= 1 && nModuleSize <= 20) 
		{
			int nSize = m_nSymbleSize * nModuleSize;
			m_strStaticBmpSize.Format(_T( "%d �� %d"), nSize, nSize);
		}
	}
	m_staticBmpSize.SetWindowText(m_strStaticBmpSize);

}


void CCodeQrForm::OnDraw(CDC* pDC)
{
	//��ȡ���ڿͻ���������
	CRect rcClient;
	GetClientRect(&rcClient);

	if (m_bDataEncoded)
	{
		int nSrcSize = m_nSymbleSize;
		int nDstSize = min(rcClient.Width(), rcClient.Height());

		CDC* pWorkDC = new CDC;
		pWorkDC->CreateCompatibleDC(NULL);

		CBitmap* pWorkBitmap = new CBitmap;
		pWorkBitmap->CreateBitmap(nDstSize, nDstSize, 1, 1, NULL);

		CBitmap* pOldBitmap = pWorkDC->SelectObject(pWorkBitmap);
		pWorkDC->StretchBlt(0, 0, nDstSize, nDstSize, m_pSymbleDC, 0, 0, nSrcSize, nSrcSize, SRCCOPY);

		pDC->BitBlt(0, 0, nDstSize, nDstSize, pWorkDC, 0, 0, SRCCOPY);

		pWorkDC->SelectObject(pOldBitmap);
		delete pWorkBitmap;
		delete pWorkDC;
	}
	else
	{
		int nDstSize = min(rcClient.Width(), rcClient.Height());
		rcClient.SetRect(0,0,nDstSize,nDstSize);
		pDC->FillSolidRect(&rcClient, RGB(255, 255, 255));
		pDC->TextOut(nDstSize/2,nDstSize/2,_T("..."));
	}

}




void CCodeQrForm::OnSelChangeLevel() 
{
	if(m_bInitControl) CreateQRImage();
}

void CCodeQrForm::OnSelChangeVersion() 
{
	if(m_bInitControl)
	{
		m_checkAutoExtent.EnableWindow(m_comboVersion.GetCurSel() != 0 && m_comboVersion.GetCurSel() < 40);
		CreateQRImage();
	}
}

void CCodeQrForm::OnAutoExtent() 
{
	if(m_bInitControl) CreateQRImage();
}

void CCodeQrForm::OnSelChangeMaskNo() 
{
	if(m_bInitControl) CreateQRImage();
}

void CCodeQrForm::OnChangeDrawSize() 
{
	if(m_bInitControl) ShowBitmapSize();
}

void CCodeQrForm::OnKillFocusDrawSize()
{
	if(m_bInitControl)
	{

		int nDrawSize = GetDlgItemInt(IDC_EDITMODULESIZE);

		if (nDrawSize <= 0)
		{
			nDrawSize = 1;
		}
		else if (nDrawSize > 20)
		{
			nDrawSize = 20;
		}

		SetDlgItemInt(IDC_EDITMODULESIZE, nDrawSize);

		ShowBitmapSize();
	}
}

void CCodeQrForm::OnCopy() 
{
	CopyImage();
}

void CCodeQrForm::OnSave() 
{
	//if (m_strSavePath.IsEmpty())
		SaveAsImage();
	//else
	//SaveImage(); 
}


void CCodeQrForm::CopyImage(COleDataSource* pOleDataSource)
{
	int nPixelSize = m_nSymbleSize * GetDlgItemInt(IDC_EDITMODULESIZE);


	int nBmpSize = ((nPixelSize + 31) / 32) * 32 / 8;
	nBmpSize *= nPixelSize;


	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 2 + nBmpSize);

	if (hGlobal == NULL)
	{
		MessageBox(_T("�ڴ治��"), NULL, MB_ICONEXCLAMATION);
		return;
	}

	LPBYTE lpbyBits = (LPBYTE)GlobalLock(hGlobal);

	//
	LPBITMAPINFO pbmi = (LPBITMAPINFO)lpbyBits;
	LPVOID       pbdt = lpbyBits + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 2;

	// LPBITMAPINFO->BITMAPINFOHEADER
	pbmi->bmiHeader.biSize			= sizeof(BITMAPINFOHEADER);
	pbmi->bmiHeader.biWidth			= nPixelSize;
	pbmi->bmiHeader.biHeight		= nPixelSize;
	pbmi->bmiHeader.biPlanes		= 1;
	pbmi->bmiHeader.biBitCount		= 1;
	pbmi->bmiHeader.biCompression	= BI_RGB;
	pbmi->bmiHeader.biSizeImage		= nBmpSize;
	pbmi->bmiHeader.biXPelsPerMeter = 3780;
	pbmi->bmiHeader.biYPelsPerMeter = 3780;
	pbmi->bmiHeader.biClrUsed		= 0;
	pbmi->bmiHeader.biClrImportant	= 0;

	CDC* pWorkDC = new CDC;
	pWorkDC->CreateCompatibleDC(NULL);

	CBitmap* pWorkBitmap = new CBitmap;
	pWorkBitmap->CreateBitmap(nPixelSize, nPixelSize, 1, 1, NULL);

	CBitmap* pOldBitmap = pWorkDC->SelectObject(pWorkBitmap);
	pWorkDC->StretchBlt(0, 0, nPixelSize, nPixelSize, m_pSymbleDC, 0, 0, m_nSymbleSize, m_nSymbleSize, SRCCOPY);

	GetDIBits(pWorkDC->m_hDC, (HBITMAP)*pWorkBitmap, 0, nPixelSize, pbdt, pbmi, DIB_RGB_COLORS);

	GlobalUnlock(hGlobal);

	pWorkDC->SelectObject(pOldBitmap);
	delete pWorkBitmap;
	delete pWorkDC;

	if (pOleDataSource == NULL)
	{
		//
		OpenClipboard();
		EmptyClipboard();
		SetClipboardData(CF_DIB, hGlobal);
		CloseClipboard();
	}
	else
	{
		//
		pOleDataSource->CacheGlobalData(CF_DIB, hGlobal);
		pOleDataSource->DoDragDrop(DROPEFFECT_COPY);
	}
}


/////////////////////////////////////////////////////////////////////////////
// CCodeQrForm::SaveAsImage
//

void CCodeQrForm::SaveAsImage()
{
	//
	CFileDialog* pFileDialog = new CFileDialog(FALSE, _T("bmp"), m_strSavePath, OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY | OFN_PATHMUSTEXIST,
		_T("λͼ�ļ�(*.bmp)|*.bmp|ȫ���ļ�(*.*)|*.*||"), this);

	pFileDialog->m_ofn.lpstrTitle = _T("����QRCode��ά��ͼ��");

	CString strFileName;

	//���ļ����桱�Ի�������ʾ
	if (pFileDialog->DoModal() == IDOK)
		strFileName = pFileDialog->GetPathName();

	delete 	pFileDialog;

	if (strFileName.IsEmpty())
		return;

	m_strSavePath = strFileName;

	SaveImage();
}


/////////////////////////////////////////////////////////////////////////////
// CCodeQrForm::SaveImage
// 

void CCodeQrForm::SaveImage()
{
	int nPixelSize = m_nSymbleSize * GetDlgItemInt(IDC_EDITMODULESIZE);

	// λ���ݲɼ���С
	int nBmpSize = ((nPixelSize + 31) / 32) * 32 / 8;
	nBmpSize *= nPixelSize;

	// �ڴ�ӳ���ļ��Ĵ���
	HANDLE hFile = CreateFile(m_strSavePath, GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		m_strSavePath.Empty();
		MessageBox(_T("�ļ���������"), _T("QRCode��ά��ͼ��"), MB_ICONSTOP);
		return;
	}

	HANDLE hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE | SEC_COMMIT, 0, 
		sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 2 + nBmpSize, NULL);
	LPBYTE lpbyMapView = (LPBYTE)MapViewOfFile(hFileMapping, FILE_MAP_WRITE, 0, 0, 0);

	ZeroMemory(lpbyMapView, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 2 + nBmpSize);

	// �ṹ��ַ����
	LPBITMAPFILEHEADER pbfh = (LPBITMAPFILEHEADER)lpbyMapView;
	LPBITMAPINFO       pbmi = (LPBITMAPINFO)(lpbyMapView + sizeof(BITMAPFILEHEADER));
	LPVOID             pbdt = lpbyMapView + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 2;

	// BITMAPFILEHEADER
	pbfh->bfType      = (WORD) (('M' << 8) | 'B'); // "BM"
	pbfh->bfSize      = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 2 + nBmpSize;
	pbfh->bfReserved1 = 0;
	pbfh->bfReserved2 = 0;
	pbfh->bfOffBits   = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 2;

	// LPBITMAPINFO->BITMAPINFOHEADER
	pbmi->bmiHeader.biSize			= sizeof(BITMAPINFOHEADER);
	pbmi->bmiHeader.biWidth			= nPixelSize;
	pbmi->bmiHeader.biHeight		= nPixelSize;
	pbmi->bmiHeader.biPlanes		= 1;
	pbmi->bmiHeader.biBitCount		= 1;
	pbmi->bmiHeader.biCompression	= BI_RGB;
	pbmi->bmiHeader.biSizeImage		= nBmpSize;
	pbmi->bmiHeader.biXPelsPerMeter = 3780;
	pbmi->bmiHeader.biYPelsPerMeter = 3780;
	pbmi->bmiHeader.biClrUsed		= 0;
	pbmi->bmiHeader.biClrImportant	= 0;

	CDC* pWorkDC = new CDC;
	pWorkDC->CreateCompatibleDC(NULL);

	CBitmap* pWorkBitmap = new CBitmap;
	pWorkBitmap->CreateBitmap(nPixelSize, nPixelSize, 1, 1, NULL);

	CBitmap* pOldBitmap = pWorkDC->SelectObject(pWorkBitmap);
	pWorkDC->StretchBlt(0, 0, nPixelSize, nPixelSize, m_pSymbleDC, 0, 0, m_nSymbleSize, m_nSymbleSize, SRCCOPY);

	GetDIBits(pWorkDC->m_hDC, (HBITMAP)*pWorkBitmap, 0, nPixelSize, pbdt, pbmi, DIB_RGB_COLORS);

	pWorkDC->SelectObject(pOldBitmap);
	delete pWorkBitmap;
	delete pWorkDC;

	UnmapViewOfFile(lpbyMapView);
	CloseHandle(hFileMapping);
	CloseHandle(hFile);
}
