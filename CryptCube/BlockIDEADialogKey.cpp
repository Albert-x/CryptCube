// BlockIDEADialogKey.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BlockIDEADialogKey.h"


// CBlockIDEADialogKey 对话框

IMPLEMENT_DYNAMIC(CBlockIDEADialogKey, CMyDialog)

CBlockIDEADialogKey::CBlockIDEADialogKey(CWnd* pParent /*=NULL*/)
	: CMyDialog(CBlockIDEADialogKey::IDD, pParent)
{

}

CBlockIDEADialogKey::~CBlockIDEADialogKey()
{
}

void CBlockIDEADialogKey::DoDataExchange(CDataExchange* pDX)
{
	CMyDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CHUSHI2, m_ctrlKey);
}


BEGIN_MESSAGE_MAP(CBlockIDEADialogKey, CMyDialog)
END_MESSAGE_MAP()


// CBlockIDEADialogKey 消息处理程序

BOOL CBlockIDEADialogKey::OnInitDialog()
{

	CMyDialog::OnInitDialog();

	// 初始化列表框，设置样式
	InitListCtrl(m_ctrlKey);

	// 向列表框里写入44个扩展密钥
	
	CString strTemp;



	for(int i=0;i<52;i++)
	{
		strTemp.Format(_T("  %d"),i);
		m_ctrlKey.InsertItem(i,strTemp);
		m_ctrlKey.SetItemText(i,1,m_strKey[i]);

	}

	return TRUE;
}


void CBlockIDEADialogKey::InitListCtrl(CListCtrl &ctrlList)
{
	ctrlList.SetExtendedStyle(LVS_EX_REGIONAL);
	LONG lStyle = ctrlList.SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	lStyle |=LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP;
	ctrlList.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)lStyle);


	CImageList   m_l; 
	m_l.Create(1,26,TRUE|ILC_COLOR32,1,0); 
	ctrlList.SetImageList(&m_l,LVSIL_SMALL);
	//ctrlList.get
	ctrlList.InsertColumn(0,_T("序号"),LVCFMT_CENTER,40,0);
	ctrlList.InsertColumn(1,_T("扩展密钥"),LVCFMT_CENTER,140,0);
}
