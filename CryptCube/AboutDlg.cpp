// AboutDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "AboutDlg.h"


// CAboutDlg 对话框

IMPLEMENT_DYNAMIC(CAboutDlg, CMyDialog)

CAboutDlg::CAboutDlg(CWnd* pParent /*=NULL*/)
	: CMyDialog(CAboutDlg::IDD, pParent)
{

}

CAboutDlg::~CAboutDlg()
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CMyDialog)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_HOMEPAGE, &CAboutDlg::OnNMClickSyslinkHomepage)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_DONATE, &CAboutDlg::OnNMClickSyslinkDonate)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_MAIL, &CAboutDlg::OnNMClickSyslinkMail)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_QQ, &CAboutDlg::OnNMClickSyslinkQq)
END_MESSAGE_MAP()

BOOL CAboutDlg::OnInitDialog() 
{
	CMyDialog::OnInitDialog();

	OSVERSIONINFOEX os; 

	os.dwOSVersionInfoSize=sizeof(OSVERSIONINFOEX);   
	GetVersionEx((OSVERSIONINFO *)&os);
	if(os.dwPlatformId==VER_PLATFORM_WIN32_NT && os.dwMajorVersion >=5)
	{

	CFont *pFont = new CFont;
	pFont->CreatePointFont(90, _T("微软雅黑"));
	SetFont(pFont);
	CWnd *pWnd   = GetWindow(GW_CHILD);
	while(pWnd   != NULL)
	{
		pWnd-> SetFont(pFont);
		pWnd = pWnd-> GetWindow(GW_HWNDNEXT);
	}
	}

	return TRUE;
}


// CAboutDlg 消息处理程序

void CAboutDlg::OnNMClickSyslinkHomepage(NMHDR *pNMHDR, LRESULT *pResult)
{
	OnAppWebsite();
	*pResult = 0;
}

void CAboutDlg::OnNMClickSyslinkDonate(NMHDR *pNMHDR, LRESULT *pResult)
{
	OnAppDonate();
	*pResult = 0;
}

void CAboutDlg::OnNMClickSyslinkMail(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	//PNMLINK pNMLink = (PNMLINK)pNMHDR;
	//CString strMailUrl;
	//strMailUrl.Format(_T(""),);
	ShellExecute(NULL, _T("open"), _T("mailto:i@cryptcube.cn?subject=《密码学盒子》软件交流") ,NULL, NULL, SW_SHOWNORMAL); 
	*pResult = 0;
}

void CAboutDlg::OnNMClickSyslinkQq(NMHDR *pNMHDR, LRESULT *pResult)
{
	ShellExecute(NULL, _T("open"), _T("tencent://message/?uin=20823006&Site=&Menu=yes") ,NULL, NULL, SW_SHOWNORMAL); 
	*pResult = 0;
}


void CAboutDlg::OnAppDonate()
{
	ShellExecute(NULL, _T("open"), _T("http://www.guet.edu.cn"),NULL, NULL, SW_SHOWNORMAL); 
}

void CAboutDlg::OnAppWebsite()
{
	ShellExecute(NULL, _T("open"), _T("http://www.guet.edu.cn/"),NULL, NULL, SW_SHOWNORMAL); 
}
