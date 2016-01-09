// StreamRC4DialogList.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "StreamRC4DialogList.h"


// CStreamRC4DialogList 对话框

IMPLEMENT_DYNAMIC(CStreamRC4DialogList, CMyDialog)

CStreamRC4DialogList::CStreamRC4DialogList(CWnd* pParent /*=NULL*/)
	: CMyDialog(CStreamRC4DialogList::IDD, pParent)
{
	nLen=0;
}

CStreamRC4DialogList::~CStreamRC4DialogList()
{
}

void CStreamRC4DialogList::DoDataExchange(CDataExchange* pDX)
{
	CMyDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CHUSHI2, m_ctrlKey);
}


BEGIN_MESSAGE_MAP(CStreamRC4DialogList, CMyDialog)
END_MESSAGE_MAP()


// CStreamRC4DialogList 消息处理程序

BOOL CStreamRC4DialogList::OnInitDialog()
{

	CMyDialog::OnInitDialog();

	// 设置对话框标题
	SetWindowText(m_strTitle);

	// 初始化列表框，设置样式
	InitListCtrl(m_ctrlKey);

	// 向列表框里写入44个扩展密钥
	
	CString strTemp;

	for(int i=0;i<nLen;i++)
	{
		strTemp.Format(_T("  %02X"),m_pRC4->m_Plain[i]);
		m_ctrlKey.InsertItem(i,strTemp);
		strTemp.Format(_T("  %02X"),m_pRC4->m_Deidai[i]);
		m_ctrlKey.SetItemText(i,1,strTemp);

	}

	return TRUE;
}


void CStreamRC4DialogList::InitListCtrl(CListCtrl &ctrlList)
{
	ctrlList.SetExtendedStyle(LVS_EX_REGIONAL);
	LONG lStyle = ctrlList.SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	lStyle |=LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP;
	ctrlList.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)lStyle);


	CImageList   m_l; 
	m_l.Create(1,15,TRUE|ILC_COLOR32,1,0); 
	ctrlList.SetImageList(&m_l,LVSIL_SMALL);
	//ctrlList.get
	ctrlList.InsertColumn(0,_T("明文"),LVCFMT_CENTER,80,0);
	ctrlList.InsertColumn(1,_T("迭代值"),LVCFMT_CENTER,80,0);
}


