// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// MainFrm.cpp : CMainFrame 类的实现
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
//窗口大小
#define MAX_WND_SIZE_X 900
#define MAX_WND_SIZE_Y 700
#define MIN_WND_SIZE_X 900
#define MIN_WND_SIZE_Y 700
//视频文件


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

// CMainFrame 构造/析构

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
	lpMMI->ptMinTrackSize.x=MIN_WND_SIZE_X; //限定最小宽度
	lpMMI->ptMinTrackSize.y=MIN_WND_SIZE_Y; //限定最小高度
	lpMMI->ptMaxTrackSize.x=MAX_WND_SIZE_X; //限定最大宽度
	lpMMI->ptMaxTrackSize.y=MAX_WND_SIZE_Y; //限定最大高度
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
	ShowWindow(SW_HIDE);//隐藏主窗口 
	//b.DoModal();把登录窗口显示处理 
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	//
	// 设置用于绘制所有用户界面元素的视觉管理器
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));

	m_wndRibbonBar.Create(this);
	InitializeRibbon();

	if (!m_wndStatusBar.CreateEx(this,0,WS_CHILD|WS_VISIBLE|CBRS_BOTTOM,AFX_IDW_STATUS_BAR))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
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

	// 设置标题栏
	SetWindowText(_T("密码学盒子 - CryptCube"));

	// 初始主按钮:
	m_MainButton.SetImage(IDP_MAIN);
	m_MainButton.SetText(_T("\nf"));
	m_MainButton.SetToolTipText(_T("主菜单"));

	//主按钮对应的菜单
	m_wndRibbonBar.SetApplicationButton(&m_MainButton, CSize (45, 45));

	CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory(_T(""), IDP_MENU, IDP_MENU,CSize (32, 32),CSize (32, 32));

	pMainPanel->Add(new CMFCRibbonButton(ID_WELCOME, _T("显示欢迎页"), -1, 0));
	pMainPanel->Add(new CMFCRibbonButton(ID_APP_ABOUT, _T("关于密码学盒子"), -1, 1));
	

	pMainPanel->AddToBottom(new CMFCRibbonMainPanelButton(ID_APP_EXIT,_T("退出盒子(&X)"), 5));


	// 加载右上方的帮助小按钮:
	m_PanelImages.SetImageSize(CSize(16, 16));
	m_PanelImages.Load(IDP_HELPSMALL);
	//m_wndRibbonBar.AddToTabs(new CMFCRibbonButton(ID_APP_HELP, _T("\na"), m_PanelImages.ExtractIcon (0)));
	m_wndRibbonBar.AddToTabs(new CMFCRibbonButton(ID_APP_ABOUT, _T("\na"), m_PanelImages.ExtractIcon (0)));


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//添加“算法原理”主类别：
	CMFCRibbonCategory* pCategoryPri= m_wndRibbonBar.AddCategory(_T("算法原理"),IDP_TOOLBAR3,IDP_TOOLBAR3,CSize (16, 16),CSize (48, 48));
	
	//添加“古典密码”小面板
	CMFCRibbonPanel* pPriClssic = pCategoryPri->AddPanel(_T("古典密码"));
	pPriClssic->Add(new CKofMFCRibbonButton(ID_CASA, _T("Casar"), -1, 0));
	pPriClssic->Add(new CKofMFCRibbonButton(ID_FSBH, _T("单表置换"), -1, 1));

	
	// 创建“分组密码”小面板:
	CMFCRibbonPanel* pPriBlock = pCategoryPri->AddPanel(_T("分组密码"));
	pPriBlock->Add(new CKofMFCRibbonButton(ID_DES, _T("DES"),-1,2));
	pPriBlock->Add(new CKofMFCRibbonButton(ID_AES, _T("AES"),-1,3));
	pPriBlock->Add(new CKofMFCRibbonButton(ID_IDEA, _T("IDEA"),-1,4));

	// 创建“流密码”小面板:
	CMFCRibbonPanel* pPriStream = pCategoryPri->AddPanel(_T("流密码"));
	pPriStream->Add(new CKofMFCRibbonButton(ID_RC4,_T("RC4"),-1,5));

	// 创建“公钥密码”小面板:
	CMFCRibbonPanel* pPriPublicKey = pCategoryPri->AddPanel(_T("公钥密码"));
	pPriPublicKey->Add(new CKofMFCRibbonButton(ID_RSA, _T("RSA"), -1, 6));
	pPriPublicKey->Add(new CKofMFCRibbonButton(ID_DIFFIE, _T("Diffie-Hellman") ,-1,7));
	pPriPublicKey->Add(new CKofMFCRibbonButton(ID_ELG, _T("ElGmal") ,-1,8));
	pPriPublicKey->Add(new CKofMFCRibbonButton(ID_ECC, _T("ECC") ,-1,9));
	

	// 创建“散列函数”小面板:
	CMFCRibbonPanel* pPriHash = pCategoryPri->AddPanel(_T("散列函数"));
	pPriHash->Add(new CKofMFCRibbonButton(ID_MD5, _T("MD5"),-1,10));
	pPriHash->Add(new CKofMFCRibbonButton(ID_SHA, _T("SHA"),-1,11));

	// 创建“数字签名”小面板:
	CMFCRibbonPanel* pPriSignature = pCategoryPri->AddPanel(_T("数字签名"));
	pPriSignature->Add(new CKofMFCRibbonButton(ID_DSA, _T("DSA"),-1,12));

	///////////////////////////////////////////////////////////////////////////////////////


	// 添加“动态演示”主类别:
	CMFCRibbonCategory* pCategoryHome = m_wndRibbonBar.AddCategory(_T("动态演示"),IDP_TOOLBAR,IDP_TOOLBAR,CSize (16, 16),CSize (48, 48));
	//CMFCRibbonCategory* pCategoryHome = m_wndRibbonBar.AddCategory(_T("动态演示"),IDP_BACKGROUND,IDP_TOOLBAR,CSize (16, 16),CSize (48, 48));
	

	// 创建“古典密码”小面板:
	CMFCRibbonPanel* pPanelClassic = pCategoryHome->AddPanel(_T("古典密码"));
	pPanelClassic->Add(new CKofMFCRibbonButton(ID_CLASSIC_KAISA, _T("凯撒密码"), -1, 0));
	pPanelClassic->Add(new CKofMFCRibbonButton(ID_CLASSIC_DAIHUAN, _T("单表置换"), -1, 1));

	// 创建“分组密码”小面板:
	CMFCRibbonPanel* pPanelBlock = pCategoryHome->AddPanel(_T("分组密码"));
	pPanelBlock->Add(new CKofMFCRibbonButton(ID_BLOCK_DES, _T("DES"),-1,2));
	pPanelBlock->Add(new CKofMFCRibbonButton(ID_BLOCK_AES, _T("AES"),-1,3));
	pPanelBlock->Add(new CKofMFCRibbonButton(ID_BLOCK_IDEA, _T("IDEA"),-1,4));

	// 创建“流密码”小面板:
	CMFCRibbonPanel* pPanelStream = pCategoryHome->AddPanel(_T("流密码"));
	pPanelStream->Add(new CKofMFCRibbonButton(ID_STREAM_RC4,_T("RC4"),-1,5));

	// 创建“公钥密码”小面板:
	CMFCRibbonPanel* pPanelPublicKey = pCategoryHome->AddPanel(_T("公钥密码"));
	pPanelPublicKey->Add(new CKofMFCRibbonButton(ID_PUBLICKEY_RSA, _T("RSA"), -1, 6));
	pPanelPublicKey->Add(new CKofMFCRibbonButton(ID_PUBLICKEY_DH, _T("Diffie-Hellman") ,-1,8));
	pPanelPublicKey->Add(new CKofMFCRibbonButton(ID_PUBLICKEY_ELGAMAL,_T("ElGamal") ,-1,7));
	pPanelPublicKey->Add(new CKofMFCRibbonButton(ID_PUBLICKEY_ECC, _T("ECC") ,0,9));

	// 创建“散列函数”小面板:
	CMFCRibbonPanel* pPanelHash = pCategoryHome->AddPanel(_T("散列函数"));
	pPanelHash->Add(new CKofMFCRibbonButton(ID_HASH_MD5, _T("MD5"),-1,10));
	pPanelHash->Add(new CKofMFCRibbonButton(ID_HASH_SHA, _T("SHA"),-1,11));

	// 创建“数字签名”小面板:
	CMFCRibbonPanel* pPanelSignature = pCategoryHome->AddPanel(_T("数字签名"));
	pPanelSignature->Add(new CKofMFCRibbonButton(ID_SIGNATURE_DSA, _T("DSA"),-1,12));



	////////////////////////////////////////////////////////////////////////////////////////////
	
	// 添加“习题测试”主类别:
	CMFCRibbonCategory* pCategoryTest = m_wndRibbonBar.AddCategory(_T("习题测试"),IDP_TOOLBARTEST,IDP_TOOLBARTEST,CSize (16, 16),CSize (48, 48));
	//pCategoryTest->Add(new CMFCRibbonButton(ID_WELCOME, _T("显示欢迎页"), -1, 0));
	CMFCRibbonPanel* pTestBlock = pCategoryTest->AddPanel(_T("分组密码"));
	pTestBlock->Add(new CKofMFCRibbonButton(ID_TEST_DES_AES, _T("DES-AES"),-1,0));

	CMFCRibbonPanel* pTestPublicKey =pCategoryTest->AddPanel(_T("公钥密码"));
	pTestPublicKey->Add(new CKofMFCRibbonButton(ID_TEST_DIFF, _T("Diffie-Hellman"),-1,1));

	CMFCRibbonPanel* pTestHash =pCategoryTest->AddPanel(_T("散列函数"));
	pTestHash->Add(new CKofMFCRibbonButton(ID_TEST_MD5, _T("MD5-SHA"),-1,2));
	pTestHash->Add(new CKofMFCRibbonButton(ID_TEST_HMAC, _T("HMAC"),-1,3));

	CMFCRibbonPanel* pTestSignature =pCategoryTest->AddPanel(_T("数字签名"));
	pTestSignature->Add(new CKofMFCRibbonButton(ID_TEST_RSA, _T("RSA-DSA"),-1,4));
	
	CMFCRibbonPanel* pTestSecure =pCategoryTest->AddPanel(_T("安全套接层协议"));
	pTestSecure->Add(new CKofMFCRibbonButton(ID_TEST_SSL, _T("SSL"),-1,5));



	///////////////////////////////////////////////////////////////////////////////////
	// 添加“密码学小工具”主类别:
	CMFCRibbonCategory* pCategoryTools = m_wndRibbonBar.AddCategory(_T("密码工具"), IDP_TOOLBAR2,  IDP_TOOLBAR2,CSize (48, 48),CSize (48, 48));
	//pCategoryTools->Add(new CMFCRibbonButton(ID_WELCOME, _T("显示欢迎页"), -1, 0));

	// 创建“密码学小工具”小面板:
	CMFCRibbonPanel* pPanelCalc = pCategoryTools->AddPanel(_T("辅助计算工具"));
	pPanelCalc->Add(new CKofMFCRibbonButton(ID_CODE_CALC, _T("数学知识计算"), -1, 1));
	pPanelCalc->Add(new CKofMFCRibbonButton(ID_CODE_RANDOM, _T("随机生成"), -1, 0));

	CMFCRibbonPanel* pPanelCrypt = pCategoryTools->AddPanel(_T("加密解密相关"));
	//pPanelCrypt->Add(new CKofMFCRibbonButton(ID_ENCRYPT_STRING, _T("文字加解密"), -1, 2));
	//pPanelCrypt->Add(new CKofMFCRibbonButton(ID_ENCRYPT_FILE, _T("文件加解密"), -1, 3));
	pPanelCrypt->Add(new CKofMFCRibbonButton(ID_CODE_HASH, _T("Hash校验"), -1, 2));

	CMFCRibbonPanel* pPanelCode = pCategoryTools->AddPanel(_T("编码转换相关"));
	pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_STRING, _T("字符编码"), -1, 3));
	//pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_BASE64, _T("Base64编码"), -1, 4));
	//pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_URL, _T("URL加解密"), -1, 4));
	//pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_COLOR, _T("颜色与按键代码"), -1, 5));
	pPanelCode->Add(new CKofMFCRibbonButton(ID_CODE_QR, _T("QRCode二维码"), -1, 4));

	


	/////////////////////////////////////////////////////////////////////////////////////////////
// 添加“密码术语”主类别:

	CMFCRibbonCategory* pCategoryTerm = m_wndRibbonBar.AddCategory(_T("密码术语"),IDP_TOOLBARTERM,IDP_TOOLBARTERM,CSize (48, 48),CSize (48, 48));
	// 创建“古典密码”小面板:
	CMFCRibbonPanel* pPanelTerm = pCategoryTerm->AddPanel(_T("密码术语"));
	pPanelTerm->Add(new CKofMFCRibbonButton(ID_TERM, _T(""), -1, 0));
	
/////////////////////////////////////////////////////////////////////////////////////

//添加“参考资料”类别
	CMFCRibbonCategory* pCategoryAccord = m_wndRibbonBar.AddCategory(_T("参考资料"),IDP_ACCORD,IDP_ACCORD,CSize (48, 48),CSize (48, 48));
	CMFCRibbonPanel* pPanelBook = pCategoryAccord->AddPanel(_T("参考分类"));
	pPanelBook->Add(new CKofMFCRibbonButton(ID_BOOK, _T("课程教材"), -1, 0));
	pPanelBook->Add(new CKofMFCRibbonButton(ID_EXCISE, _T("实践参考"), -1, 1));
	pPanelBook->Add(new CKofMFCRibbonButton(ID_THEORY, _T("理论参考"), -1, 2));
	pPanelBook->Add(new CKofMFCRibbonButton(ID_CLASS, _T("微课参考"), -1, 3));

//高级应用
	CMFCRibbonCategory* pCategoryHigh = m_wndRibbonBar.AddCategory(_T("高级应用"),IDP_HIGH1,IDP_HIGH1,CSize (48, 48),CSize (48, 48));
	CMFCRibbonPanel* pPanelGroup = pCategoryHigh->AddPanel(_T("分组密码典型应用"));
	pPanelGroup->Add(new CKofMFCRibbonButton(ID_HIGH_KER, _T("Kerberos"), -1, 0));

	CMFCRibbonPanel* pPanelPublic = pCategoryHigh->AddPanel(_T("公钥密码典型应用"));
	pPanelPublic->Add(new CKofMFCRibbonButton(ID_HIGH_PKI, _T("PKI"), -1, 1));
	pPanelPublic->Add(new CKofMFCRibbonButton(ID_HIGH_EFS, _T("EFS"), -1, 2));

	CMFCRibbonPanel* pPanelCom = pCategoryHigh->AddPanel(_T("综合应用"));
	pPanelCom->Add(new CKofMFCRibbonButton(ID_HIGH_SSL, _T("SSL"), -1, 3));
	pPanelCom->Add(new CKofMFCRibbonButton(ID_HIGH_OPEN, _T("Openssl"), -1, 4));
	pPanelCom->Add(new CKofMFCRibbonButton(ID_HIGH_PGP, _T("PGP"), -1, 5));
	
	CMFCRibbonPanel* pPanelFile = pCategoryHigh->AddPanel(_T("文件应用"));
	pPanelFile->Add(new CKofMFCRibbonButton(ID_HIGH_FILE, _T("文件安全传输"), -1, 6));

	//可汗学院
	
	CMFCRibbonCategory* pCategoryKhan = m_wndRibbonBar.AddCategory(_T("可汗学院"),IDP_KEHAN,IDP_KEHAN,CSize (48, 48),CSize (48, 48));
	CMFCRibbonPanel* pPanelKhan= pCategoryKhan->AddPanel(_T("KHAN"));
	pPanelKhan->Add(new CKofMFCRibbonButton(ID_KHAN, _T("可汗学院"), -1, 0));
	//pPanelKhan->Add(new CKofMFCRibbonButton(ID_STU, _T("学生作品参考"), -1, 1));
	
	//学生作品
	CMFCRibbonCategory* pCategoryStuwork = m_wndRibbonBar.AddCategory(_T("优秀作品"),IDP_STU,IDP_STU,CSize (48, 48),CSize (48, 48));
	CMFCRibbonPanel* pPanelStuwork= pCategoryStuwork->AddPanel(_T("优秀作品"));
	pPanelStuwork->Add(new CKofMFCRibbonButton(ID_STU, _T(""), -1, 0));
	// 添加快速访问工具栏命令:
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
		TRACE0("未能创建标题栏\n");
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

// CMainFrame 诊断

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


// CMainFrame 消息处理程序

void CMainFrame::OnViewCaptionBar()
{
	m_wndCaptionBar.ShowWindow(m_wndCaptionBar.IsVisible() ? SW_HIDE : SW_SHOW);
	RecalcLayout(FALSE);
}

void CMainFrame::OnUpdateViewCaptionBar(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndCaptionBar.IsVisible());
}


void CMainFrame::SwitchToForm(int nForm)               //进行视图切换的代码函数
{
	//CDocument* pDoc = GetActiveDocument();

	CView *pOldActiveView=GetActiveView();             //保存旧视图
	CView *pNewActiveView=(CView*)GetDlgItem(nForm);   //取得新视图

	if(pOldActiveView == pNewActiveView) return;
	if(pNewActiveView==NULL)
	{
		//这些ID是对话框的标志符,但也可以用其他的标志
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
		CCreateContext context;   //将文挡和视图相连
		context.m_pCurrentDoc=pOldActiveView->GetDocument();
		pNewActiveView->Create(NULL, NULL, WS_CHILD ,
			CFrameWnd::rectDefault, this, nForm, &context);

		pNewActiveView->OnInitialUpdate();
		pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	}

	SetActiveView(pNewActiveView);        //改变活动的视图
	pNewActiveView->ShowWindow(SW_SHOW);  //显示新的视图
	pOldActiveView->ShowWindow(SW_HIDE);  //隐藏旧的视图


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
	//delete pOldActiveView;   //删除旧视图
	
	RecalcLayout();          //调整框架窗口
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
	m_wndStatusBar.SetInformation(_T("使用帮助"));
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
	m_wndStatusBar.SetInformation(_T("凯撒密码"));
	SwitchToForm(IDD_CLASSIC_KAISA);
}

void CMainFrame::OnClassicDaihuan()
{
	m_wndStatusBar.SetInformation(_T("单表置换"));
	SwitchToForm(IDD_CLASSIC_DAIHUAN);
}

void CMainFrame::OnBlockDes()
{
	m_wndStatusBar.SetInformation(_T("DES算法加密过程演示"));
	SwitchToForm(IDD_BLOCK_DES);
}

void CMainFrame::OnBlockAes()
{
	m_wndStatusBar.SetInformation(_T("AES算法加密过程演示"));
	SwitchToForm(IDD_BLOCK_AES);
}

void CMainFrame::OnBlockIdea()
{
	m_wndStatusBar.SetInformation(_T("IDEA算法加密过程演示"));
	SwitchToForm(IDD_BLOCK_IDEA);
}

void CMainFrame::OnStreamRc4()
{
	m_wndStatusBar.SetInformation(_T("RC4算法加密过程演示"));
	SwitchToForm(IDD_STREAM_RC4);
}

void CMainFrame::OnPublickeyRsa()
{
	m_wndStatusBar.SetInformation(_T("RSA算法加密过程演示"));
	SwitchToForm(IDD_PUBLICKEY_RSA);
}

void CMainFrame::OnPublickeyElgamal()
{
	m_wndStatusBar.SetInformation(_T("ELGamal算法加密过程演示"));
	SwitchToForm(IDD_PUBLICKEY_ELGAMAL);
}

void CMainFrame::OnHashMd5()
{
	m_wndStatusBar.SetInformation(_T("MD5算法加密过程演示"));
	SwitchToForm(IDD_HASH_MD5);
}

void CMainFrame::OnHashSha()
{
	m_wndStatusBar.SetInformation(_T("SHA算法加密过程演示"));
	SwitchToForm(IDD_HASH_SHA);
}

void CMainFrame::OnPublickeyDh()
{
	m_wndStatusBar.SetInformation(_T("Diffie-Hellman算法加密过程演示"));
	SwitchToForm(IDD_PUBLICKEY_DH);
}

void CMainFrame::OnPublickeyEcc()
{
	m_wndStatusBar.SetInformation(_T("ECC算法加密过程演示"));
	SwitchToForm(IDD_PUBLICKEY_ECC);
}

void CMainFrame::OnSignatureDsa()
{
	m_wndStatusBar.SetInformation(_T("DSA算法加密过程演示"));
	SwitchToForm(IDD_SIGNATURE_DSA);
}

void CMainFrame::OnCodeRandom()
{
	m_wndStatusBar.SetInformation(_T("随机生成工具"));
	SwitchToForm(IDD_CODE_RANDOM);
}

void CMainFrame::OnCodeCalc()
{
	m_wndStatusBar.SetInformation(_T("多进制计算"));
	SwitchToForm(IDD_CODE_CALC);
}

void CMainFrame::OnEncryptString()
{
	m_wndStatusBar.SetInformation(_T("对文字加解密"));
	SwitchToForm(IDD_ENCRYPT_STRING);
}

void CMainFrame::OnEncryptFile()
{
	m_wndStatusBar.SetInformation(_T("对文件加解密"));
	SwitchToForm(IDD_ENCRYPT_FILE);
}

void CMainFrame::OnCodeHash()
{
	m_wndStatusBar.SetInformation(_T("生成文件的校验值"));
	SwitchToForm(IDD_CODE_HASH);
}

void CMainFrame::OnCodeString()
{
	m_wndStatusBar.SetInformation(_T("将字符串用不同的方式编码以十六进制显示"));
	SwitchToForm(IDD_CODE_STRING);
}

void CMainFrame::OnCodeBase64()
{
	m_wndStatusBar.SetInformation(_T("Base64编码转换"));
	SwitchToForm(IDD_CODE_BASE64);
}

void CMainFrame::OnCodeUrl()
{
	m_wndStatusBar.SetInformation(_T("对URL链接进行编码和解码"));
	SwitchToForm(IDD_CODE_URL);
}

void CMainFrame::OnCodeColor()
{
	m_wndStatusBar.SetInformation(_T("获取颜色和键盘按键的机器码"));
	SwitchToForm(IDD_CODE_COLOR);
}

void CMainFrame::OnCodeQr()
{
	m_wndStatusBar.SetInformation(_T("生成符合 GB/T 18284-2000 国家标准的QR二维码"));
	SwitchToForm(IDD_CODE_QR);
}



	



/////////////////////////////////////////////////////////////

//Flash..

void CMainFrame::OnKaisa()
{
	m_wndStatusBar.SetInformation(_T("凯撒密码"));
	
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
	m_wndStatusBar.SetInformation(_T("单表置换"));
	
}

void CMainFrame::OnDes()
{
	m_wndStatusBar.SetInformation(_T("DES算法加密过程演示"));
		FlashDes des;
	des.DoModal();
	
}

void CMainFrame::OnAes()
{
	m_wndStatusBar.SetInformation(_T("AES算法加密过程演示"));
	FlashAes aes;
	aes.DoModal();
}

void CMainFrame::OnIdea()
{
	m_wndStatusBar.SetInformation(_T("IDEA算法加密过程演示"));
	CFlashIdea pIdea;
	pIdea.DoModal();
	
}

void CMainFrame::OnRc4()
{
	m_wndStatusBar.SetInformation(_T("RC4算法加密过程演示"));
	FlashRc4 rc4;
	rc4.DoModal();
	
}

void CMainFrame::OnRsa()
{
	m_wndStatusBar.SetInformation(_T("RSA算法加密过程演示"));
	FlsahRsa Rsa;
	Rsa.DoModal();
}

void CMainFrame::OnElgamal()
{
	m_wndStatusBar.SetInformation(_T("ELGamal算法加密过程演示"));


}

void CMainFrame::OnMd5()
{
	m_wndStatusBar.SetInformation(_T("MD5算法加密过程演示"));
	FlashMd5 pMd5;
	pMd5.DoModal();
}

void CMainFrame::OnSha()
{
	m_wndStatusBar.SetInformation(_T("SHA算法加密过程演示"));
	FlashSha pSha;
	pSha.DoModal();
}

void CMainFrame::OnDiffie()
{
	m_wndStatusBar.SetInformation(_T("Diffie-Hellman算法加密过程演示"));
		FlashDiff pDiff;
	pDiff.DoModal();
}

void CMainFrame::OnEcc()
{
	m_wndStatusBar.SetInformation(_T("ECC算法加密过程演示"));
	CFlashEcc pEcc;
	pEcc.DoModal();
	
}

void CMainFrame::OnDsa()
{
	m_wndStatusBar.SetInformation(_T("DSA算法加密过程演示"));
	FlashDsa pDha;
	pDha.DoModal();
}

void CMainFrame::OnFSBH()
{
	m_wndStatusBar.SetInformation(_T("Affine算法过程演示"));
	FlashAffine pAffine;
	pAffine.DoModal();
	
}
void CMainFrame::OnHMAC()
{
	m_wndStatusBar.SetInformation(_T("HMAC算法过程演示"));
	FlashHmac pFlashHmac;
	pFlashHmac.DoModal();
	
}
//习题测试

void CMainFrame::OnTest_DES()
{
	m_wndStatusBar.SetInformation(_T("DES-AES习题测试"));
	TestDes pDes;
	pDes.DoModal();
	//ShellExecute(NULL,"open","DES-AES-Exercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
void CMainFrame::OnTest_DIFF()
{
	m_wndStatusBar.SetInformation(_T("Diffie-Hellman习题测试"));
	TestDiff pTestDiff;
	pTestDiff.DoModal();
	//ShellExecute(NULL,"open","D-HExercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
void CMainFrame::OnTest_HMAC()
{
	m_wndStatusBar.SetInformation(_T("HMAC习题测试"));
	TestHmac pHmac;
	pHmac.DoModal();
		//ShellExecute(NULL,"open","HMAC_Exercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
void CMainFrame::OnTest_MD5()
{
	m_wndStatusBar.SetInformation(_T("MD5-SHA习题测试"));
	TestMd5 pMd5;
	pMd5.DoModal();
		//ShellExecute(NULL,"open","MD5-SHAExercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
void CMainFrame::OnTest_RSA()
{
	m_wndStatusBar.SetInformation(_T("RSA-DSA习题测试"));
	TestDsa pDsa;
	pDsa.DoModal();
//ShellExecute(NULL,"open","RSA-DSA.swf",NULL,NULL,SW_MAXIMIZE);
	
}
void CMainFrame::OnTest_SSL()
{
	m_wndStatusBar.SetInformation(_T("SSL习题测试"));
	TestSsl pSsl;
	pSsl.DoModal();
	//ShellExecute(NULL,"open","SSLExercise.swf",NULL,"C:/ProgramFiles/Internet Explorer",SW_MAXIMIZE);

	
}
//密码术语
void CMainFrame::OnTerm()
{
	m_wndStatusBar.SetInformation(_T("密码术语"));
	SwitchToForm(IDD_SHUYU);
	//ShellExecute(NULL,"open","flashSource\\密码术语.pdf",NULL,NULL,SW_MAXIMIZE);
}
//参考资料
void CMainFrame::OnBook()
{
	m_wndStatusBar.SetInformation(_T("课程教材参考"));
	SwitchToForm(IDD_LESSON);
	
}
void CMainFrame::OnExcise()
{
	m_wndStatusBar.SetInformation(_T("实践参考"));
	SwitchToForm(IDD_EXCISE);
	
}
void CMainFrame::OnTheory()
{
	m_wndStatusBar.SetInformation(_T("理论参考"));
	SwitchToForm(IDD_THEORY);
	
}
void CMainFrame::OnClass()
{
	m_wndStatusBar.SetInformation(_T("微课参考"));
	SwitchToForm(IDD_WEICLASS);
	
}
//高级
void CMainFrame::OnHighKer()
{
	m_wndStatusBar.SetInformation(_T("kerberos应用"));
	SwitchToForm(IDD_HIGH_KER);
}
void CMainFrame::OnHighPki()
{
	m_wndStatusBar.SetInformation(_T("PKI应用"));
	SwitchToForm(IDD_HIGH_PKI);
}
void CMainFrame::OnHighPgp()
{
	m_wndStatusBar.SetInformation(_T("PKI应用"));
	SwitchToForm(IDD_HIGH_PGP);
}
void CMainFrame::OnHighOpen()
{
	m_wndStatusBar.SetInformation(_T("OPENSSL应用"));
	SwitchToForm(IDD_HIGH_OPEN);
}
void CMainFrame::OnHighEfs()
{
	m_wndStatusBar.SetInformation(_T("EFS应用"));
	SwitchToForm(IDD_HIGH_EFS);
}

void CMainFrame::OnHighSSL()
{
	m_wndStatusBar.SetInformation(_T("SSL应用"));
	SwitchToForm(IDD_HIGH_SSL);
}
void CMainFrame::OnHighFile()
{
	m_wndStatusBar.SetInformation(_T("文件应用"));
	SwitchToForm(IDD_HIGH_FILE);
	
	//HighFile pfile;
	//pfile.DoModal();
}
void CMainFrame::OnKhan()
{
	m_wndStatusBar.SetInformation(_T("可汗学院"));
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}

	CString strFileName = strCurDrt;
	strFileName += "flashSource\\Journey into Cryptography"; //以上为获的绝对路径
	ShellExecute(NULL,"open",strFileName,NULL,NULL,SW_SHOW);
}

void CMainFrame::OnStu()
{
	m_wndStatusBar.SetInformation(_T("可汗学院"));
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}

	CString strFileName = strCurDrt;
	strFileName += "StuWork"; //以上为获的绝对路径
	ShellExecute(NULL,"open",strFileName,NULL,NULL,SW_SHOW);
}