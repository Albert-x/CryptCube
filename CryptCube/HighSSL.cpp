// HighSSL.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HighSSL.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// HighSSL �Ի���

IMPLEMENT_DYNCREATE(HighSSL, CForm)




BEGIN_MESSAGE_MAP(HighSSL, CForm)
	ON_BN_CLICKED(IDC_BUTTON1, &HighSSL::OnBnClickedButton1)
END_MESSAGE_MAP()

HighSSL::HighSSL()
	: CForm(HighSSL::IDD)
{

}

HighSSL::~HighSSL()
{
}

void HighSSL::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}
// HighSSL ��Ϣ�������

#ifdef _DEBUG
void HighSSL::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void HighSSL::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 
void HighSSL::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ShellExecute(NULL,"open","flashSource\\HighSSL.swf",NULL,NULL,SW_SHOWNORMAL);
		TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}	CString strFileName = strCurDrt;
	strFileName += "flashSource\\HighSSL.swf"; //����Ϊ��ľ���·��
	CString strFlashPlayer =strCurDrt;
	strFlashPlayer += "flashSource\\flashplayer.exe";
	ShellExecute(NULL,"open",strFlashPlayer,strFileName,NULL,SW_SHOW);
}
