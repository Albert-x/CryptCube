#pragma once


// HashSHA1Key 对话框

class HashSHA1Key : public CDialogEx
{
	DECLARE_DYNAMIC(HashSHA1Key)

public:
	HashSHA1Key(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HashSHA1Key();

// 对话框数据
	enum { IDD = IDD_Hash_SHA1_Key };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_k1;
//	CEdit m_k2;
//	CEdit m_k3;
//	CEdit m_k4;
//	CEdit m_k5;
//	CEdit m_k6;
//	CEdit m_k7;
	CString m_k2;
	CString m_k3;
	CString m_k4;
	CString m_k5;
	CString m_k6;
	CString m_k7;
	CString m_k8;
	CString m_k9;
	CString m_k10;
	CString m_k11;
	CString m_k12;
	CString m_k13;
	CString m_k14;
	CString m_k15;
	CString m_k16;
	CString m_k17;
	CString m_k18;
	CString m_k19;
	CString m_k20;
	CString m_k21;
	CString m_k22;
	CString m_k23;
	CString m_k24;
	CString m_k25;
	CString m_k26;
	CString m_k27;
	CString m_k28;
	CString m_k29;
	CString m_k30;
	CString m_k31;
	CString m_k32;
	CString m_k33;
	CString m_k34;
	CString m_k35;
	CString m_k36;
	CString m_k37;
	CString m_k38;
	CString m_k39;
	CString m_k40;
	CString m_k41;
	CString m_k42;
	CString m_k43;
	CString m_k44;
	CString m_k45;
	CString m_k46;
	CString m_k47;
	CString m_k48;
	CString m_k49;
	CString m_k50;
	CString m_k51;
	CString m_k52;
	CString m_k53;
	CString m_k54;
	CString m_k55;
	CString m_k56;
	CString m_k57;
	CString m_k58;
	CString m_k59;
	CString m_k60;
	CString m_k61;
	CString m_k62;
	CString m_k63;
	CString m_k64;
	CString m_k65;
	CString m_k66;
	CString m_k67;
	CString m_k68;
	CString m_k69;
	CString m_k70;
	CString m_k71;
	CString m_k72;
	CString m_k73;
	CString m_k74;
	CString m_k75;
	CString m_k76;
	CString m_k77;
	CString m_k78;
	CString m_k79;
	CString m_k80;
	virtual BOOL OnInitDialog();
};
