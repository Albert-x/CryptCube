// FlashRc4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "FlashRc4.h"


// FlashRc4 �Ի���

IMPLEMENT_DYNAMIC(FlashRc4, CDialog)

FlashRc4::FlashRc4(CWnd* pParent /*=NULL*/)
	: CDialog(FlashRc4::IDD, pParent)
{

}

FlashRc4::~FlashRc4()
{
}

void FlashRc4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOCKWAVEFLASH1, m_flashShow);
}


BEGIN_MESSAGE_MAP(FlashRc4, CDialog)
END_MESSAGE_MAP()


// FlashRc4 ��Ϣ��������
BOOL FlashRc4::OnInitDialog()
{
	CDialog::OnInitDialog();
	CDialog::EndDialog(NULL);
	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�

	//ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	//ASSERT(IDM_ABOUTBOX < 0xF000);

		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������
	//ShowWindow(SW_SHOWMAXIMIZED ); 
	//CRect rect; 
	//GetWindowRect(rect); //�������ʾģʽ
	//m_flashShow.MoveWindow(rect,true); 
	//SetWindowLong(this->m_hWnd, GWL_STYLE, GetWindowLong(this->m_hWnd, GWL_STYLE) & WS_CAPTION);//ȥ��������
	//CClientDC dc(this);
	//int horzres = dc.GetDeviceCaps(HORZRES);//������س���
	//int vertres = dc.GetDeviceCaps(VERTRES);//����
	//this->MoveWindow(0, 0, horzres, vertres);
	//m_flashShow.SetWindowPos(&CWnd::wndTop, 0, 0, horzres, vertres, SWP_SHOWWINDOW);
	//��flashȫ����ʾ
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}

	CString strFileName = strCurDrt;
	strFileName += "flashSource\\RC4.swf"; //����Ϊ��ľ���·��
	CString strFlashPlayer =strCurDrt;
	strFlashPlayer += "flashSource\\flashplayer.exe";
	ShellExecute(NULL,"open",strFlashPlayer,strFileName,NULL,SW_SHOW);
	//m_flashShow.LoadMovie(0, strFileName);//����flash
	//m_FlashPlayer.put_WMode(L"transparent");
	//m_FlashPlayer.put_BackgroundColor(50);
	//m_flashShow.Play(); //����
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
	
	
	/*CFileDialog dialog (true,"swf",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Flash�ļ�(*.swf)|*.swf",this);
	if(dialog.DoModal()==IDOK)	
	{
		CString path=dialog.GetPathName();
		m_flashShow.LoadMovie(0,path);
		//m_flashShow.SetBackgroundColor(::GetSysColor(COLOR_3DFACE));
		CRect rc;
		m_flashShow.GetClientRect(&rc);
		m_flashShow.Play();
	}	
	return TRUE;*/
}