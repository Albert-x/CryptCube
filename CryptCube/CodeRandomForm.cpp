// CodeRandomForm.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "CodeRandomForm.h"
#include "CStringConvert.h"


// CCodeRandomForm

IMPLEMENT_DYNCREATE(CCodeRandomForm, CForm)

CCodeRandomForm::CCodeRandomForm()
	: CForm(CCodeRandomForm::IDD)
	, m_strPassLength(_T(""))
	, m_strPassAmount(_T(""))
	, m_bCheckUppercase(TRUE)
	, m_bCheckLowercase(TRUE)
	, m_bCheckNumber(FALSE)
	, m_bCheckCharacter(FALSE)
	, m_bCheckHex(FALSE)
	, m_bCheckBin(FALSE)
	, m_strPassCustom(_T(""))
	, m_bCheckCustom(FALSE)
	, m_strPass(_T(""))
{
}

CCodeRandomForm::~CCodeRandomForm()
{
}

void CCodeRandomForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_PASS_LEN, m_strPassLength);
	DDX_CBString(pDX, IDC_COMBO_PASS_AMOUNT, m_strPassAmount);
	DDX_Control(pDX, IDC_COMBO_PASS_LEN, m_pComboPassLength);
	DDX_Check(pDX, IDC_CHECK_UPPERCASE, m_bCheckUppercase);
	DDX_Check(pDX, IDC_CHECK_LOWERCASE, m_bCheckLowercase);
	DDX_Check(pDX, IDC_CHECK_NUMBER, m_bCheckNumber);
	DDX_Check(pDX, IDC_CHECK_CHARACTER, m_bCheckCharacter);
	DDX_Check(pDX, IDC_CHECK_HEX, m_bCheckHex);
	DDX_Check(pDX, IDC_CHECK_BIN, m_bCheckBin);
	DDX_Control(pDX, IDC_CHECK_UPPERCASE, m_btnCheckUppercase);
	DDX_Control(pDX, IDC_CHECK_LOWERCASE, m_btnCheckLowercase);
	DDX_Control(pDX, IDC_CHECK_NUMBER, m_btnCheckNumber);
	DDX_Control(pDX, IDC_CHECK_CHARACTER, m_btnCheckCharacter);
	DDX_Control(pDX, IDC_CHECK_HEX, m_btnCheckHex);
	DDX_Control(pDX, IDC_CHECK_BIN, m_btnCheckBin);
	DDX_Control(pDX, IDC_COMBO_PASS_AMOUNT, m_pComboPassAmount);
	DDX_Control(pDX, IDC_EDIT_PASSCUSTOM, m_editPassCustom);
	DDX_Text(pDX, IDC_EDIT_PASSCUSTOM, m_strPassCustom);
	DDV_MaxChars(pDX, m_strPassCustom, 100);
	DDX_Control(pDX, IDC_CHECK_PASSCUSTOM, m_btnCheckCustom);
	DDX_Check(pDX, IDC_CHECK_PASSCUSTOM, m_bCheckCustom);
	DDX_Text(pDX, IDC_EDIT_PASS, m_strPass);
	DDX_Control(pDX, IDC_EDIT_PASS, m_editPass);
	DDX_Control(pDX, ID_PASS_GENERATE, m_btnPassGenerate);
}

BEGIN_MESSAGE_MAP(CCodeRandomForm, CForm)
	ON_BN_CLICKED(ID_PASS_GENERATE, &CCodeRandomForm::OnBnClickedPassGenerate)
	ON_BN_CLICKED(IDC_CHECK_HEX, &CCodeRandomForm::OnBnClickedCheckHex)
	ON_BN_CLICKED(IDC_CHECK_BIN, &CCodeRandomForm::OnBnClickedCheckBin)
	ON_CBN_EDITCHANGE(IDC_COMBO_PASS_LEN, &CCodeRandomForm::OnCbnEditchangeComboPassLength)
	ON_CBN_EDITCHANGE(IDC_COMBO_PASS_AMOUNT, &CCodeRandomForm::OnCbnEditchangeComboPassAmount)
	ON_BN_CLICKED(IDC_CHECK_PASSCUSTOM, &CCodeRandomForm::OnBnClickedCheckPasscustom)
END_MESSAGE_MAP()


// CCodeRandomForm 诊断

#ifdef _DEBUG
void CCodeRandomForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeRandomForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeRandomForm 消息处理程序

//初始化Form
void CCodeRandomForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();

	//用子线程的方法初始化Combobox内容
	CWinThread *pPassLengthThread= AfxBeginThread((AFX_THREADPROC)InitComboboxPassLength,this);
	CWinThread *pPassAmountThread= AfxBeginThread((AFX_THREADPROC)InitComboboxPassAmount,this);
}


// 解决多行输入框的的CTRL+A快捷键无法响应的问题
BOOL CCodeRandomForm::PreTranslateMessage(MSG* pMsg)
{

	if(WM_KEYDOWN == pMsg->message && _T('A') == pMsg->wParam && HIBYTE(GetKeyState(VK_CONTROL)))
	{
		// 设置 m_editPass的CTRL+A
		if(GetFocus()->GetSafeHwnd() == m_editPass.m_hWnd)
		{
			m_editPass.SetSel(0, -1);
			return CFormView::PreTranslateMessage(pMsg);
		}
	}
	return CForm::PreTranslateMessage(pMsg);
}


//初始化密码长度的线程，为密码长度下拉框设置初始值
UINT CCodeRandomForm::InitComboboxPassLength(LPVOID param)
{
	CCodeRandomForm * pThisForm = (CCodeRandomForm *) param; 
	CString strTemp;
	int nCombobox=1;

	pThisForm->m_pComboPassLength.ResetContent();

	for(int i=0;i<=12;i++)
	{
		strTemp.Format(_T("%d"),nCombobox*=2);
		pThisForm->m_pComboPassLength.InsertString(i,strTemp);
	}
	pThisForm->m_pComboPassLength.SetCurSel(3);
	return 0; 
}

//初始化密码数量下拉框的线程
UINT CCodeRandomForm::InitComboboxPassAmount(LPVOID param)
{
	//由于子线程是静态成员函数，无法直接访问成员变量。
	//所以创建一个（CxxxxxForm * ）pThisForm的指针指向此Form。
	//使用pThisForm->的形式获取成员变量和非静态方法。
	CCodeRandomForm * pThisForm = (CCodeRandomForm *) param; 
	CString strTemp;

	pThisForm->m_pComboPassAmount.ResetContent();

	for(int i=1;i<=10;i++)
	{
		strTemp.Format(_T("%d"),i);
		pThisForm->m_pComboPassAmount.InsertString(i-1,strTemp);
	}
	pThisForm->m_pComboPassAmount.SetCurSel(0);
	return 0; 
}


//让“密码长度输入框”只能输入数字
void CCodeRandomForm::OnCbnEditchangeComboPassLength()
{
	UpdateData();
	for (int i = 0; i < m_strPassLength.GetLength(); i++)//若输入的字符中有非数字，则直接删除
	{
		if (m_strPassLength.GetAt(i) < _T('0') || m_strPassLength.GetAt(i) > _T('9'))
		{
			m_strPassLength.Delete(i);
			m_pComboPassLength.SetWindowText(m_strPassLength);
			m_pComboPassLength.SetEditSel(i,i);

		}
	}
	if(_T('0') == m_strPassLength)//若输入的第一个字符为0，自动改成1
	{
		m_strPassLength=_T('1');
		m_pComboPassLength.SetWindowText(m_strPassLength);
	}
}

// 让“密码数量输入框”只能输入数字
void CCodeRandomForm::OnCbnEditchangeComboPassAmount()
{
	UpdateData();
	for (int i = 0; i < m_strPassAmount.GetLength(); i++)
	{
		if (m_strPassAmount.GetAt(i) < _T('0') || m_strPassAmount.GetAt(i) > _T('9'))
		{
			m_strPassAmount.Delete(i);
			m_pComboPassAmount.SetWindowText(m_strPassAmount);
			m_pComboPassAmount.SetEditSel(i,i);
		}
	}
	if(_T('0') == m_strPassAmount)//若输入的第一个字符为0，自动改成1
	{
		m_strPassAmount=_T('1');
		m_pComboPassAmount.SetWindowText(m_strPassAmount);
	}
}

// 选中“十六进制”复选框后，禁用其它复选框
void CCodeRandomForm::OnBnClickedCheckHex()
{
	UpdateData();//从控件读取到变量
	if(TRUE == m_bCheckHex)
	{
		m_btnCheckUppercase.EnableWindow(FALSE);
		m_btnCheckLowercase.EnableWindow(FALSE);
		m_btnCheckNumber.EnableWindow(FALSE);
		m_btnCheckCharacter.EnableWindow(FALSE);
		m_btnCheckBin.EnableWindow(FALSE);
		m_btnCheckCustom.EnableWindow(FALSE);
		m_editPassCustom.EnableWindow(FALSE);
	}
	else
	{
		m_btnCheckUppercase.EnableWindow(TRUE);
		m_btnCheckLowercase.EnableWindow(TRUE);
		m_btnCheckNumber.EnableWindow(TRUE);
		m_btnCheckCharacter.EnableWindow(TRUE);
		m_btnCheckBin.EnableWindow(TRUE);
		m_btnCheckCustom.EnableWindow(TRUE);
		if(TRUE == m_bCheckCustom)
		{
			m_editPassCustom.EnableWindow(TRUE);
		}
		else
		{
			m_editPassCustom.EnableWindow(FALSE);
		}
	}
}


//选中“二进制”复选框后，禁用其它复选框
void CCodeRandomForm::OnBnClickedCheckBin()
{
	UpdateData();//从控件读取到变量
	if(TRUE == m_bCheckBin)
	{
		m_btnCheckUppercase.EnableWindow(FALSE);
		m_btnCheckLowercase.EnableWindow(FALSE);
		m_btnCheckNumber.EnableWindow(FALSE);
		m_btnCheckCharacter.EnableWindow(FALSE);
		m_btnCheckHex.EnableWindow(FALSE);
		m_btnCheckCustom.EnableWindow(FALSE);
		m_editPassCustom.EnableWindow(FALSE);
	}
	else
	{
		m_btnCheckUppercase.EnableWindow(TRUE);
		m_btnCheckLowercase.EnableWindow(TRUE);
		m_btnCheckNumber.EnableWindow(TRUE);
		m_btnCheckCharacter.EnableWindow(TRUE);
		m_btnCheckHex.EnableWindow(TRUE);
		m_btnCheckCustom.EnableWindow(TRUE);
		if(TRUE == m_bCheckCustom)
		{
			m_editPassCustom.EnableWindow(TRUE);
		}
		else
		{
			m_editPassCustom.EnableWindow(FALSE);
		}
	}
}



// 选中“自定义字符”复选框后，启用“自定义字符”输入框
void CCodeRandomForm::OnBnClickedCheckPasscustom()
{
	UpdateData();// 读取控件上的内容到变量
	if(TRUE == m_bCheckCustom)
	{
		m_editPassCustom.EnableWindow(TRUE);
	}
	else
	{
		m_editPassCustom.EnableWindow(FALSE);
	}
}



// 按下“生成按钮”执行密码生成的操作
void CCodeRandomForm::OnBnClickedPassGenerate()
{

	
	UpdateData();// 读取控件上的内容到变量
	
	// 添加密码长度、密码数量的历史记录到下拉框
	if(CB_ERR == m_pComboPassLength.FindStringExact(-1,m_strPassLength)) 
		m_pComboPassLength.InsertString(0,m_strPassLength);
	if(CB_ERR == m_pComboPassAmount.FindStringExact(-1,m_strPassAmount))
		m_pComboPassAmount.InsertString(0,m_strPassAmount);

	//执行生成随机密码的线程
	CWinThread *pPassGenerateThread= AfxBeginThread((AFX_THREADPROC)PassGenerate,this);

}


//执行随机密码生成线程
UINT CCodeRandomForm::PassGenerate(LPVOID param)
{
	//由于子线程是静态成员函数，无法直接访问成员变量。
	//所以创建一个（CxxxxxForm * ）pThisForm的指针指向此Form。
	//使用pThisForm->的形式获取成员变量和非静态方法。
	CCodeRandomForm * pThisForm = (CCodeRandomForm *) param;

	//禁用“生成”按钮
	pThisForm->m_btnPassGenerate.EnableWindow(FALSE);


	// 初始化随机种子
	srand((unsigned)time(NULL)); 

	// 清空密码
	pThisForm->m_strPass=_T("");

	// 按数量循环生成密码并用换行符连接
	for(int i=0;i<_ttoi(pThisForm->m_strPassAmount);i++)
	{
		pThisForm->m_strPass += RandomCode(
			_ttoi(pThisForm->m_strPassLength),pThisForm->m_bCheckHex, pThisForm->m_bCheckBin,
			pThisForm->m_bCheckCharacter, pThisForm->m_bCheckUppercase,
			pThisForm->m_bCheckLowercase, pThisForm->m_bCheckNumber,
			pThisForm->m_bCheckCustom, pThisForm->m_strPassCustom);

		pThisForm->m_strPass += _T("\r\n");
	}

	// 清除最后一个换行符
	pThisForm->m_strPass.TrimRight(_T("\r\n"));

	// 在控件上显示密码
	pThisForm->m_editPass.SetWindowText(pThisForm->m_strPass);

	// 滚动文本框到最下方
	pThisForm->m_editPass.LineScroll(pThisForm->m_editPass.GetLineCount());

	//Sleep(100);
	// 恢复“生成”按钮
	pThisForm->m_btnPassGenerate.EnableWindow(TRUE);

	return 0;
}


// 随机获取一个字符串
CString CCodeRandomForm::RandomCode(int nlength,BOOL bHex ,
		BOOL bBin ,BOOL bCharacter ,BOOL bUppercase ,BOOL bLowercase ,
		BOOL bNumber ,BOOL bCustom ,CString strCustom)
{
	CString strCode;

	// 按照需要的长度循环获得字符序列
	for(int i = 0;i<nlength;i++)
	{
		strCode += GetChar(bHex,bBin,bCharacter,bUppercase,bLowercase,bNumber,bCustom,strCustom);
	}
	return strCode;
}


// 根据参数要求随机获得一个字符
CString CCodeRandomForm::GetChar(BOOL bHex ,
		BOOL bBin ,BOOL bCharacter ,BOOL bUppercase ,BOOL bLowercase ,
		BOOL bNumber ,BOOL bCustom ,CString strCustom)
{
	CString strChar= _T(""); // 一个空字符串用来记录备选的字符
	CString strArrayCharacter = _T("`~!@#$%^&*()_+-={}|[]\\:;\"'<>?,./"); //备选的32个键盘符号
	CString strArrayUppercase = _T("ABCDEFGHIJKLMNOPQRSTUVWXYZ"); // 备选的26个大写字母
	CString strArrayLowercase = _T("abcdefghijklmnopqrstuvwxyz"); // 备选的26个小写字母
	CString strArrayNumber = _T("0123456789"); // 备选的10个数字符号
	CString strArrayHex = _T("0123456789ABCDEF"); // 备选的16个十六进制符号
	CString strArrayBin = _T("01"); // 备选的2个二进制符号

	// 根据参数设置备选字符添加到字符库strChar
	if(bCharacter) strChar+=strArrayCharacter;
	if(bUppercase) strChar+=strArrayUppercase;
	if(bLowercase) strChar+=strArrayLowercase;
	if(bNumber) strChar+=strArrayNumber;
	if(bCustom) strChar+=strCustom;
	if(bHex) strChar=strArrayHex;
	if(bBin) strChar=strArrayBin;
	if(_T("") == strChar) return _T("");// 若备选字符库strChar为空，返回空字符。

	CStringW strCharW = CStrT2CStrW(strChar);//用UNICOD方式处理字串，以保证ANSI编译方式后无法自定义中文字符
	return CStrW2CStrT(strCharW.Mid( rand() % strCharW.GetLength() ,1));// 否则返回一个随机字符。
}


