// StreamRC4DialogText.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "StreamRC4DialogText.h"


// CStreamRC4DialogText 对话框

IMPLEMENT_DYNAMIC(CStreamRC4DialogText, CMyDialog)

CStreamRC4DialogText::CStreamRC4DialogText(CWnd* pParent /*=NULL*/)
	: CMyDialog(CStreamRC4DialogText::IDD, pParent)
{

}

CStreamRC4DialogText::~CStreamRC4DialogText()
{
}

void CStreamRC4DialogText::DoDataExchange(CDataExchange* pDX)
{
	CMyDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST_CHUSHI2, m_ctrlBox);
}


BEGIN_MESSAGE_MAP(CStreamRC4DialogText, CMyDialog)
END_MESSAGE_MAP()


// CStreamRC4DialogText 消息处理程序

BOOL CStreamRC4DialogText::OnInitDialog()
{

	CMyDialog::OnInitDialog();

	// 设置对话框标题
	SetWindowText(m_strTitle);

	InitListCtrl(m_ctrlBox);

	UpdateListCtrl(m_ctrlBox,m_strBox);

	UpdateData(FALSE);
	return TRUE;
}


void CStreamRC4DialogText::InitListCtrl(CListCtrl &ctrlList)
{
	ctrlList.SetExtendedStyle(LVS_EX_REGIONAL);
	LONG lStyle = ctrlList.SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	lStyle |=LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP;
	ctrlList.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)lStyle);


	CImageList   m_l; 
	m_l.Create(1,15,TRUE|ILC_COLOR32,1,0); 
	ctrlList.SetImageList(&m_l,LVSIL_SMALL);
	ctrlList.InsertColumn(0,_T(""),LVCFMT_CENTER,31,0);
	ctrlList.InsertColumn(1,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(2,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(3,_T(""),LVCFMT_CENTER,32,0);

	ctrlList.InsertColumn(4,_T(""),LVCFMT_CENTER,31,0);
	ctrlList.InsertColumn(5,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(6,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(7,_T(""),LVCFMT_CENTER,32,0);

	ctrlList.InsertColumn(8,_T(""),LVCFMT_CENTER,31,0);
	ctrlList.InsertColumn(9,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(0,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(11,_T(""),LVCFMT_CENTER,32,0);

	ctrlList.InsertColumn(12,_T(""),LVCFMT_CENTER,31,0);
	ctrlList.InsertColumn(13,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(14,_T(""),LVCFMT_CENTER,32,0);
	ctrlList.InsertColumn(15,_T(""),LVCFMT_CENTER,32,0);

	ctrlList.InsertItem(0,_T(""));
	ctrlList.InsertItem(1,_T(""));
	ctrlList.InsertItem(2,_T(""));
	ctrlList.InsertItem(3,_T(""));

	ctrlList.InsertItem(4,_T(""));
	ctrlList.InsertItem(5,_T(""));
	ctrlList.InsertItem(6,_T(""));
	ctrlList.InsertItem(7,_T(""));

	ctrlList.InsertItem(8,_T(""));
	ctrlList.InsertItem(9,_T(""));
	ctrlList.InsertItem(0,_T(""));
	ctrlList.InsertItem(11,_T(""));

	ctrlList.InsertItem(12,_T(""));
	ctrlList.InsertItem(13,_T(""));
	ctrlList.InsertItem(14,_T(""));
	ctrlList.InsertItem(15,_T(""));
}

void CStreamRC4DialogText::UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[16])
{
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
		{
			ctrlList.SetItemText(i,j,strList[i][j]);
		}
	}

}


