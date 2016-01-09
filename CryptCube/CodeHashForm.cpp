// CodeHashForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeHashForm.h"
#include "CStringConvert.h"
#include <Wincrypt.h>
//设置各个算法在列表框的位置
#define HASH_MD5		0
#define HASH_MD2		1
#define HASH_SHA1		2
#define HASH_SHA		3
//#define HASH_SHA512		4

// CCodeHashForm

IMPLEMENT_DYNCREATE(CCodeHashForm, CForm)

CCodeHashForm::CCodeHashForm()
	: CForm(CCodeHashForm::IDD)
	, m_strFilePath(_T(""))
{

}

CCodeHashForm::~CCodeHashForm()
{
}

void CCodeHashForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HASH, m_ctrlListHash);
	DDX_Text(pDX, IDC_EDIT_FILE_PATH, m_strFilePath);
	DDV_MaxChars(pDX, m_strFilePath, 255);
}

BEGIN_MESSAGE_MAP(CCodeHashForm, CForm)
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CCodeHashForm::OnBnClickedButtonOpen)
END_MESSAGE_MAP()


// CCodeHashForm 诊断

#ifdef _DEBUG
void CCodeHashForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeHashForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeHashForm 消息处理程序

void CCodeHashForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();
	InitListCtrl();
}


void CCodeHashForm::InitListCtrl()
{
	m_ctrlListHash.SetExtendedStyle(LVS_EX_CHECKBOXES);
	LONG lStyle = m_ctrlListHash.SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	lStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP;
	m_ctrlListHash.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)lStyle);

	
	m_ctrlListHash.InsertColumn(0,_T("算法类型"),LVCFMT_CENTER,80,-1);
	m_ctrlListHash.InsertColumn(1,_T("哈希值"),LVCFMT_CENTER,500,-1);


    m_ctrlListHash.InsertItem(HASH_MD5, _T("MD5"));
    m_ctrlListHash.SetCheck(HASH_MD5, TRUE);
	m_ctrlListHash.SetItemText(HASH_MD5,1,_T(""));

    m_ctrlListHash.InsertItem(HASH_MD2, _T("MD2"));
    m_ctrlListHash.SetCheck(HASH_MD2, TRUE);
	m_ctrlListHash.SetItemText(HASH_MD2,1,_T(""));
 
    m_ctrlListHash.InsertItem(HASH_SHA1, _T("SHA"));
    m_ctrlListHash.SetCheck(HASH_SHA1, TRUE);
	m_ctrlListHash.SetItemText(HASH_SHA1,1,_T(""));

	m_ctrlListHash.InsertItem(HASH_SHA, _T("SHA1"));
    m_ctrlListHash.SetCheck(HASH_SHA, TRUE);
	m_ctrlListHash.SetItemText(HASH_SHA,1,_T(""));

   


}

void CCodeHashForm::OnDropFiles(HDROP hDropInfo) 
{
	UpdateData();
    TCHAR szFileName[255];
    ZeroMemory(szFileName,255);
    DragQueryFile(hDropInfo,0,szFileName,254);
    if(lstrlen(szFileName)!=0 && PathIsDirectory(szFileName) == FALSE)
    {
        m_strFilePath=szFileName;
		UpdateData(FALSE);
		DoHash();
		
    }
    DragFinish(hDropInfo); 
	
	
	
}
void CCodeHashForm::OnBnClickedButtonOpen()
{
	CFileDialog* pFileDialog = new CFileDialog(TRUE,NULL,NULL,OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_READONLY,
       _T("所有文件(*.*)|*.*||"),this);

	pFileDialog->m_ofn.lpstrTitle = _T("打开要计算哈希值的文件");

	//“文件保存”对话框中显示
	if (pFileDialog->DoModal() == IDOK)
	{
		m_strFilePath = pFileDialog->GetPathName();
		UpdateData(FALSE);
		DoHash();
	}

	delete 	pFileDialog;
}

void CCodeHashForm::DoHash()
{
	UpdateData();
	if(PathFileExists(m_strFilePath) && !PathIsDirectory(m_strFilePath))
	{

		BOOL bCheckMD5 = m_ctrlListHash.GetCheck(HASH_MD5);
		BOOL bCheckMD2 = m_ctrlListHash.GetCheck(HASH_MD2);
		BOOL bCheckSHA1 = m_ctrlListHash.GetCheck(HASH_SHA1);
		BOOL bCheckSHA = m_ctrlListHash.GetCheck(HASH_SHA);
		//BOOL bCheckSHA512 = m_ctrlListHash.GetCheck(HASH_SHA512);

		if(bCheckMD5) 
			CWinThread *pMD5GenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashMD5,this);
		if(bCheckMD2)
			CWinThread *pMD2GenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashMD2,this);
		if(bCheckSHA1) 
			CWinThread *pSHA1GenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashSHA1,this);
		if(bCheckSHA) 
			CWinThread *pSHAGenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashSHA,this);
		//if(bCheckSHA512) 
			//CWinThread *pSHA512GenerateThread= AfxBeginThread((AFX_THREADPROC)DoHashSHA512,this);

	}

}

UINT CCodeHashForm::DoHashMD5(LPVOID param)
{
	//得到Form指针。
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;

	//pThisForm->m_ctrlListHash.SetItemText(HASH_MD5,1,GetFileHashMD5(pThisForm->m_strFilePath));
	TCHAR szHash[512] = {0};
	GetHash(pThisForm->m_strFilePath, CALG_MD5,szHash);
	pThisForm->m_ctrlListHash.SetItemText(HASH_MD5,1,szHash);

	return 0;
}

UINT CCodeHashForm::DoHashMD2(LPVOID param)
{
	//得到Form指针。
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;
	//pThisForm->m_ctrlListHash.SetItemText(HASH_CRC32,1,GetFileHashCRC32(pThisForm->m_strFilePath));
	TCHAR szHash[512] = {0};
	GetHash(pThisForm->m_strFilePath, CALG_MD2,szHash);
	pThisForm->m_ctrlListHash.SetItemText(HASH_MD2,1,szHash);
	return 0;
}


UINT CCodeHashForm::DoHashSHA1(LPVOID param)
{
	//得到Form指针。
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;
	//pThisForm->m_ctrlListHash.SetItemText(HASH_SHA1,1,GetFileHashSHA1(pThisForm->m_strFilePath));
	TCHAR szHash[512] = {0};
	GetHash(pThisForm->m_strFilePath, CALG_SHA1,szHash);
	pThisForm->m_ctrlListHash.SetItemText(HASH_SHA1,1,szHash);


	return 0;
}


UINT CCodeHashForm::DoHashSHA(LPVOID param)
{
	//得到Form指针。
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;
	//pThisForm->m_ctrlListHash.SetItemText(HASH_SHA256,1,GetFileHashSHA256(pThisForm->m_strFilePath));
	TCHAR szHash[512] = {0};
	GetHash(pThisForm->m_strFilePath, CALG_SHA,szHash);
	pThisForm->m_ctrlListHash.SetItemText(HASH_SHA,1,szHash);
	
	return 0;
}


/*UINT CCodeHashForm::DoHashSHA512(LPVOID param)
{
	//得到Form指针。
	CCodeHashForm * pThisForm = (CCodeHashForm *) param;
	//pThisForm->m_strFilePath;
	//pThisForm->m_ctrlListHash.SetItemText(HASH_SHA512,1,GetFileHashSHA512(pThisForm->m_strFilePath));
	TCHAR szHash[512] = {0};
	GetHash(pThisForm->m_strFilePath, CALG_SHA_512,szHash);
	pThisForm->m_ctrlListHash.SetItemText(HASH_SHA512,1,szHash);
	return 0;
}*/