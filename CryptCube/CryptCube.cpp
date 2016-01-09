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

// CryptCube.cpp : 定义应用程序的类行为。
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
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	
END_MESSAGE_MAP()




// CCryptCubeApp 构造

CCryptCubeApp::CCryptCubeApp()
{

	
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CCryptCubeApp 对象

CCryptCubeApp theApp;


// CCryptCubeApp 初始化
//可实现菜单变灰
void CCryptCubeApp::OnUpdateMenupause(CCmdUI* pCmdUI) 
{
	
	m_bvisible=true;
	pCmdUI->Enable(!m_bvisible);
	
}

BOOL CCryptCubeApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(0);  // 加载标准 INI 文件选项

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	
	//ShowWindow(SW_HIDE);
	//FindWindow(NULL,"密码学盒子 - CryptCube");
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



	// 分析标准外壳命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	
	
	//AfxGetApp()->m_pMainWnd->GetMenu()->EnableMenuItem(ID_HIGH_FILE, MF_GRAYED);//变灰
	m_pMainWnd->CenterWindow();     //窗口打开时，居中显示。
	m_pMainWnd->ShowWindow(SW_SHOW);
	
	m_pMainWnd->UpdateWindow();
	return TRUE;
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框



// 用于运行对话框的应用程序命令


// CCryptCubeApp 自定义加载/保存方法

void CCryptCubeApp::PreLoadState()
{
}

void CCryptCubeApp::LoadCustomState()
{
}

void CCryptCubeApp::SaveCustomState()
{
}

// CCryptCubeApp 消息处理程序


BOOL CCryptCubeApp::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	AfxOleTerm(FALSE);
	CleanState();//清除程序在注册表写入的状态信息
	CleanState(_T("WorkSpace"));

	return CWinAppEx::ExitInstance();
}
