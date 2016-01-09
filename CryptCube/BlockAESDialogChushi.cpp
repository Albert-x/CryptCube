// BlockAESDialogChushi.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BlockAESDialogChushi.h"


// CBlockAESDialogChushi 对话框

IMPLEMENT_DYNAMIC(CBlockAESDialogChushi, CMyDialog)

CBlockAESDialogChushi::CBlockAESDialogChushi(CWnd* pParent /*=NULL*/)
	: CMyDialog(CBlockAESDialogChushi::IDD, pParent)
{

}

CBlockAESDialogChushi::~CBlockAESDialogChushi()
{
}

void CBlockAESDialogChushi::DoDataExchange(CDataExchange* pDX)
{
	CMyDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_INPUT, m_ctrlInput);
	DDX_Control(pDX, IDC_LIST_WI, m_ctrlWi);
	DDX_Control(pDX, IDC_LIST_OUTPUT, m_ctrlOutput);
}


BEGIN_MESSAGE_MAP(CBlockAESDialogChushi, CMyDialog)
END_MESSAGE_MAP()


BOOL  CBlockAESDialogChushi::OnInitDialog()
{
	CMyDialog::OnInitDialog();
	InitListCtrl(m_ctrlInput);
	InitListCtrl(m_ctrlWi);
	InitListCtrl(m_ctrlOutput);
	UpdateListCtrl(m_ctrlInput,m_strInput);
	UpdateListCtrl(m_ctrlWi,m_strWi);
	UpdateListCtrl(m_ctrlOutput,m_strOutput);

	return TRUE;
}

// CBlockAESDialogChushi 消息处理程序

void CBlockAESDialogChushi::InitListCtrl(CListCtrl &ctrlList)
{
	ctrlList.SetExtendedStyle(LVS_EX_REGIONAL);
	LONG lStyle = ctrlList.SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	lStyle |=LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP;
	ctrlList.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)lStyle);


	CImageList   m_l; 
	m_l.Create(1,31,TRUE|ILC_COLOR32,1,0); 
	ctrlList.SetImageList(&m_l,LVSIL_SMALL);
	//ctrlList.get
	ctrlList.InsertColumn(0,_T(""),LVCFMT_CENTER,31,0);
	ctrlList.InsertColumn(1,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(2,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(3,_T(""),LVCFMT_CENTER,32,0);

	ctrlList.InsertItem(0,_T(""));
	ctrlList.InsertItem(1,_T(""));
	ctrlList.InsertItem(2,_T(""));
	ctrlList.InsertItem(3,_T(""));
}


void CBlockAESDialogChushi::UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			ctrlList.SetItemText(i,j,strList[i][j]);
		}
	}

}
