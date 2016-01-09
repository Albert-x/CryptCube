// TestDes.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "TestDes.h"


// TestDes 对话框

IMPLEMENT_DYNAMIC(TestDes, CDialog)

TestDes::TestDes(CWnd* pParent /*=NULL*/)
	: CDialog(TestDes::IDD, pParent)
{

}

TestDes::~TestDes()
{
}

void TestDes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOCKWAVEFLASH1, m_flashShow);
}


BEGIN_MESSAGE_MAP(TestDes, CDialog)
END_MESSAGE_MAP()


// TestDes 消息处理程序
BOOL TestDes::OnInitDialog()
{
	CDialog::OnInitDialog();
	CDialog::EndDialog(NULL);
	// TODO: 在此添加额外的初始化代码
	//ShowWindow(SW_SHOWMAXIMIZED ); 
	//AfxGetMainWnd()->SendMessage(WM_CLOSE);
	//CRect rect; 
	//GetWindowRect(rect); //先最大显示模式
	//m_flashShow.MoveWindow(rect,true); 
	//SetWindowLong(this->m_hWnd, GWL_STYLE, GetWindowLong(this->m_hWnd, GWL_STYLE) & WS_CAPTION);//去掉标题栏
	//CClientDC dc(this);
	//int horzres = dc.GetDeviceCaps(HORZRES);//获得象素长度
	//int vertres = dc.GetDeviceCaps(VERTRES);//宽度
	//this->MoveWindow(0, 0, horzres, vertres);
	//m_flashShow.SetWindowPos(&CWnd::wndTop, 0, 0, horzres, vertres, SWP_SHOWWINDOW);
	//让flash全屏显示
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}

	CString strFileName = strCurDrt;
	strFileName += "flashSource\\DES-AES-Exercise.swf"; //以上为获的绝对路径
	CString strFlashPlayer =strCurDrt;
	strFlashPlayer += "flashSource\\flashplayer.exe";
	ShellExecute(NULL,"open",strFlashPlayer,strFileName,NULL,SW_SHOW);

	//m_flashShow.LoadMovie(0, strFileName);//加载flash
	//m_FlashPlayer.put_WMode(L"transparent");
	//m_FlashPlayer.put_BackgroundColor(50);
	//m_flashShow.Play(); //播放
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
	
	
	/*CFileDialog dialog (true,"swf",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Flash文件(*.swf)|*.swf",this);
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