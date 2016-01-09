// BlockAESDialogZuiHou.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BlockAESDialogZuiHou.h"


// CBlockAESDialogZuihou 对话框

IMPLEMENT_DYNAMIC(CBlockAESDialogZuihou, CMyDialog)

CBlockAESDialogZuihou::CBlockAESDialogZuihou(CWnd* pParent /*=NULL*/)
	: CMyDialog(CBlockAESDialogZuihou::IDD, pParent)
{

}

CBlockAESDialogZuihou::~CBlockAESDialogZuihou()
{
}

void CBlockAESDialogZuihou::DoDataExchange(CDataExchange* pDX)
{
	CMyDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_INPUT, m_ctrlInput);
	DDX_Control(pDX, IDC_LIST_ZUIHOU_SUB, m_ctrlSubBytes);
	DDX_Control(pDX, IDC_LIST_ZUIHOU_SHIFT, m_ctrlShiftRows);
	DDX_Control(pDX, IDC_LIST_ZUIHOU_WI, m_ctrlWi);
	DDX_Control(pDX, IDC_LIST_ZUIHOU_ADD, m_ctrlOutput);
}


BEGIN_MESSAGE_MAP(CBlockAESDialogZuihou, CMyDialog)
END_MESSAGE_MAP()



BOOL CBlockAESDialogZuihou::OnInitDialog()
{

	CMyDialog::OnInitDialog();


	InitListCtrl(m_ctrlInput);
	InitListCtrl(m_ctrlSubBytes);
	InitListCtrl(m_ctrlShiftRows);
	InitListCtrl(m_ctrlWi);
	InitListCtrl(m_ctrlOutput);

	UpdateListCtrl(m_ctrlInput,m_strInput);
	UpdateListCtrl(m_ctrlSubBytes,m_strSubBytes);
	UpdateListCtrl(m_ctrlShiftRows,m_strShiftRows);
	UpdateListCtrl(m_ctrlWi,m_strWi);
	UpdateListCtrl(m_ctrlOutput,m_strOutput);

	
	return TRUE;
}

// CBlockAESDialogZuihou 消息处理程序


void CBlockAESDialogZuihou::InitListCtrl(CListCtrl &ctrlList)
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


void CBlockAESDialogZuihou::UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			ctrlList.SetItemText(i,j,strList[i][j]);
		}
	}

}