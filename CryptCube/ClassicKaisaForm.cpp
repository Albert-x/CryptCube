// ClassicKaisaForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CryptCube.h"
#include "ClassicKaisaForm.h"
#include "CStringConvert.h"

#include "ClassicKaisa.h"

// CClassicKaisaForm

IMPLEMENT_DYNCREATE(CClassicKaisaForm, CForm)

CClassicKaisaForm::CClassicKaisaForm()
	: CForm(CClassicKaisaForm::IDD)
	, m_strKeyLength(_T("0"))
	, m_strPlainText(_T(""))
	, m_strCipherText(_T(""))
{

}

CClassicKaisaForm::~CClassicKaisaForm()
{
}

void CClassicKaisaForm::DoDataExchange(CDataExchange* pDX)
{
	CForm::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_KAISA_KEYLEN, m_strKeyLength);
	DDV_MaxChars(pDX, m_strKeyLength, 2);
	DDX_Text(pDX, IDC_EDIT_KAISA_PLAIN, m_strPlainText);
	DDX_Text(pDX, IDC_EDIT_KAISA_CIPHER, m_strCipherText);
	//DDX_Control(pDX, IDC_EDIT_KAISA_PLAIN, m_pEditPlainText);
	//DDX_Control(pDX, IDC_EDIT_KAISA_CIPHER, m_pEditCipherText);
	//DDX_Control(pDX, IDC_EDIT_KAISA_KEYLEN, m_pEditKeyLength);
	DDX_Control(pDX, IDC_SPIN_KEYLEN, m_spinKeyLength);
	DDX_Text(pDX, IDC_EDIT5, m_strA);
	DDX_Text(pDX, IDC_EDIT18, m_strB);
	DDX_Text(pDX, IDC_EDIT19, m_strC);
	DDX_Text(pDX, IDC_EDIT20, m_strD);
	DDX_Text(pDX, IDC_EDIT21, m_strE);
	DDX_Text(pDX, IDC_EDIT22, m_strF);
	DDX_Text(pDX, IDC_EDIT23, m_strG);
	DDX_Text(pDX, IDC_EDIT24, m_strH);
	DDX_Text(pDX, IDC_EDIT25, m_strI);
	DDX_Text(pDX, IDC_EDIT26, m_strJ);
	DDX_Text(pDX, IDC_EDIT27, m_strK);
	DDX_Text(pDX, IDC_EDIT28, m_strL);
	DDX_Text(pDX, IDC_EDIT29, m_strM);
	DDX_Text(pDX, IDC_EDIT30, m_strN);
	DDX_Text(pDX, IDC_EDIT31, m_strO);
	DDX_Text(pDX, IDC_EDIT32, m_strP);
	DDX_Text(pDX, IDC_EDIT33, m_strQ);
	DDX_Text(pDX, IDC_EDIT34, m_strR);
	DDX_Text(pDX, IDC_EDIT35, m_strS);
	DDX_Text(pDX, IDC_EDIT36, m_strT);
	DDX_Text(pDX, IDC_EDIT37, m_strU);
	DDX_Text(pDX, IDC_EDIT38, m_strV);
	DDX_Text(pDX, IDC_EDIT39, m_strW);
	DDX_Text(pDX, IDC_EDIT40, m_strX);
	DDX_Text(pDX, IDC_EDIT41, m_strY);
	DDX_Text(pDX, IDC_EDIT42, m_strZ);

	DDX_Text(pDX, IDC_EDIT43,  m_stra);
	DDX_Text(pDX, IDC_EDIT44,  m_strb);
	DDX_Text(pDX, IDC_EDIT45,  m_strc);
	DDX_Text(pDX, IDC_EDIT46,  m_strd);
	DDX_Text(pDX, IDC_EDIT47,  m_stre);
	DDX_Text(pDX, IDC_EDIT48,  m_strf);
	DDX_Text(pDX, IDC_EDIT49,  m_strg);
	DDX_Text(pDX, IDC_EDIT50,  m_strh);
	DDX_Text(pDX, IDC_EDIT51,  m_stri);
	DDX_Text(pDX, IDC_EDIT52,  m_strj);
	DDX_Text(pDX, IDC_EDIT53,  m_strk);
	DDX_Text(pDX, IDC_EDIT54,  m_strl);
	DDX_Text(pDX, IDC_EDIT55,  m_strm);
	DDX_Text(pDX, IDC_EDIT56,  m_strn);
	DDX_Text(pDX, IDC_EDIT57,  m_stro);
	DDX_Text(pDX, IDC_EDIT58,  m_strp);
	DDX_Text(pDX, IDC_EDIT59,  m_strq);
	DDX_Text(pDX, IDC_EDIT60,  m_strr);
	DDX_Text(pDX, IDC_EDIT61,  m_strs);
	DDX_Text(pDX, IDC_EDIT62,  m_strt);
	DDX_Text(pDX, IDC_EDIT63,  m_stru);
	DDX_Text(pDX, IDC_EDIT64,  m_strv);
	DDX_Text(pDX, IDC_EDIT65,  m_strw);
	DDX_Text(pDX, IDC_EDIT66,  m_strx);
	DDX_Text(pDX, IDC_EDIT67,  m_stry);
	DDX_Text(pDX, IDC_EDIT68,  m_strz);


}

BEGIN_MESSAGE_MAP(CClassicKaisaForm, CForm)
	
	ON_EN_CHANGE(IDC_EDIT_KAISA_PLAIN, &CClassicKaisaForm::OnEnChangeEditKaisaPlain)
	ON_EN_CHANGE(IDC_EDIT_KAISA_CIPHER, &CClassicKaisaForm::OnEnChangeEditKaisaCipher)
	ON_EN_KILLFOCUS(IDC_EDIT_KAISA_KEYLEN, &CClassicKaisaForm::OnEnKillfocusEditKaisaKeylen)
	ON_EN_CHANGE(IDC_EDIT_KAISA_KEYLEN, &CClassicKaisaForm::OnEnChangeEditKaisaKeylen)
	ON_BN_CLICKED(IDC_BUTTON_PREW, &CClassicKaisaForm::OnBnClickedButtonPrew)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CClassicKaisaForm::OnBnClickedButtonNext)
END_MESSAGE_MAP()


// CClassicKaisaForm ���



#ifdef _DEBUG
void CClassicKaisaForm::AssertValid() const
{
	CForm::AssertValid();
}

#ifndef _WIN32_WCE
void CClassicKaisaForm::Dump(CDumpContext& dc) const
{
	CForm::Dump(dc);
}
#endif
#endif //_DEBUG


// CClassicKaisaForm ��Ϣ�������

void CClassicKaisaForm::OnInitialUpdate()
{
	CForm::OnInitialUpdate();

	//m_strA=_T("A");
	//m_strB=_T("B");
	//m_strC=_T("C");
	//m_strD=_T("D");
	//m_strE=_T("E");
	//m_strF=_T("F");
	//m_strG=_T("G");
	//m_strH=_T("H");
	//m_strI=_T("I");
	//m_strJ=_T("J");
	//m_strK=_T("K");
	//m_strL=_T("L");
	//m_strM=_T("M");
	//m_strN=_T("N");
	//m_strO=_T("O");
	//m_strP=_T("P");
	//m_strQ=_T("Q");
	//m_strR=_T("R");
	//m_strS=_T("S");
	//m_strT=_T("T");
	//m_strU=_T("U");
	//m_strV=_T("V");
	//m_strW=_T("W");
	//m_strX=_T("X");
	//m_strY=_T("Y");
	//m_strZ=_T("Z");

	//m_stra=_T("a");
	//m_strb=_T("b");
	//m_strc=_T("c");
	//m_strd=_T("d");
	//m_stre=_T("e");
	//m_strf=_T("f");
	//m_strg=_T("g");
	//m_strh=_T("h");
	//m_stri=_T("i");
	//m_strj=_T("j");
	//m_strk=_T("k");
	//m_strl=_T("k");
	//m_strm=_T("m");
	//m_strn=_T("n");
	//m_stro=_T("o");
	//m_strp=_T("p");
	//m_strq=_T("q");
	//m_strr=_T("r");
	//m_strs=_T("s");
	//m_strt=_T("t");
	//m_stru=_T("u");
	//m_strv=_T("v");
	//m_strw=_T("w");
	//m_strx=_T("x");
	//m_stry=_T("y");
	//m_strz=_T("z");

	//������Կ������ѡ��Χ��0-25
	m_spinKeyLength.SetRange(0, 25);

	m_strAlphabet[0]=&m_strA;
	m_strAlphabet[1]=&m_strB;
	m_strAlphabet[2]=&m_strC;
	m_strAlphabet[3]=&m_strD;
	m_strAlphabet[4]=&m_strE;
	m_strAlphabet[5]=&m_strF;
	m_strAlphabet[6]=&m_strG;
	m_strAlphabet[7]=&m_strH;
	m_strAlphabet[8]=&m_strI;
	m_strAlphabet[9]=&m_strJ;
	m_strAlphabet[10]=&m_strK;
	m_strAlphabet[11]=&m_strL;
	m_strAlphabet[12]=&m_strM;
	m_strAlphabet[13]=&m_strN;
	m_strAlphabet[14]=&m_strO;
	m_strAlphabet[15]=&m_strP;
	m_strAlphabet[16]=&m_strQ;
	m_strAlphabet[17]=&m_strR;
	m_strAlphabet[18]=&m_strS;
	m_strAlphabet[19]=&m_strT;
	m_strAlphabet[20]=&m_strU;
	m_strAlphabet[21]=&m_strV;
	m_strAlphabet[22]=&m_strW;
	m_strAlphabet[23]=&m_strX;
	m_strAlphabet[24]=&m_strY;
	m_strAlphabet[25]=&m_strZ;

	m_strAlphabet[26]=&m_stra;
	m_strAlphabet[27]=&m_strb;
	m_strAlphabet[28]=&m_strc;
	m_strAlphabet[29]=&m_strd;
	m_strAlphabet[30]=&m_stre;
	m_strAlphabet[31]=&m_strf;
	m_strAlphabet[32]=&m_strg;
	m_strAlphabet[33]=&m_strh;
	m_strAlphabet[34]=&m_stri;
	m_strAlphabet[35]=&m_strj;
	m_strAlphabet[36]=&m_strk;
	m_strAlphabet[37]=&m_strl;
	m_strAlphabet[38]=&m_strm;
	m_strAlphabet[39]=&m_strn;
	m_strAlphabet[40]=&m_stro;
	m_strAlphabet[41]=&m_strp;
	m_strAlphabet[42]=&m_strq;
	m_strAlphabet[43]=&m_strr;
	m_strAlphabet[44]=&m_strs;
	m_strAlphabet[45]=&m_strt;
	m_strAlphabet[46]=&m_stru;
	m_strAlphabet[47]=&m_strv;
	m_strAlphabet[48]=&m_strw;
	m_strAlphabet[49]=&m_strx;
	m_strAlphabet[50]=&m_stry;
	m_strAlphabet[51]=&m_strz;



	int i;
	for(i=0;i<26;i++)
	{
		m_strAlphabet[i]->Format(_T("%c"),i+97);
	}

	for(i=26;i<52;i++)
	{
		m_strAlphabet[i]->Format(_T("%c"),i+65-26);
	}


	UpdateData(FALSE);

	m_bInitControl= TRUE;
}



// ������ĸlist
void CClassicKaisaForm::AlphabetList()
{
	UpdateData(TRUE);
	for(int i =26;i<52;i++)
	{
		//strTemp
		m_strAlphabet[i]->Format(_T("%c"),GetClassicKaisaChar(i+97-26,_ttoi(m_strKeyLength)));

	}
	UpdateData(FALSE);
}


void CClassicKaisaForm::OnEnChangeEditKaisaPlain()
{
	if(m_bInitControl== TRUE)
	{
		UpdateData(TRUE);

		// ���ܲ������Ŀ�����ʾ
		m_strCipherText = ClassicKaisaEncrypt(m_strPlainText,_ttoi(m_strKeyLength));
		UpdateData(FALSE);

		AlphabetList();
	}
}


void CClassicKaisaForm::OnEnChangeEditKaisaCipher()
{
	if(m_bInitControl== TRUE)
	{
		UpdateData(TRUE);

		//// ���ܲ������Ŀ�����ʾ
		m_strPlainText = ClassicKaisaDecrypt(m_strCipherText,_ttoi(m_strKeyLength));
		UpdateData(FALSE);

	}
}



// ����Կ������ƿ�������¼���Ӧ
void CClassicKaisaForm::OnEnKillfocusEditKaisaKeylen()
{

	if(m_bInitControl== TRUE)
	{
		UpdateData(TRUE);

		// ��Կ����25ʱ�Զ���Ϊ25��
		if(_ttoi(m_strKeyLength) > 25)
		{
			m_strKeyLength=_T("25");
		}

		UpdateData(FALSE);

		AlphabetList();

	}

}





// ����Կ�ı�ʱ���Զ������µ�����
void CClassicKaisaForm::OnEnChangeEditKaisaKeylen()
{
	if(m_bInitControl== TRUE) OnEnChangeEditKaisaPlain();
}


// ���ư�ť�¼���Ӧ
void CClassicKaisaForm::OnBnClickedButtonPrew()
{

	UpdateData(TRUE);
	if(_ttoi(m_strKeyLength)<25) m_strKeyLength.Format(_T("%d"),_ttoi(m_strKeyLength)+1);
		else m_strKeyLength.Format(_T("%d"),0);
	UpdateData(FALSE);
	OnEnChangeEditKaisaPlain();

}


// ���ư�ť�¼���Ӧ
void CClassicKaisaForm::OnBnClickedButtonNext()
{

	UpdateData(TRUE);
	if(_ttoi(m_strKeyLength)>0) m_strKeyLength.Format(_T("%d"),_ttoi(m_strKeyLength)-1);
		else m_strKeyLength.Format(_T("%d"),25);
	UpdateData(FALSE);
	OnEnChangeEditKaisaPlain();

}
