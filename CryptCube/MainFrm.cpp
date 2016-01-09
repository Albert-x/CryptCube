// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "CryptCube.h"
#include "MainFrm.h"
#include "ribbonbutton.h"
#include "CryptCubeForm.h"

//
#include "AboutDlg.h"


//
#include "ClassicKaisaForm.h"
#include "ClassicDaiHuanForm.h"
#include "BlockDESForm.h"
#include "BlockAESForm.h"
#include "BlockIDEAForm.h"
#include "StreamRC4Form.h"
#include "PublickeyRSAForm.h"
#include "PublickeyELGAMALForm.h"
#include "PublickeyECCForm.h"
#include "PublickeyDHForm.h"
#include "HashMD5Form.h"
#include "HashSHAForm.h"
#include "SignatureDSAForm.h"

#include "CodeRandomForm.h"
#include "CodeCalcForm.h"
#include "EncryptFileForm.h"
#include "EncryptStringForm.h"
#include "CodeHashForm.h"
#include "CodeStringForm.h"
#include "CodeBase64Form.h"
#include "CodeUrlForm.h"
#include "CodeColorForm.h"
#include "CodeQrForm.h"
#include "HelpForm.h"
#include "FlashDes.h"

#include "FlashAes.h"
#include "FlashRc4.h"
#include "FlsahRsa.h"
#include "FlashAffine.h"
#include "FlashMd5.h"
#include "FlashSha.h"
#include "FlashHmac.h"
#include "FlashDsa.h"
#include "FlashDiff.h"
#include "FlashCarsa.h"
#include "FlashIdea.h"
#include "FlashEcc.h"
#include "FlashElg.h"

#include "TestDes.h"
#include "TestDiff.h"
#include "TestHmac.h"
#include "TestMd5.h"
#include "TestDsa.h"
#include "TestSsl.h"

#include "BookLesson.h"
#include "Execise.h"
#include "Theory.h"
#include "WeiClass.h"

#include "HighKer.h"
#include "HighPki.h"
#include "HighEfs.h"
#include "HighOpen.h"
#include "HighPgp.h"
#include "HighSSl.h"
#include "HighFile.h"

#include "SelectTerm.h"
//���ڴ�С
#define MAX_WND_SIZE_X 900
#define MAX_WND_SIZE_Y 700
#define MIN_WND_SIZE_X 900
#define MIN_WND_SIZE_Y 700
//��Ƶ�ļ�


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_NCHITTEST()
	ON_WM_WINDOWPOSCHANGING()
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_GETMINMAXINFO()
	ON_WM_INITMENUPOPUP()
	//ON_UPDATE_COMMAND_UI  
	ON_COMMAND(ID_VIEW_CAPTION_BAR, &CMainFrame::OnViewCaptionBar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CAPTION_BAR, &CMainFrame::OnUpdateViewCaptionBar)
	ON_COMMAND(ID_APP_ABOUT, &CMainFrame::OnAppAbout)
	ON_COMMAND(ID_CLASSIC_KAISA, &CMainFrame::OnClassicKaisa)
	ON_COMMAND(ID_CLASSIC_DAIHUAN, &CMainFrame::OnClassicDaihuan)
	ON_COMMAND(ID_BLOCK_DES, &CMainFrame::OnBlockDes)
	ON_COMMAND(ID_BLOCK_AES, &CMainFrame::OnBlockAes)
	ON_COMMAND(ID_BLOCK_IDEA, &CMainFrame::OnBlockIdea)
	ON_COMMAND(ID_STREAM_RC4, &CMainFrame::OnStreamRc4)
	ON_COMMAND(ID_PUBLICKEY_RSA, &CMainFrame::OnPublickeyRsa)
	ON_COMMAND(ID_PUBLICKEY_ELGAMAL, &CMainFrame::OnPublickeyElgamal)
	ON_COMMAND(ID_HASH_MD5, &CMainFrame::OnHashMd5)
	ON_COMMAND(ID_HASH_SHA, &CMainFrame::OnHashSha)
	ON_COMMAND(ID_WELCOME, &CMainFrame::OnWelcome)
	ON_COMMAND(ID_PUBLICKEY_DH, &CMainFrame::OnPublickeyDh)
	ON_COMMAND(ID_PUBLICKEY_ECC, &CMainFrame::OnPublickeyEcc)
	ON_COMMAND(ID_APP_DONATE, &CMainFrame::OnAppDonate)
	ON_COMMAND(ID_APP_WEBSITE, &CMainFrame::OnAppWebsite)
	ON_COMMAND(ID_SIGNATURE_DSA, &CMainFrame::OnSignatureDsa)
	ON_COMMAND(ID_CODE_RANDOM, &CMainFrame::OnCodeRandom)
	ON_COMMAND(ID_ENCRYPT_STRING, &CMainFrame::OnEncryptString)
	ON_COMMAND(ID_CODE_CALC, &CMainFrame::OnCodeCalc)
	ON_COMMAND(ID_ENCRYPT_FILE, &CMainFrame::OnEncryptFile)
	ON_COMMAND(ID_CODE_HASH, &CMainFrame::OnCodeHash)
	ON_COMMAND(ID_CODE_BASE64, &CMainFrame::OnCodeBase64)
	ON_COMMAND(ID_CODE_STRING, &CMainFrame::OnCodeString)
	ON_COMMAND(ID_CODE_URL, &CMainFrame::OnCodeUrl)
	ON_COMMAND(ID_CODE_COLOR, &CMainFrame::OnCodeColor)
	ON_COMMAND(ID_CODE_QR, &CMainFrame::OnCodeQr)
	ON_COMMAND(ID_APP_HELP, &CMainFrame::OnAppHelp)
	ON_COMMAND(ID_ELG,&CMainFrame::OnElg)
	ON_COMMAND(ID_CASA,&CMainFrame::OnCASA)
	ON_COMMAND(ID_FSBH,&CMainFrame::OnFSBH)
	ON_COMMAND(ID_HMAC,&CMainFrame::OnHMAC)
	ON_COMMAND(ID_RSA,&CMainFrame::OnRsa)
	ON_COMMAND(ID_KAISA,&CMainFrame::OnKaisa)
	ON_COMMAND(ID_DANBIAO,&CMainFrame::OnDanbiao)
	ON_COMMAND(ID_AES,&CMainFrame::OnAes)
	ON_COMMAND(ID_DES,&CMainFrame::OnDes)
	ON_COMMAND(ID_DSA,&CMainFrame::OnDsa)
	ON_COMMAND(ID_IDEA,&CMainFrame::OnIdea)
	ON_COMMAND(ID_ECC,&CMainFrame::OnEcc)
	ON_COMMAND(ID_DIFFIE,&CMainFrame::OnDiffie)
	ON_COMMAND(ID_RC4,&CMainFrame::OnRc4)
	ON_COMMAND(ID_MD5,&CMainFrame::OnMd5)
	ON_COMMAND(ID_SHA,&CMainFrame::OnSha)
	ON_COMMAND(ID_ELGAMAL,&CMainFrame::OnElgamal)

	ON_COMMAND(ID_TEST_DES_AES,&CMainFrame::OnTest_DES)
	ON_COMMAND(ID_TEST_DIFF,&CMainFrame::OnTest_DIFF)
	ON_COMMAND(ID_TEST_HMAC,&CMainFrame::OnTest_HMAC)
	ON_COMMAND(ID_TEST_MD5,&CMainFrame::OnTest_MD5)
	ON_COMMAND(ID_TEST_RSA,&CMainFrame::OnTest_RSA)
	ON_COMMAND(ID_TEST_SSL,&CMainFrame::OnTest_SSL)

	ON_COMMAND(ID_TERM,&CMainFrame::OnTerm)

	ON_COMMAND(ID_BOOK,&CMainFrame::OnBook)
	ON_COMMAND(ID_EXCISE,&CMainFrame::OnExcise)
	ON_COMMAND(ID_THEORY,&CMainFrame::OnTheory)
	ON_COMMAND(ID_CLASS,&CMainFrame::OnClass)

	ON_COMMAND(ID_HIGH_KER,&CMainFrame::OnHighKer)
	ON_COMMAND(ID_HIGH_PKI,&CMainFrame::OnHighPki)
	ON_COMMAND(ID_HIGH_EFS,&CMainFrame::OnHighEfs)
	ON_COMMAND(ID_HIGH_PGP,&CMainFrame::OnHighPgp)
	ON_COMMAND(ID_HIGH_OPEN,&CMainFrame::OnHighOpen)
	ON_COMMAND(ID_HIGH_SSL,&CMainFrame::OnHighSSL)
	ON_COMMAND(ID_HIGH_FILE,&CMainFrame::OnHighFile)

	ON_COMMAND(ID_KHAN,&CMainFrame::OnKhan)
	ON_COMMAND(ID_STU,&CMainFrame::OnStu)
END_MESSAGE_MAP()

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	this->m_bAutoMenuEnable   =FALSE;    
	//m_strClassicKaisa = _T("");
	//m_strClassicDaihuan = _T("");
	//m_strBlockDES = _T("");
	//m_strBlockAES = _T("");
	//m_strStreamRC4 = _T("");
	//m_strPublicKeyRSA = _T("");
	//m_strPublicKeyDH = _T("");
	//m_strPublicKeyElGamal = _T("");
	//m_strPublicKeyECC = _T("");
	//m_strHashMD5 = _T("");
	//m_strHashSHAForm = _T("");
	//m_strSignatureDSA = _T("");

}

CMainFrame::~CMainFrame()
{
}


void CMainFrame::OnGetMinMaxInfo(MINMAXINFO   FAR*   lpMMI)
{
	lpMMI->ptMinTrackSize.x=MIN_WND_SIZE_X; //�޶���С���
	lpMMI->ptMinTrackSize.y=MIN_WND_SIZE_Y; //�޶���С�߶�
	lpMMI->ptMaxTrackSize.x=MAX_WND_SIZE_X; //�޶������
	lpMMI->ptMaxTrackSize.y=MAX_WND_SIZE_Y; //�޶����߶�
	CFrameWndEx::OnGetMinMaxInfo(lpMMI);   
}


void CMainFrame::OnWindowPosChanging(WINDOWPOS FAR* lpwndpos) 
{
	CFrameWndEx::OnWindowPosChanging(lpwndpos);

}

void CMainFrame::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos) 
{
	CFrameWndEx::OnWindowPosChanged(lpwndpos);

}

LRESULT CMainFrame::OnNcHitTest(CPoint point)
{

	if(CFrameWndEx::OnNcHitTest(point) == HTRIGHT
		|| CFrameWndEx::OnNcHitTest(point) == HTLEFT 
		|| CFrameWndEx::OnNcHitTest(point) == HTBOTTOM
		|| CFrameWndEx::OnNcHitTest(point) == HTBOTTOMLEFT
		|| CFrameWndEx::OnNcHitTest(point) == HTTOP 
		|| CFrameWndEx::OnNcHitTest(point) == HTTOPLEFT
		|| CFrameWndEx::OnNcHitTest(point) == HTTOPRIGHT
		|| CFrameWndEx::OnNcHitTest(point) == HTBOTTOMRIGHT)return HTCLIENT;
	return CFrameWndEx::OnNcHitTest(point);
}

void CMainFrame::OnSize(UINT nType, int cx, int cy)
{

	CFrameWndEx::OnSize(nType, cx, cy);

}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	CMainFrame b;
	ShowWindow(SW_HIDE);//���������� 
	//b.DoModal();�ѵ�¼������ʾ���� 
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	//
	// �������ڻ��������û�����Ԫ�ص��Ӿ�������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));

	m_wndRibbonBar.Create(this);
	InitializeRibbon();

	if (!m_wndStatusBar.CreateEx(this,0,WS_CHILD|WS_VISIBLE|CBRS_BOTTOM,AFX_IDW_STATUS_BAR))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	BOOL bNameValid;
	CString strTitlePane1;
	CString strTitlePane2;
	bNameValid = strTitlePane1.LoadString(IDS_STATUS_PANE1);
	ASSERT(bNameValid);
	bNameValid = strTitlePane2.LoadString(IDS_STATUS_PANE2);
	ASSERT(bNameValid);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, strTitlePane1, TRUE), strTitlePane1);
	m_wndStatusBar.RemoveElement(NULL);
	//m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, strTitlePane2, TRUE), strTitlePane2);
	

	m_wndStatusBar.SetInformation(_T(" "));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	//ShowWindow(SW_HIDE);
	cs.style &= ~(LONG) WS_MAXIMIZEBOX;
	cs.style &= ~(LONG) FWS_ADDTOTITLE;
	return CFrameWndEx::PreCreateWindow(cs);

}


void CMainFrame::InitializeRibbon()
{

	// ���ñ�����
	SetWindowText(_T("����ѧ���� - CryptCube"));

	// ��ʼ����ť:
	m_MainButton.SetImage(IDP_MAIN);
	m_MainButton.SetText(_T("\nf"));
	m_MainButton.SetToolTipText(_T("���˵�"));

	//����ť��Ӧ�Ĳ˵�
	m_wndRibbonBar.SetApplicationButton(&m_MainButton, CSize (45, 45));

	CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory(_T(""), IDP_MENU, IDP_MENU,CSize (32, 32),CSize (32, 32));

	pMainPanel->Add(new CMFCRibbonButton(ID_WELCOME, _T("��ʾ��ӭҳ"), -1, 0));
	pMainPanel->Add(new CMFCRibbonButton(ID_APP_ABOUT, _T("��������ѧ����"), -1, 1));
	

	pMainPanel->AddToBottom(new CMFCRibbonMainPanelButton(ID_APP_EXIT,_T("�˳�����(&X)"), 5));


	// �������Ϸ��İ���С��ť:
	m_PanelImages.SetImageSize(CSize(16, 16));
	m_PanelImages.Load(IDP_HELPSMALL);
	//m_wndRibbonBar.AddToTabs(new CMFCRibbonButton(ID_APP_HELP, _T("\na"), m_PanelImages.ExtractIcon (0)));
	m_wndRibbonBar.AddToTabs(new CMFCRibbonButton(ID_APP_ABOUT, _T("\na"), m_PanelImages.ExtractIcon (0)));


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//��ӡ��㷨ԭ�������
	CMFCRibbonCategory* pCategoryPri= m_wndRibbonBar.AddCategory(_T("�㷨ԭ��"),IDP_TOOLBAR3,IDP_TOOLBAR3,CSize (16, 16),CSize (48, 48));
	
	//��ӡ��ŵ����롱С���
	CMFCRibbonPanel* pPriClssic = pCategoryPri->AddPanel(_T("�ŵ�����"));
	pPriClssic->Add(new CKofMFCRibbonButton(ID_CASA, _T("Casar"), -1, 0));
	pPriClssic->Add(new CKofMFCRibbonButton(ID_FSBH, _T("�����û�"), -1, 1));

	
	// �������������롱С���:
	CMFCRibbonPanel* pPriBlock = pCategoryPri->AddPanel(_T("��������"));
	pPriBlock->Add(new CKofMFCRibbonButton(ID_DES, _T("DES"),-1,2));
	pPriBlock->Add(new CKofMFCRibbonButton(ID_AES, _T("AES"),-1,3));
	pPriBlock->Add(new CKofMFCRibbonButton(ID_IDEA, _T("IDEA"),-1,4));

	// �����������롱С���:
	CMFCRibbonPanel* pPriStream = pCategoryPri->AddPanel(_T("������"));
	pPriStream->Add(new CKofMFCRibbonButton(ID_RC4,_T("RC4"),-1,5));

	// ��������Կ���롱С���:
	CMFCRibbonPanel* pPriPublicKey = pCategoryPri->AddPanel(_T("��Կ����"));
	pPriPublicKey->Add(new CKofMFCRibbonButton(ID_RSA, _T("RSA"), -1, 6));
	pPriPublicKey->Add(new CKofMFCRibbonButton(ID_DIFFIE, _T("Diffie-Hellman") ,-1,7));
	pPriPublicKey->Add(new CKofMFCRibbonButton(ID_ELG, _T("ElGmal") ,-1,8));
	pPriPublicKey->Add(new CKofMFCRibbonButton(ID_ECC, _T("ECC") ,-1,9));
	

	// ������ɢ�к�����С���:
	CMFCRibbonPanel* pPriHash = pCategoryPri->AddPanel(_T("ɢ�к���"));
	pPriHash->Add(new CKofMFCRibbonButton(ID_MD5, _T("MD5"),-1,10));
	pPriHash->Add(new CKofMFCRibbonButton(ID_SHA, _T("SHA"),-1,11));

	// ����������ǩ����С���:
	CMFCRibbonPanel* pPriSignature = pCategoryPri->AddPanel(_T("����ǩ��"));
	pPriSignature->Add(new CKofMFCRibbonButton(ID_DSA, _T("DSA"),-1,12));

	///////////////////////////////////////////////////////////////////////////////////////


	// ��ӡ���̬��ʾ�������:
	CMFCRibbonCategory* pCategoryHome = m_wndRibbonBar.AddCategory(_T("��̬��ʾ"),IDP_TOOLBAR,IDP_TOOLBAR,CSize (16, 16),CSize (48, 48));
	//CMFCRibbonCategory* pCategoryHome = m_wndRibbonBar.AddCategory(_T("��̬��ʾ"),IDP_BACKGROUND,IDP_TOOLBAR,CSize (16, 16),CSize (48, 48));
	

	// �������ŵ����롱С���:
	CMFCRibbonPanel* pPanelClassic = pCategoryHome->AddPanel(_T("�ŵ�����"));
	pPanelClassic->Add(new CKofMFCRibbonButton(ID_CLASSIC_KAISA, _T("��������"), -1, 0));
	pPanelClassic->Add(new CKofMFCRibbonButton(ID_CLASSIC_DAIHUAN, _T("�����û�"), -1, 1));

	// �������������롱С���:
	CMFCRibbonPanel* pPanelBlock = pCategoryHome->AddPanel(_T("��������"));
	pPanelBlock->Add(new CKofMFCRibbonButton(ID_BLOCK_DES, _T("DES"),-1,2));
	pPanelBlock->Add(new CKofMFCRibbonButton(ID_BLOCK_AES, _T("AES"),-1,3));
	pPanelBlock->Add(new CKofMFCRibbonButton(ID_BLOCK_IDEA, _T("IDEA"),-1,4));

	// �����������롱С���:
	CMFCRibbonPanel* pPanelStream = pCategoryHome->AddPanel(_T("������"));
	pPanelStream->Add(new CKofMFCRibbonButton(ID_STREAM_RC4,_T("RC4"),-1,5));

	// ��������Կ���롱С���:
	CMFCRibbonPanel* pPanelPublicKey = pCategoryHome->AddPanel(_T("��Կ����"));
	pPanelPublicKey->Add(new CKofMFCRibbonButton(ID_PUBLICKEY_RSA, _T("RSA"), -1, 6));
	pPanelPublicKey->Add(new CKofMFCRibbonButton(ID_PUBLICKEY_DH, _T("Diffie-Hellman") ,-1,8));
	pPanelPublicKey->Add(new CKofMFCRibbonButton(ID_PUBLICKEY_ELGAMAL,_T("ElGamal") ,-1,7));
	pPanelPublicKey->Add(new CKofMFCRibbonButton(ID_PUBLICKEY_ECC, _T("ECC") ,0,9));

	// ������ɢ�к�����С���:
	CMFCRibbonPanel* pPanelHash = pCategoryHome->AddPanel(_T("ɢ�к���"));
	pPanelHash->Add(new CKofMFCRibbonButton(ID_HASH_MD5, _T("MD5"),-1,10));
	pPanelHash->Add(new CKofMFCRibbonButton(ID_HASH_SHA, _T("SHA"),-1,11));

	// ����������ǩ����С���:
	CMFCRibbonPanel* pPanelSignature = pCategoryHome->AddPanel(_T("����ǩ��"));
	pPanelSignature->Add(new CKofMFCRibbonButton(ID_SIGNATURE_DSA, _T("DSA"),-1,12));



	////////////////////////////////////////////////////////////////////////////////////////////
	
	// ��ӡ�ϰ����ԡ������:
	CMFCRibbonCategory* pCategoryTest = m_wndRibbonBar.AddCategory(_T("ϰ�����"),IDP_TOOLBARTEST,IDP_TOOLBARTEST,CSize (16, 16),CSize (48, 48));
	//pCategoryTest->Add(new CMFCRibbonButton(ID_WELCOME, _T("��ʾ��ӭҳ"), -1, 0));
	CMFCRibbonPanel* pTestBlock = pCategoryTest->AddPanel(_T("��������"));
	pTestBlock->Add(new CKofMFCRibbonButton(ID_TEST_DES_AES, _T("DES-AES"),-1,0));

	CMFCRibbonPanel* pTestPublicKey =pCategoryTest->AddPanel(_T("��Կ����"));
	pTestPublicKey->Add(new CKofMFCRibbonButton(ID_TEST_DIFF, _T("Diffie-Hellman"),-1,1));

	CMFCRibbonPanel* pTestHash =pCategoryTest->AddPanel(_T("ɢ�к���"));
	pTestHash->Add(new CKofMFCRibbonButton(ID_TEST_MD5, _T("MD5-SHA"),-1,2));
	pTestHash->Add(new CKofMFCRibbonButton(ID_TEST_HMAC, _T("HMAC"),-1,3));

	CMFCRibbonPanel* pTestSignature =pCategoryTest->AddPanel(_T("����ǩ��"));
	pTestSignature->Add(new CKofMFCRibbonButton(ID_TEST_RSA, _T("RSA-DSA"),-1,4));
	
	CMFCRibbonPanel* pTestSecure =pCategoryTest->AddPanel(_T("��ȫ�׽Ӳ�Э��"));
	pTestSecure->Add(new CKofMFCRibbonButton(ID_TEST_SSL, _T("SSL"),-1,5));



	///////////////////////////////////////////////////////////////////////////////////
	// ��ӡ�����ѧС���ߡ������:
	CMFCRibbonCategory* pCategoryTools = m_wndRibbonBar.AddCategory(_T("���빤��"), IDP_TOOLBAR2,  IDP_TOOLBAR2,CSize (48, 48),CSize (48, 48));
	//pCategoryTools->Add(new CMFCRibbonButton(ID_WELCOME, _T("��ʾ��ӭҳ"), -1, 0));

	// ����������ѧС���ߡ�С���:
	CMFCRibbonPanel* pPanelCalc = pCategoryTools->AddPanel(_T("�������㹤��"));
	pPanelCalc->Add(new CKofMFCRibbonButton(ID_CODE_CALC, _T("��ѧ֪ʶ����"), -1, 1));
	pPanelCalc->Add(new CKofMFCRibbonButton(ID_CODE_RANDOM, _T("�������"), -1, 0));

	CMFCRibbonPanel* pPanelCrypt = pCategoryTools->AddPanel(_T("���ܽ������"));
	//pPanelCrypt->Add(new CKofMFCRibbonButton(ID_ENCRYPT_STRING, _T("���ּӽ���"), -1, 2));
	//pPanelCrypt->Add(new CKofMFCRibbonButton(ID_ENCRYPT_FILE, _T("�ļ��ӽ���"), -1, 3));
	pPanelCrypt->Add(new CKofMFCRibbonButton(ID_CODE_HASH, _T("HashУ��"), -1, 2));

	CMFCRibbonPanel* pPanelCode = pCategoryTools->AddPanel(_T("����ת�����"));
	pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_STRING, _T("�ַ�����"), -1, 3));
	//pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_BASE64, _T("Base64����"), -1, 4));
	//pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_URL, _T("URL�ӽ���"), -1, 4));
	//pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_COLOR, _T("��ɫ�밴������"), -1, 5));
	pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_QR, _T("QRCode��ά��"), -1, 4));

	


	/////////////////////////////////////////////////////////////////////////////////////////////
// ��ӡ�������������:

	CMFCRibbonCategory* pCategoryTerm = m_wndRibbonBar.AddCategory(_T("��������"),IDP_TOOLBARTERM,IDP_TOOLBARTERM,CSize (48, 48),CSize (48, 48));
	// �������ŵ����롱С���:
	CMFCRibbonPanel* pPanelTerm = pCategoryTerm->AddPanel(_T("��������"));
	pPanelTerm->Add(new CKofMFCRibbonButton(ID_TERM, _T(""), -1, 0));
	
/////////////////////////////////////////////////////////////////////////////////////

//��ӡ��ο����ϡ����
	CMFCRibbonCategory* pCategoryAccord = m_wndRibbonBar.AddCategory(_T("�ο�����"),IDP_ACCORD,IDP_ACCORD,CSize (48, 48),CSize (48, 48));
	CMFCRibbonPanel* pPanelBook = pCategoryAccord->AddPanel(_T("�ο�����"));
	pPanelBook->Add(new CKofMFCRibbonButton(ID_BOOK, _T("�γ̲̽�"), -1, 0));
	pPanelBook->Add(new CKofMFCRibbonButton(ID_EXCISE, _T("ʵ���ο�"), -1, 1));
	pPanelBook->Add(new CKofMFCRibbonButton(ID_THEORY, _T("���۲ο�"), -1, 2));
	pPanelBook->Add(new CKofMFCRibbonButton(ID_CLASS, _T("΢�βο�"), -1, 3));

//�߼�Ӧ��
	CMFCRibbonCategory* pCategoryHigh = m_wndRibbonBar.AddCategory(_T("�߼�Ӧ��"),IDP_HIGH1,IDP_HIGH1,CSize (48, 48),CSize (48, 48));
	CMFCRibbonPanel* pPanelGroup = pCategoryHigh->AddPanel(_T("�����������Ӧ��"));
	pPanelGroup->Add(new CKofMFCRibbonButton(ID_HIGH_KER, _T("Kerberos"), -1, 0));

	CMFCRibbonPanel* pPanelPublic = pCategoryHigh->AddPanel(_T("��Կ�������Ӧ��"));
	pPanelPublic->Add(new CKofMFCRibbonButton(ID_HIGH_PKI, _T("PKI"), -1, 1));
	pPanelPublic->Add(new CKofMFCRibbonButton(ID_HIGH_EFS, _T("EFS"), -1, 2));

	CMFCRibbonPanel* pPanelCom = pCategoryHigh->AddPanel(_T("�ۺ�Ӧ��"));
	pPanelCom->Add(new CKofMFCRibbonButton(ID_HIGH_SSL, _T("SSL"), -1, 3));
	pPanelCom->Add(new CKofMFCRibbonButton(ID_HIGH_OPEN, _T("Openssl"), -1, 4));
	pPanelCom->Add(new CKofMFCRibbonButton(ID_HIGH_PGP, _T("PGP"), -1, 5));
	
	CMFCRibbonPanel* pPanelFile = pCategoryHigh->AddPanel(_T("�ļ�Ӧ��"));
	pPanelFile->Add(new CKofMFCRibbonButton(ID_HIGH_FILE, _T("�ļ���ȫ����"), -1, 6));

	//�ɺ�ѧԺ
	
	CMFCRibbonCategory* pCategoryKhan = m_wndRibbonBar.AddCategory(_T("�ɺ�ѧԺ"),IDP_KEHAN,IDP_KEHAN,CSize (48, 48),CSize (48, 48));
	CMFCRibbonPanel* pPanelKhan= pCategoryKhan->AddPanel(_T("KHAN"));
	pPanelKhan->Add(new CKofMFCRibbonButton(ID_KHAN, _T("�ɺ�ѧԺ"), -1, 0));
	//pPanelKhan->Add(new CKofMFCRibbonButton(ID_STU, _T("ѧ����Ʒ�ο�"), -1, 1));
	
	//ѧ����Ʒ
	CMFCRibbonCategory* pCategoryStuwork = m_wndRibbonBar.AddCategory(_T("������Ʒ"),IDP_STU,IDP_STU,CSize (48, 48),CSize (48, 48));
	CMFCRibbonPanel* pPanelStuwork= pCategoryStuwork->AddPanel(_T("������Ʒ"));
	pPanelStuwork->Add(new CKofMFCRibbonButton(ID_STU, _T(""), -1, 0));
	// ��ӿ��ٷ��ʹ���������:
	//CList<UINT, UINT> lstQATCmds;

	//lstQATCmds.AddTail(ID_FILE_NEW);
	//lstQATCmds.AddTail(ID_FILE_OPEN);
	//lstQATCmds.AddTail(ID_FILE_SAVE);
	//lstQATCmds.AddTail(ID_FILE_PRINT_DIRECT);
	//OnMenuitemOpen();
	//m_wndRibbonBar.SetQuickAccessCommands(lstQATCmds);

}



BOOL CMainFrame::CreateCaptionBar()
{

	if (!m_wndCaptionBar.Create(WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, this, ID_VIEW_CAPTION_BAR, 20, TRUE))
	{
		TRACE0("δ�ܴ���������\n");
		return FALSE;
	}

	BOOL bNameValid;

	CString strTemp, strTemp2;
	bNameValid = strTemp.LoadString(IDS_CAPTION_BUTTON);
	ASSERT(bNameValid);
	m_wndCaptionBar.SetButton(strTemp, ID_TOOLS_OPTIONS, CMFCCaptionBar::ALIGN_LEFT, FALSE);
	bNameValid = strTemp.LoadString(IDS_CAPTION_BUTTON_TIP);
	ASSERT(bNameValid);
	m_wndCaptionBar.SetButtonToolTip(strTemp);

	bNameValid = strTemp.LoadString(IDS_CAPTION_TEXT);
	ASSERT(bNameValid);
	m_wndCaptionBar.SetText(strTemp, CMFCCaptionBar::ALIGN_LEFT);

	m_wndCaptionBar.SetBitmap(IDB_INFO, RGB(255, 255, 255), FALSE, CMFCCaptionBar::ALIGN_LEFT);
	bNameValid = strTemp.LoadString(IDS_CAPTION_IMAGE_TIP);
	ASSERT(bNameValid);
	bNameValid = strTemp2.LoadString(IDS_CAPTION_IMAGE_TEXT);
	ASSERT(bNameValid);
	m_wndCaptionBar.SetImageToolTip(strTemp, strTemp2);

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

void CMainFrame::OnViewCaptionBar()
{
	m_wndCaptionBar.ShowWindow(m_wndCaptionBar.IsVisible() ? SW_HIDE : SW_SHOW);
	RecalcLayout(FALSE);
}

void CMainFrame::OnUpdateViewCaptionBar(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndCaptionBar.IsVisible());
}


void CMainFrame::SwitchToForm(int nForm)               //������ͼ�л��Ĵ��뺯��
{
	//CDocument* pDoc = GetActiveDocument();

	CView *pOldActiveView=GetActiveView();             //�������ͼ
	CView *pNewActiveView=(CView*)GetDlgItem(nForm);   //ȡ������ͼ

	if(pOldActiveView == pNewActiveView) return;
	if(pNewActiveView==NULL)
	{
		//��ЩID�ǶԻ���ı�־��,��Ҳ�����������ı�־
		switch(nForm)
		{
		case IDD_CRYPTCUBE_FORM :
			pNewActiveView=(CView*)new CCryptCubeForm;
			break;
		case IDD_CLASSIC_KAISA :
			pNewActiveView=(CView*)new CClassicKaisaForm;
			break;
		case IDD_CLASSIC_DAIHUAN :
			pNewActiveView=(CView*)new CClassicDaihuanForm;
			break;
		case IDD_BLOCK_DES :
			pNewActiveView=(CView*)new CBlockDESForm;
			break;
		case IDD_BLOCK_AES :
			pNewActiveView=(CView*)new CBlockAESForm;
			break;
		case IDD_BLOCK_IDEA :
			pNewActiveView=(CView*)new CBlockIDEAForm;
			break;
		case IDD_STREAM_RC4 :
			pNewActiveView=(CView*)new CStreamRC4Form;
			break;
		case IDD_PUBLICKEY_RSA :
			pNewActiveView=(CView*)new CPublicKeyRSAForm;
			break;
		case IDD_PUBLICKEY_DH :
			pNewActiveView=(CView*)new CPublicKeyDHForm;
			break;
		case IDD_PUBLICKEY_ELGAMAL :
			pNewActiveView=(CView*)new CPublicKeyElGamalForm;
			break;
		case IDD_PUBLICKEY_ECC :
			pNewActiveView=(CView*)new CPublicKeyECCForm;
			break;
		case IDD_HASH_MD5 :
			pNewActiveView=(CView*)new CHashMD5Form;
			break;
		case IDD_HASH_SHA :
			pNewActiveView=(CView*)new CHashSHAForm;
			break;
		case IDD_SIGNATURE_DSA :
			pNewActiveView=(CView*)new CSignatureDSAForm;
			break;
		case IDD_CODE_RANDOM :
			pNewActiveView=(CView*)new CCodeRandomForm;
			break;
		case IDD_CODE_CALC :
			pNewActiveView=(CView*)new CCodeCalcForm;
			break;
		case IDD_ENCRYPT_STRING :
			pNewActiveView=(CView*)new CEncryptStringForm;
			break;
		case IDD_ENCRYPT_FILE :
			pNewActiveView=(CView*)new CEncryptFileForm;
			break;
		case IDD_CODE_HASH :
			pNewActiveView=(CView*)new CCodeHashForm;
			break;
		case IDD_CODE_STRING :
			pNewActiveView=(CView*)new CCodeStringForm;
			break;
		case IDD_CODE_BASE64 :
			pNewActiveView=(CView*)new CCodeBase64Form;
			break;
		case IDD_CODE_URL :
			pNewActiveView=(CView*)new CCodeUrlForm;
			break;
		case IDD_CODE_COLOR :
			pNewActiveView=(CView*)new CCodeColorForm;
			break;
		case IDD_CODE_QR :
			pNewActiveView=(CView*)new CCodeQrForm;
			break;
		case IDD_HELP :
			pNewActiveView=(CView*)new CHelpForm;
			break;
		
		case IDD_LESSON :
			pNewActiveView=(CView*)new BookLesson;
			break;
		case IDD_EXCISE :
			pNewActiveView=(CView*)new CExecise;
			break;
		case IDD_THEORY :
			pNewActiveView=(CView*)new CTheory;
			break;
		case IDD_WEICLASS :
			pNewActiveView=(CView*)new CWeiClass;
			break;
		case IDD_HIGH_KER :
			pNewActiveView=(CView*)new HighKer;
			break;
		case IDD_HIGH_PKI :
			pNewActiveView=(CView*)new HighPki;
			break;
		case IDD_HIGH_EFS :
			pNewActiveView=(CView*)new HighEfs;
			break;
		case IDD_HIGH_SSL :
			pNewActiveView=(CView*)new HighSSL;
			break;
		case IDD_HIGH_FILE :
			pNewActiveView=(CView*)new HighFile;
			break;

		case IDD_HIGH_OPEN :
			pNewActiveView=(CView*)new CHighOpen;
			break;
		case IDD_HIGH_PGP :
			pNewActiveView=(CView*)new CHighPgp;
			break;
		case IDD_FLASH_CARSA :
			pNewActiveView=(CView*)new FlashCarsa;
			break;
		case IDD_FLASH_IDEA :
			pNewActiveView=(CView*)new CFlashIdea;
			break;
		case IDD_FLASH_ECC :
			pNewActiveView=(CView*)new CFlashEcc;
			break;
		case IDD_FLASH_ELG :
			pNewActiveView=(CView*)new CFlashElg;
			break;
		case IDD_SHUYU :
			pNewActiveView=(CView*)new CSelectTerm;
			break;
		}

		if(pOldActiveView->GetRuntimeClass() == pNewActiveView->GetRuntimeClass()) return;
		CCreateContext context;   //���ĵ�����ͼ����
		context.m_pCurrentDoc=pOldActiveView->GetDocument();
		pNewActiveView->Create(NULL, NULL, WS_CHILD ,
			CFrameWnd::rectDefault, this, nForm, &context);

		pNewActiveView->OnInitialUpdate();
		pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	}

	SetActiveView(pNewActiveView);        //�ı�����ͼ
	pNewActiveView->ShowWindow(SW_SHOW);  //��ʾ�µ���ͼ
	pOldActiveView->ShowWindow(SW_HIDE);  //���ؾɵ���ͼ


	if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CCryptCubeForm))
		pOldActiveView->SetDlgCtrlID(IDD_CRYPTCUBE_FORM);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CClassicKaisaForm))
		pOldActiveView->SetDlgCtrlID(IDD_CLASSIC_KAISA);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CClassicDaihuanForm))
		pOldActiveView->SetDlgCtrlID(IDD_CLASSIC_DAIHUAN);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CBlockDESForm))
		pOldActiveView->SetDlgCtrlID(IDD_BLOCK_DES);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CBlockAESForm))
		pOldActiveView->SetDlgCtrlID(IDD_BLOCK_AES);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CBlockIDEAForm))
		pOldActiveView->SetDlgCtrlID(IDD_BLOCK_IDEA);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CStreamRC4Form))
		pOldActiveView->SetDlgCtrlID(IDD_STREAM_RC4);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CPublicKeyRSAForm))
		pOldActiveView->SetDlgCtrlID(IDD_PUBLICKEY_RSA);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CPublicKeyDHForm))
		pOldActiveView->SetDlgCtrlID(IDD_PUBLICKEY_DH);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CPublicKeyElGamalForm))
		pOldActiveView->SetDlgCtrlID(IDD_PUBLICKEY_ELGAMAL);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CPublicKeyECCForm))
		pOldActiveView->SetDlgCtrlID(IDD_PUBLICKEY_ECC);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CHashMD5Form))
		pOldActiveView->SetDlgCtrlID(IDD_HASH_MD5);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CHashSHAForm))
		pOldActiveView->SetDlgCtrlID(IDD_HASH_SHA);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CSignatureDSAForm))
		pOldActiveView->SetDlgCtrlID(IDD_SIGNATURE_DSA);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CCodeRandomForm))
		pOldActiveView->SetDlgCtrlID(IDD_CODE_RANDOM);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CCodeCalcForm))
		pOldActiveView->SetDlgCtrlID(IDD_CODE_CALC);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CEncryptStringForm))
		pOldActiveView->SetDlgCtrlID(IDD_ENCRYPT_STRING);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CEncryptFileForm))
		pOldActiveView->SetDlgCtrlID(IDD_ENCRYPT_FILE);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CCodeHashForm))
		pOldActiveView->SetDlgCtrlID(IDD_CODE_HASH);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CCodeStringForm))
		pOldActiveView->SetDlgCtrlID(IDD_CODE_STRING);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CCodeBase64Form))
		pOldActiveView->SetDlgCtrlID(IDD_CODE_BASE64);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CCodeUrlForm))
		pOldActiveView->SetDlgCtrlID(IDD_CODE_URL);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CCodeColorForm))
		pOldActiveView->SetDlgCtrlID(IDD_CODE_COLOR);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CCodeQrForm))
		pOldActiveView->SetDlgCtrlID(IDD_CODE_QR);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CHelpForm))
		pOldActiveView->SetDlgCtrlID(IDD_HELP);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CExecise))
		pOldActiveView->SetDlgCtrlID(IDD_EXCISE);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CWeiClass))
		pOldActiveView->SetDlgCtrlID(IDD_WEICLASS);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CTheory))
		pOldActiveView->SetDlgCtrlID(IDD_THEORY);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(BookLesson))
		pOldActiveView->SetDlgCtrlID(IDD_LESSON);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(HighKer))
		pOldActiveView->SetDlgCtrlID(IDD_HIGH_KER);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(HighPki))
		pOldActiveView->SetDlgCtrlID(IDD_HIGH_PKI);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(HighEfs))
		pOldActiveView->SetDlgCtrlID(IDD_HIGH_EFS);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CHighOpen))
		pOldActiveView->SetDlgCtrlID(IDD_HIGH_OPEN);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CHighPgp))
		pOldActiveView->SetDlgCtrlID(IDD_HIGH_PGP);
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(HighSSL))
		pOldActiveView->SetDlgCtrlID(IDD_HIGH_SSL);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(HighFile))
		pOldActiveView->SetDlgCtrlID(IDD_HIGH_FILE);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(FlashCarsa))
		pOldActiveView->SetDlgCtrlID(IDD_FLASH_CARSA);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CFlashIdea))
		pOldActiveView->SetDlgCtrlID(IDD_FLASH_IDEA);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CFlashEcc))
		pOldActiveView->SetDlgCtrlID(IDD_FLASH_ECC);
	
	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CFlashElg))
		pOldActiveView->SetDlgCtrlID(IDD_FLASH_ELG);

	else if(pOldActiveView->GetRuntimeClass() ==RUNTIME_CLASS(CSelectTerm))
		pOldActiveView->SetDlgCtrlID(IDD_SHUYU);
	//delete pOldActiveView;   //ɾ������ͼ
	
	RecalcLayout();          //������ܴ���
}


//
void CMainFrame::OnAppDonate()
{
	CAboutDlg::OnAppDonate();
}

void CMainFrame::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


void CMainFrame::OnAppWebsite()
{
	CAboutDlg::OnAppWebsite();
}


void CMainFrame::OnAppHelp()
{
	m_wndStatusBar.SetInformation(_T("ʹ�ð���"));
	SwitchToForm(IDD_HELP);
}


void CMainFrame::OnWelcome()
{
	m_wndStatusBar.SetInformation(_T(" "));
	SwitchToForm(IDD_CRYPTCUBE_FORM);
}


//
void CMainFrame::OnClassicKaisa()
{
	m_wndStatusBar.SetInformation(_T("��������"));
	SwitchToForm(IDD_CLASSIC_KAISA);
}

void CMainFrame::OnClassicDaihuan()
{
	m_wndStatusBar.SetInformation(_T("�����û�"));
	SwitchToForm(IDD_CLASSIC_DAIHUAN);
}

void CMainFrame::OnBlockDes()
{
	m_wndStatusBar.SetInformation(_T("DES�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_BLOCK_DES);
}

void CMainFrame::OnBlockAes()
{
	m_wndStatusBar.SetInformation(_T("AES�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_BLOCK_AES);
}

void CMainFrame::OnBlockIdea()
{
	m_wndStatusBar.SetInformation(_T("IDEA�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_BLOCK_IDEA);
}

void CMainFrame::OnStreamRc4()
{
	m_wndStatusBar.SetInformation(_T("RC4�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_STREAM_RC4);
}

void CMainFrame::OnPublickeyRsa()
{
	m_wndStatusBar.SetInformation(_T("RSA�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_PUBLICKEY_RSA);
}

void CMainFrame::OnPublickeyElgamal()
{
	m_wndStatusBar.SetInformation(_T("ELGamal�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_PUBLICKEY_ELGAMAL);
}

void CMainFrame::OnHashMd5()
{
	m_wndStatusBar.SetInformation(_T("MD5�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_HASH_MD5);
}

void CMainFrame::OnHashSha()
{
	m_wndStatusBar.SetInformation(_T("SHA�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_HASH_SHA);
}

void CMainFrame::OnPublickeyDh()
{
	m_wndStatusBar.SetInformation(_T("Diffie-Hellman�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_PUBLICKEY_DH);
}

void CMainFrame::OnPublickeyEcc()
{
	m_wndStatusBar.SetInformation(_T("ECC�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_PUBLICKEY_ECC);
}

void CMainFrame::OnSignatureDsa()
{
	m_wndStatusBar.SetInformation(_T("DSA�㷨���ܹ�����ʾ"));
	SwitchToForm(IDD_SIGNATURE_DSA);
}

void CMainFrame::OnCodeRandom()
{
	m_wndStatusBar.SetInformation(_T("������ɹ���"));
	SwitchToForm(IDD_CODE_RANDOM);
}

void CMainFrame::OnCodeCalc()
{
	m_wndStatusBar.SetInformation(_T("����Ƽ���"));
	SwitchToForm(IDD_CODE_CALC);
}

void CMainFrame::OnEncryptString()
{
	m_wndStatusBar.SetInformation(_T("�����ּӽ���"));
	SwitchToForm(IDD_ENCRYPT_STRING);
}

void CMainFrame::OnEncryptFile()
{
	m_wndStatusBar.SetInformation(_T("���ļ��ӽ���"));
	SwitchToForm(IDD_ENCRYPT_FILE);
}

void CMainFrame::OnCodeHash()
{
	m_wndStatusBar.SetInformation(_T("�����ļ���У��ֵ"));
	SwitchToForm(IDD_CODE_HASH);
}

void CMainFrame::OnCodeString()
{
	m_wndStatusBar.SetInformation(_T("���ַ����ò�ͬ�ķ�ʽ������ʮ��������ʾ"));
	SwitchToForm(IDD_CODE_STRING);
}

void CMainFrame::OnCodeBase64()
{
	m_wndStatusBar.SetInformation(_T("Base64����ת��"));
	SwitchToForm(IDD_CODE_BASE64);
}

void CMainFrame::OnCodeUrl()
{
	m_wndStatusBar.SetInformation(_T("��URL���ӽ��б���ͽ���"));
	SwitchToForm(IDD_CODE_URL);
}

void CMainFrame::OnCodeColor()
{
	m_wndStatusBar.SetInformation(_T("��ȡ��ɫ�ͼ��̰����Ļ�����"));
	SwitchToForm(IDD_CODE_COLOR);
}

void CMainFrame::OnCodeQr()
{
	m_wndStatusBar.SetInformation(_T("���ɷ��� GB/T 18284-2000 ���ұ�׼��QR��ά��"));
	SwitchToForm(IDD_CODE_QR);
}



	



/////////////////////////////////////////////////////////////

//Flash..

void CMainFrame::OnKaisa()
{
	m_wndStatusBar.SetInformation(_T("��������"));
	
}

void CMainFrame::OnCASA()
{
	m_wndStatusBar.SetInformation(_T("Casar"));
	FlashCarsa pCasa;
	pCasa.DoModal();
	
}
void CMainFrame::OnElg()
{
	m_wndStatusBar.SetInformation(_T("ElGmal"));
		CFlashElg pElg;
	pElg.DoModal();
	
}
void CMainFrame::OnDanbiao()
{
	m_wndStatusBar.SetInformation(_T("�����û�"));
	
}

void CMainFrame::OnDes()
{
	m_wndStatusBar.SetInformation(_T("DES�㷨���ܹ�����ʾ"));
		FlashDes des;
	des.DoModal();
	
}

void CMainFrame::OnAes()
{
	m_wndStatusBar.SetInformation(_T("AES�㷨���ܹ�����ʾ"));
	FlashAes aes;
	aes.DoModal();
}

void CMainFrame::OnIdea()
{
	m_wndStatusBar.SetInformation(_T("IDEA�㷨���ܹ�����ʾ"));
	CFlashIdea pIdea;
	pIdea.DoModal();
	
}

void CMainFrame::OnRc4()
{
	m_wndStatusBar.SetInformation(_T("RC4�㷨���ܹ�����ʾ"));
	FlashRc4 rc4;
	rc4.DoModal();
	
}

void CMainFrame::OnRsa()
{
	m_wndStatusBar.SetInformation(_T("RSA�㷨���ܹ�����ʾ"));
	FlsahRsa Rsa;
	Rsa.DoModal();
}

void CMainFrame::OnElgamal()
{
	m_wndStatusBar.SetInformation(_T("ELGamal�㷨���ܹ�����ʾ"));


}

void CMainFrame::OnMd5()
{
	m_wndStatusBar.SetInformation(_T("MD5�㷨���ܹ�����ʾ"));
	FlashMd5 pMd5;
	pMd5.DoModal();
}

void CMainFrame::OnSha()
{
	m_wndStatusBar.SetInformation(_T("SHA�㷨���ܹ�����ʾ"));
	FlashSha pSha;
	pSha.DoModal();
}

void CMainFrame::OnDiffie()
{
	m_wndStatusBar.SetInformation(_T("Diffie-Hellman�㷨���ܹ�����ʾ"));
		FlashDiff pDiff;
	pDiff.DoModal();
}

void CMainFrame::OnEcc()
{
	m_wndStatusBar.SetInformation(_T("ECC�㷨���ܹ�����ʾ"));
	CFlashEcc pEcc;
	pEcc.DoModal();
	
}

void CMainFrame::OnDsa()
{
	m_wndStatusBar.SetInformation(_T("DSA�㷨���ܹ�����ʾ"));
	FlashDsa pDha;
	pDha.DoModal();
}

void CMainFrame::OnFSBH()
{
	m_wndStatusBar.SetInformation(_T("Affine�㷨������ʾ"));
	FlashAffine pAffine;
	pAffine.DoModal();
	
}
void CMainFrame::OnHMAC()
{
	m_wndStatusBar.SetInformation(_T("HMAC�㷨������ʾ"));
	FlashHmac pFlashHmac;
	pFlashHmac.DoModal();
	
}
//ϰ�����

void CMainFrame::OnTest_DES()
{
	m_wndStatusBar.SetInformation(_T("DES-AESϰ�����"));
	TestDes pDes;
	pDes.DoModal();
	//ShellExecute(NULL,"open","DES-AES-Exercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
void CMainFrame::OnTest_DIFF()
{
	m_wndStatusBar.SetInformation(_T("Diffie-Hellmanϰ�����"));
	TestDiff pTestDiff;
	pTestDiff.DoModal();
	//ShellExecute(NULL,"open","D-HExercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
void CMainFrame::OnTest_HMAC()
{
	m_wndStatusBar.SetInformation(_T("HMACϰ�����"));
	TestHmac pHmac;
	pHmac.DoModal();
		//ShellExecute(NULL,"open","HMAC_Exercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
void CMainFrame::OnTest_MD5()
{
	m_wndStatusBar.SetInformation(_T("MD5-SHAϰ�����"));
	TestMd5 pMd5;
	pMd5.DoModal();
		//ShellExecute(NULL,"open","MD5-SHAExercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
void CMainFrame::OnTest_RSA()
{
	m_wndStatusBar.SetInformation(_T("RSA-DSAϰ�����"));
	TestDsa pDsa;
	pDsa.DoModal();
//ShellExecute(NULL,"open","RSA-DSA.swf",NULL,NULL,SW_MAXIMIZE);
	
}
void CMainFrame::OnTest_SSL()
{
	m_wndStatusBar.SetInformation(_T("SSLϰ�����"));
	TestSsl pSsl;
	pSsl.DoModal();
	//ShellExecute(NULL,"open","SSLExercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
//��������
void CMainFrame::OnTerm()
{
	m_wndStatusBar.SetInformation(_T("��������"));
	SwitchToForm(IDD_SHUYU);
	//ShellExecute(NULL,"open","flashSource\\��������.pdf",NULL,NULL,SW_MAXIMIZE);
}
//�ο�����
void CMainFrame::OnBook()
{
	m_wndStatusBar.SetInformation(_T("�γ̲̽Ĳο�"));
	SwitchToForm(IDD_LESSON);
	
}
void CMainFrame::OnExcise()
{
	m_wndStatusBar.SetInformation(_T("ʵ���ο�"));
	SwitchToForm(IDD_EXCISE);
	
}
void CMainFrame::OnTheory()
{
	m_wndStatusBar.SetInformation(_T("���۲ο�"));
	SwitchToForm(IDD_THEORY);
	
}
void CMainFrame::OnClass()
{
	m_wndStatusBar.SetInformation(_T("΢�βο�"));
	SwitchToForm(IDD_WEICLASS);
	
}
//�߼�
void CMainFrame::OnHighKer()
{
	m_wndStatusBar.SetInformation(_T("kerberosӦ��"));
	SwitchToForm(IDD_HIGH_KER);
}
void CMainFrame::OnHighPki()
{
	m_wndStatusBar.SetInformation(_T("PKIӦ��"));
	SwitchToForm(IDD_HIGH_PKI);
}
void CMainFrame::OnHighPgp()
{
	m_wndStatusBar.SetInformation(_T("PKIӦ��"));
	SwitchToForm(IDD_HIGH_PGP);
}
void CMainFrame::OnHighOpen()
{
	m_wndStatusBar.SetInformation(_T("OPENSSLӦ��"));
	SwitchToForm(IDD_HIGH_OPEN);
}
void CMainFrame::OnHighEfs()
{
	m_wndStatusBar.SetInformation(_T("EFSӦ��"));
	SwitchToForm(IDD_HIGH_EFS);
}

void CMainFrame::OnHighSSL()
{
	m_wndStatusBar.SetInformation(_T("SSLӦ��"));
	SwitchToForm(IDD_HIGH_SSL);
}
void CMainFrame::OnHighFile()
{
	m_wndStatusBar.SetInformation(_T("�ļ�Ӧ��"));
	SwitchToForm(IDD_HIGH_FILE);
	
	//HighFile pfile;
	//pfile.DoModal();
}
void CMainFrame::OnKhan()
{
	m_wndStatusBar.SetInformation(_T("�ɺ�ѧԺ"));
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}

	CString strFileName = strCurDrt;
	strFileName += "flashSource\\Journey into Cryptography"; //����Ϊ��ľ���·��
	ShellExecute(NULL,"open",strFileName,NULL,NULL,SW_SHOW);
}

void CMainFrame::OnStu()
{
	m_wndStatusBar.SetInformation(_T("�ɺ�ѧԺ"));
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}

	CString strFileName = strCurDrt;
	strFileName += "StuWork"; //����Ϊ��ľ���·��
	ShellExecute(NULL,"open",strFileName,NULL,NULL,SW_SHOW);
}