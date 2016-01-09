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

// CryptCube.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "CryptCube.h"
#include "MainFrm.h"

#include "CryptCubeDoc.h"
#include "CryptCubeForm.h"

//#pragma comment(lib,"MousehookDll.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCryptCubeApp

BEGIN_MESSAGE_MAP(CCryptCubeApp, CWinAppEx)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	
END_MESSAGE_MAP()




// CCryptCubeApp ����

CCryptCubeApp::CCryptCubeApp()
{

	
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CCryptCubeApp ����

CCryptCubeApp theApp;


// CCryptCubeApp ��ʼ��
//��ʵ�ֲ˵����
void CCryptCubeApp::OnUpdateMenupause(CCmdUI* pCmdUI) 
{
	
	m_bvisible=true;
	pCmdUI->Enable(!m_bvisible);
	
}

BOOL CCryptCubeApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(0);  // ���ر�׼ INI �ļ�ѡ��

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	
	//ShowWindow(SW_HIDE);
	//FindWindow(NULL,"����ѧ���� - CryptCube");
	//EnableMenuItem(pMenu,ID_HIGH_FILE,MF_GRAYED|MF_DISABLED);
//	HICON m_hIcon;
	//CMouseHook m_hook;
	//
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CCryptCubeDoc),
		RUNTIME_CLASS(CMainFrame),  
		RUNTIME_CLASS(CCryptCubeForm));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	
	
	//AfxGetApp()->m_pMainWnd->GetMenu()->EnableMenuItem(ID_HIGH_FILE, MF_GRAYED);//���
	m_pMainWnd->CenterWindow();     //���ڴ�ʱ��������ʾ��
	m_pMainWnd->ShowWindow(SW_SHOW);
	
	m_pMainWnd->UpdateWindow();
	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���



// �������жԻ����Ӧ�ó�������


// CCryptCubeApp �Զ������/���淽��

void CCryptCubeApp::PreLoadState()
{
}

void CCryptCubeApp::LoadCustomState()
{
}

void CCryptCubeApp::SaveCustomState()
{
}

// CCryptCubeApp ��Ϣ�������


BOOL CCryptCubeApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);
	CleanState();//���������ע���д���״̬��Ϣ
	CleanState(_T("WorkSpace"));

	return CWinAppEx::ExitInstance();
}
