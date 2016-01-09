// BlockAESDialogLun.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "BlockAESDialogLun.h"


// CBlockAESDialogLun 对话框

IMPLEMENT_DYNAMIC(CBlockAESDialogLun, CMyDialog)

CBlockAESDialogLun::CBlockAESDialogLun(CWnd* pParent /*=NULL*/)
	: CMyDialog(CBlockAESDialogLun::IDD, pParent)
{

}

CBlockAESDialogLun::~CBlockAESDialogLun()
{
}

void CBlockAESDialogLun::DoDataExchange(CDataExchange* pDX)
{
	CMyDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_INPUT, m_ctrlInput);
	DDX_Control(pDX, IDC_LIST_SUB, m_ctrlSubBytes);
	DDX_Control(pDX, IDC_LIST_SHIFT, m_ctrlShiftRows);
	DDX_Control(pDX, IDC_LIST_MIX, m_ctrlMixColumns);
	DDX_Control(pDX, IDC_LIST_WI, m_ctrlWi);
	DDX_Control(pDX, IDC_LIST_ADD, m_ctrlOutput);
	DDX_Control(pDX, IDC_BUTTON_PREW, m_btnPrew);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_btnNext);
	DDX_Text(pDX, IDC_EDIT_LUN_PAGE, m_strPage);
	DDX_Control(pDX, IDC_SPIN_PAGE, m_spinPage);
}


BEGIN_MESSAGE_MAP(CBlockAESDialogLun, CMyDialog)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CBlockAESDialogLun::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREW, &CBlockAESDialogLun::OnBnClickedButtonPrew)
	ON_EN_CHANGE(IDC_EDIT_LUN_PAGE, &CBlockAESDialogLun::OnEnChangeEditLunPage)
END_MESSAGE_MAP()


BOOL  CBlockAESDialogLun::OnInitDialog()
{

	CMyDialog::OnInitDialog();


	InitListCtrl(m_ctrlInput);
	InitListCtrl(m_ctrlSubBytes);
	InitListCtrl(m_ctrlShiftRows);
	InitListCtrl(m_ctrlMixColumns);
	InitListCtrl(m_ctrlWi);
	InitListCtrl(m_ctrlOutput);
	UpdateListCtrl(m_ctrlInput,m_strInput[0]);
	UpdateListCtrl(m_ctrlSubBytes,m_strSubBytes[0]);
	UpdateListCtrl(m_ctrlShiftRows,m_strShiftRows[0]);
	UpdateListCtrl(m_ctrlMixColumns,m_strMixColumns[0]);
	UpdateListCtrl(m_ctrlWi,m_strWi[0]);
	UpdateListCtrl(m_ctrlOutput,m_strOutput[0]);

	m_spinPage.SetRange(1,9);

	m_strPage=_T("1");
	UpdateData(FALSE);

	// 初始化完成标志位
	m_bInitControl= TRUE;
	

	return TRUE;
}

// CBlockAESDialoglun 消息处理程序

void CBlockAESDialogLun::InitListCtrl(CListCtrl &ctrlList)
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


void CBlockAESDialogLun::UpdateListCtrl(CListCtrl &ctrlList,CString (*strList)[4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			ctrlList.SetItemText(i,j,strList[i][j]);
		}
	}

}

void CBlockAESDialogLun::OnBnClickedButtonNext()
{
	UpdateData(TRUE);
	if(_ttoi(m_strPage)<9) m_strPage.Format(_T("%d"),_ttoi(m_strPage)+1);
		else m_strPage.Format(_T("%d"),1);
	UpdateData(FALSE);
	OnEnChangeEditLunPage();
}

void CBlockAESDialogLun::OnBnClickedButtonPrew()
{
	UpdateData(TRUE);
	if(_ttoi(m_strPage)>1) m_strPage.Format(_T("%d"),_ttoi(m_strPage)-1);
		else m_strPage.Format(_T("%d"),9);

	UpdateData(FALSE);
	OnEnChangeEditLunPage();
}

void CBlockAESDialogLun::OnEnChangeEditLunPage()
{
	if(TRUE == m_bInitControl)
	{
		UpdateData(TRUE);

		int nLun = _ttoi(m_strPage);

		if(nLun > 9)
		{
			nLun = 9;
		}

		if(nLun < 1)
		{
			nLun = 1;
		}

		m_strPage.Format(_T("%d"), nLun);
		UpdateData(FALSE);

		UpdateListCtrl(m_ctrlInput,m_strInput[nLun-1]);
		UpdateListCtrl(m_ctrlSubBytes,m_strSubBytes[nLun-1]);
		UpdateListCtrl(m_ctrlShiftRows,m_strShiftRows[nLun-1]);
		UpdateListCtrl(m_ctrlMixColumns,m_strMixColumns[nLun-1]);
		UpdateListCtrl(m_ctrlWi,m_strWi[nLun-1]);
		UpdateListCtrl(m_ctrlOutput,m_strOutput[nLun-1]);

		CString strTemp;

		strTemp.Format(_T("W%d~W%d"),nLun*4,nLun*4+3);

		GetDlgItem(IDC_STATIC_WI)->SetWindowText(strTemp);


	}
}
