// HighPki.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HighPki.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// HighPki �Ի���

IMPLEMENT_DYNCREATE(HighPki, CForm)

HighPki::HighPki()
	:CForm(HighPki::IDD)
{

}

HighPki::~HighPki()
{
}

void HighPki::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HighPki, CForm)
	ON_BN_CLICKED(IDC_BUTTON1, &HighPki::OnBnClickedButton1)
END_MESSAGE_MAP()


// HighPki ��Ϣ�������
#ifdef _DEBUG
void HighPki::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void HighPki::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif 

void HighPki::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ShellExecute(NULL,"open","flashSource\\PKI.swf",NULL,NULL,SW_SHOWNORMAL);
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}	CString strFileName = strCurDrt;
	strFileName += "flashSource\\PKI.swf"; //����Ϊ��ľ���·��
	CString strFlashPlayer =strCurDrt;
	strFlashPlayer += "flashSource\\flashplayer.exe";
	ShellExecute(NULL,"open",strFlashPlayer,strFileName,NULL,SW_SHOW);
}
