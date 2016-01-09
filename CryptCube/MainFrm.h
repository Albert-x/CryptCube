// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// MainFrm.h : CMainFrame 类的接口
//

#pragma once

#include "RibbonBar.h"  

class CMainFrame : public CFrameWndEx
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:

	//CString m_strClassicKaisa;
	//CString m_strClassicDaihuan;
	//CString m_strBlockDES;
	//CString m_strBlockAES;
	//CString m_strStreamRC4;
	//CString m_strPublicKeyRSA;
	//CString m_strPublicKeyDH;
	//CString m_strPublicKeyElGamal;
	//CString m_strPublicKeyECC;
	//CString m_strHashMD5;
	//CString m_strHashSHAForm;
	//CString m_strSignatureDSA;

// 操作
public:
	void SwitchToForm(int nForm);

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnGetMinMaxInfo( MINMAXINFO FAR* lpMMI );
	

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CKofMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	CMFCCaptionBar    m_wndCaptionBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCaptionBar();
	afx_msg void OnUpdateViewCaptionBar(CCmdUI* pCmdUI);
	afx_msg void OnMenuitemOpen();
	DECLARE_MESSAGE_MAP()

	void InitializeRibbon();
	BOOL CreateCaptionBar();
public:
	afx_msg void OnAppAbout();
	afx_msg void OnClassicKaisa();
	afx_msg void OnClassicDaihuan();
	afx_msg void OnBlockDes();
	afx_msg void OnBlockAes();
	afx_msg void OnBlockIdea();
	afx_msg void OnStreamRc4();
	afx_msg void OnPublickeyRsa();
	afx_msg void OnPublickeyElgamal();
	afx_msg void OnHashMd5();
	afx_msg void OnHashSha();
	afx_msg void OnWelcome();
	afx_msg void OnPublickeyDh();
	afx_msg void OnPublickeyEcc();
	afx_msg void OnAppDonate();
	afx_msg void OnAppWebsite();
	afx_msg void OnSignatureDsa();
	afx_msg void OnCodeRandom();
	afx_msg void OnEncryptString();
	afx_msg void OnCodeCalc();
	afx_msg void OnEncryptFile();
	afx_msg void OnCodeHash();
	afx_msg void OnCodeBase64();
	afx_msg void OnCodeString();
	afx_msg void OnCodeUrl();
	afx_msg void OnCodeColor();
	afx_msg void OnCodeQr();
	afx_msg void OnAppHelp();

	afx_msg void OnRsa();
	afx_msg void OnKaisa();
	afx_msg void OnDanbiao();
	afx_msg void OnDes();
	afx_msg void OnAes();
	afx_msg void OnIdea();
	afx_msg void OnElgamal();
	afx_msg void OnMd5();
	afx_msg void OnSha();
	afx_msg void OnRc4();
	afx_msg void OnDsa();
	afx_msg void OnDiffie();
	afx_msg void OnEcc();
	afx_msg void OnFSBH();
	afx_msg void OnHMAC();
	afx_msg void OnCASA();
	afx_msg void OnElg();


	//习题测试
	afx_msg void OnTest_DES();
	afx_msg void OnTest_DIFF();
	afx_msg void OnTest_HMAC();
	afx_msg void OnTest_MD5();
	afx_msg void OnTest_RSA();
	afx_msg void OnTest_SSL();
	//密码术语
	afx_msg void OnTerm();
	
	//参考资料
	afx_msg void OnBook();
	afx_msg void OnExcise();
	afx_msg void OnClass();
	afx_msg void OnTheory();
	//高级
	afx_msg void OnHighKer();
	afx_msg void OnHighPki();
	afx_msg void OnHighEfs();
	afx_msg void OnHighOpen();
	afx_msg void OnHighPgp();
	afx_msg void OnHighSSL();
	afx_msg void OnHighFile();
	//可汗学院
	afx_msg void OnKhan();
	afx_msg void OnStu();
};


