// HashSHA1Key.cpp : 实现文件
//

#include "stdafx.h"
#include "CryptCube.h"
#include "HashSHA1Key.h"
#include "afxdialogex.h"
extern ULONG W1[90];

// HashSHA1Key 对话框

IMPLEMENT_DYNAMIC(HashSHA1Key, CDialogEx)

HashSHA1Key::HashSHA1Key(CWnd* pParent /*=NULL*/)
	: CDialogEx(HashSHA1Key::IDD, pParent)
{

	m_k1 = _T("");
	m_k2 = _T("");
	m_k3 = _T("");
	m_k4 = _T("");
	m_k5 = _T("");
	m_k6 = _T("");
	m_k7 = _T("");
	m_k8 = _T("");
	m_k9 = _T("");
	m_k10 = _T("");
	m_k11 = _T("");
	m_k12 = _T("");
	m_k13 = _T("");
	m_k14 = _T("");
	m_k15 = _T("");
	m_k16 = _T("");
	m_k17 = _T("");
	m_k18 = _T("");
	m_k19 = _T("");
	m_k20 = _T("");
	m_k21 = _T("");
	m_k22 = _T("");
	m_k23 = _T("");
	m_k24 = _T("");
	m_k25 = _T("");
	m_k26 = _T("");
	m_k27 = _T("");
	m_k28 = _T("");
	m_k29 = _T("");
	m_k30 = _T("");
	m_k31 = _T("");
	m_k32 = _T("");
	m_k33 = _T("");
	m_k34 = _T("");
	m_k35 = _T("");
	m_k36 = _T("");
	m_k37 = _T("");
	m_k38 = _T("");
	m_k39 = _T("");
	m_k40 = _T("");
	m_k41 = _T("");
	m_k42 = _T("");
	m_k43 = _T("");
	m_k44 = _T("");
	m_k45 = _T("");
	m_k46 = _T("");
	m_k47 = _T("");
	m_k48 = _T("");
	m_k49 = _T("");
	m_k50 = _T("");
	m_k51 = _T("");
	m_k52 = _T("");
	m_k53 = _T("");
	m_k54 = _T("");
	m_k55 = _T("");
	m_k56 = _T("");
	m_k57 = _T("");
	m_k58 = _T("");
	m_k59 = _T("");
	m_k60 = _T("");
	m_k61 = _T("");
	m_k62 = _T("");
	m_k63 = _T("");
	m_k64 = _T("");
	m_k65 = _T("");
	m_k66 = _T("");
	m_k67 = _T("");
	m_k68 = _T("");
	m_k69 = _T("");
	m_k70 = _T("");
	m_k71 = _T("");
	m_k72 = _T("");
	m_k73 = _T("");
	m_k74 = _T("");
	m_k75 = _T("");
	m_k76 = _T("");
	m_k77 = _T("");
	m_k78 = _T("");
	m_k79 = _T("");
	m_k80 = _T("");
}

HashSHA1Key::~HashSHA1Key()
{
}

void HashSHA1Key::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_k1);
	DDX_Text(pDX, IDC_EDIT74, m_k2);
	DDX_Text(pDX, IDC_EDIT75, m_k3);
	DDX_Text(pDX, IDC_EDIT76, m_k4);
	DDX_Text(pDX, IDC_EDIT77, m_k5);
	DDX_Text(pDX, IDC_EDIT78, m_k6);
	DDX_Text(pDX, IDC_EDIT79, m_k7);
	DDX_Text(pDX, IDC_EDIT80, m_k8);
	DDX_Text(pDX, IDC_EDIT81, m_k9);
	DDX_Text(pDX, IDC_EDIT82, m_k10);
	DDX_Text(pDX, IDC_EDIT83, m_k11);
	DDX_Text(pDX, IDC_EDIT84, m_k12);
	DDX_Text(pDX, IDC_EDIT85, m_k13);
	DDX_Text(pDX, IDC_EDIT86, m_k14);
	DDX_Text(pDX, IDC_EDIT87, m_k15);
	DDX_Text(pDX, IDC_EDIT88, m_k16);
	DDX_Text(pDX, IDC_EDIT89, m_k17);
	DDX_Text(pDX, IDC_EDIT90, m_k18);
	DDX_Text(pDX, IDC_EDIT93, m_k19);
	DDX_Text(pDX, IDC_EDIT94, m_k20);
	DDX_Text(pDX, IDC_EDIT95, m_k21);
	DDX_Text(pDX, IDC_EDIT96, m_k22);
	DDX_Text(pDX, IDC_EDIT97, m_k23);
	DDX_Text(pDX, IDC_EDIT98, m_k24);
	DDX_Text(pDX, IDC_EDIT99, m_k25);
	DDX_Text(pDX, IDC_EDIT100, m_k26);
	DDX_Text(pDX, IDC_EDIT101, m_k27);
	DDX_Text(pDX, IDC_EDIT102, m_k28);
	DDX_Text(pDX, IDC_EDIT103, m_k29);
	DDX_Text(pDX, IDC_EDIT104, m_k30);
	DDX_Text(pDX, IDC_EDIT105, m_k31);
	DDX_Text(pDX, IDC_EDIT106, m_k32);
	DDX_Text(pDX, IDC_EDIT107, m_k33);
	DDX_Text(pDX, IDC_EDIT108, m_k34);
	DDX_Text(pDX, IDC_EDIT109, m_k35);
	DDX_Text(pDX, IDC_EDIT110, m_k36);
	DDX_Text(pDX, IDC_EDIT111, m_k37);
	DDX_Text(pDX, IDC_EDIT112, m_k38);
	DDX_Text(pDX, IDC_EDIT113, m_k39);
	DDX_Text(pDX, IDC_EDIT114, m_k40);
	DDX_Text(pDX, IDC_EDIT69, m_k41);
	DDX_Text(pDX, IDC_EDIT115, m_k42);
	DDX_Text(pDX, IDC_EDIT116, m_k43);
	DDX_Text(pDX, IDC_EDIT117, m_k44);
	DDX_Text(pDX, IDC_EDIT91, m_k45);
	DDX_Text(pDX, IDC_EDIT118, m_k46);
	DDX_Text(pDX, IDC_EDIT119, m_k47);
	DDX_Text(pDX, IDC_EDIT120, m_k48);
	DDX_Text(pDX, IDC_EDIT12, m_k49);
	DDX_Text(pDX, IDC_EDIT121, m_k50);
	DDX_Text(pDX, IDC_EDIT122, m_k51);
	DDX_Text(pDX, IDC_EDIT123, m_k52);
	DDX_Text(pDX, IDC_EDIT124, m_k53);
	DDX_Text(pDX, IDC_EDIT125, m_k54);
	DDX_Text(pDX, IDC_EDIT126, m_k55);
	DDX_Text(pDX, IDC_EDIT127, m_k56);
	DDX_Text(pDX, IDC_EDIT72, m_k57);
	DDX_Text(pDX, IDC_EDIT128, m_k58);
	DDX_Text(pDX, IDC_EDIT129, m_k59);
	DDX_Text(pDX, IDC_EDIT130, m_k60);
	DDX_Text(pDX, IDC_EDIT131, m_k61);
	DDX_Text(pDX, IDC_EDIT132, m_k62);
	DDX_Text(pDX, IDC_EDIT133, m_k63);
	DDX_Text(pDX, IDC_EDIT134, m_k64);
	DDX_Text(pDX, IDC_EDIT135, m_k65);
	DDX_Text(pDX, IDC_EDIT136, m_k66);
	DDX_Text(pDX, IDC_EDIT137, m_k67);
	DDX_Text(pDX, IDC_EDIT138, m_k68);
	DDX_Text(pDX, IDC_EDIT139, m_k69);
	DDX_Text(pDX, IDC_EDIT140, m_k70);
	DDX_Text(pDX, IDC_EDIT141, m_k71);
	DDX_Text(pDX, IDC_EDIT142, m_k72);
	DDX_Text(pDX, IDC_EDIT22, m_k73);
	DDX_Text(pDX, IDC_EDIT143, m_k74);
	DDX_Text(pDX, IDC_EDIT144, m_k75);
	DDX_Text(pDX, IDC_EDIT145, m_k76);
	DDX_Text(pDX, IDC_EDIT146, m_k77);
	DDX_Text(pDX, IDC_EDIT147, m_k78);
	DDX_Text(pDX, IDC_EDIT148, m_k79);
	DDX_Text(pDX, IDC_EDIT149, m_k80);
}
BEGIN_MESSAGE_MAP(HashSHA1Key, CDialogEx)
END_MESSAGE_MAP()


// HashSHA1Key 消息处理程序


BOOL HashSHA1Key::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(TRUE);
	m_k1.Format("%08X",W1[0]);
	GetDlgItem(IDC_EDIT1)->SetWindowText(m_k1);
	m_k2.Format("%08X",W1[1]);
	GetDlgItem(IDC_EDIT74)->SetWindowText(m_k2);
	m_k3.Format("%08X",W1[2]);
	GetDlgItem(IDC_EDIT75)->SetWindowText(m_k3);
	m_k4.Format("%08X",W1[3]);
	GetDlgItem(IDC_EDIT76)->SetWindowText(m_k4);
	m_k5.Format("%08X",W1[4]);
	GetDlgItem(IDC_EDIT77)->SetWindowText(m_k5);
	m_k6.Format("%08X",W1[5]);
	GetDlgItem(IDC_EDIT78)->SetWindowText(m_k6);
	m_k7.Format("%08X",W1[6]);
	GetDlgItem(IDC_EDIT79)->SetWindowText(m_k7);
	m_k8.Format("%08X",W1[7]);
	GetDlgItem(IDC_EDIT80)->SetWindowText(m_k8);
//1
	m_k9.Format("%08X",W1[8]);
	GetDlgItem(IDC_EDIT81)->SetWindowText(m_k9);
	m_k10.Format("%08X",W1[9]);
	GetDlgItem(IDC_EDIT82)->SetWindowText(m_k10);
	m_k11.Format("%08X",W1[10]);
	GetDlgItem(IDC_EDIT83)->SetWindowText(m_k11);
	m_k12.Format("%08X",W1[11]);
	GetDlgItem(IDC_EDIT84)->SetWindowText(m_k12);
	m_k13.Format("%08X",W1[12]);
	GetDlgItem(IDC_EDIT85)->SetWindowText(m_k13);
	m_k14.Format("%08X",W1[13]);
	GetDlgItem(IDC_EDIT86)->SetWindowText(m_k14);
	m_k15.Format("%08X",W1[14]);
	GetDlgItem(IDC_EDIT87)->SetWindowText(m_k15);
	m_k16.Format("%08X",W1[15]);
	GetDlgItem(IDC_EDIT88)->SetWindowText(m_k16);
//2
	m_k17.Format("%08X",W1[16]);
	GetDlgItem(IDC_EDIT89)->SetWindowText(m_k17);
	m_k18.Format("%08X",W1[17]);
	GetDlgItem(IDC_EDIT90)->SetWindowText(m_k18);
	m_k19.Format("%08X",W1[18]);
	GetDlgItem(IDC_EDIT93)->SetWindowText(m_k19);
	m_k20.Format("%08X",W1[19]);
	GetDlgItem(IDC_EDIT94)->SetWindowText(m_k20);
	m_k21.Format("%08X",W1[20]);
	GetDlgItem(IDC_EDIT95)->SetWindowText(m_k21);
	m_k22.Format("%08X",W1[21]);
	GetDlgItem(IDC_EDIT96)->SetWindowText(m_k22);
	m_k23.Format("%08X",W1[22]);
	GetDlgItem(IDC_EDIT97)->SetWindowText(m_k23);
	m_k24.Format("%08X",W1[23]);
	GetDlgItem(IDC_EDIT98)->SetWindowText(m_k24);
//3
	m_k25.Format("%08X",W1[24]);
	GetDlgItem(IDC_EDIT99)->SetWindowText(m_k25);
	m_k26.Format("%08X",W1[25]);
	GetDlgItem(IDC_EDIT100)->SetWindowText(m_k26);
	m_k27.Format("%08X",W1[26]);
	GetDlgItem(IDC_EDIT101)->SetWindowText(m_k27);
	m_k28.Format("%08X",W1[27]);
	GetDlgItem(IDC_EDIT102)->SetWindowText(m_k28);
	m_k29.Format("%08X",W1[28]);
	GetDlgItem(IDC_EDIT103)->SetWindowText(m_k29);
	m_k30.Format("%08X",W1[29]);
	GetDlgItem(IDC_EDIT104)->SetWindowText(m_k30);
	m_k31.Format("%08X",W1[30]);
	GetDlgItem(IDC_EDIT105)->SetWindowText(m_k31);
	m_k32.Format("%08X",W1[31]);
	GetDlgItem(IDC_EDIT106)->SetWindowText(m_k32);
//4
	m_k33.Format("%08X",W1[32]);
	GetDlgItem(IDC_EDIT107)->SetWindowText(m_k33);
	m_k34.Format("%08X",W1[33]);
	GetDlgItem(IDC_EDIT108)->SetWindowText(m_k34);
	m_k35.Format("%08X",W1[34]);
	GetDlgItem(IDC_EDIT109)->SetWindowText(m_k35);
	m_k36.Format("%08X",W1[35]);
	GetDlgItem(IDC_EDIT110)->SetWindowText(m_k36);
	m_k37.Format("%08X",W1[36]);
	GetDlgItem(IDC_EDIT111)->SetWindowText(m_k37);
	m_k38.Format("%08X",W1[37]);
	GetDlgItem(IDC_EDIT112)->SetWindowText(m_k38);
	m_k39.Format("%08X",W1[38]);
	GetDlgItem(IDC_EDIT113)->SetWindowText(m_k39);
	m_k40.Format("%08X",W1[39]);
	GetDlgItem(IDC_EDIT114)->SetWindowText(m_k40);
//5
	m_k41.Format("%08X",W1[40]);
	GetDlgItem(IDC_EDIT69)->SetWindowText(m_k41);
	m_k42.Format("%08X",W1[41]);
	GetDlgItem(IDC_EDIT115)->SetWindowText(m_k42);
	m_k43.Format("%08X",W1[42]);
	GetDlgItem(IDC_EDIT116)->SetWindowText(m_k43);
	m_k44.Format("%08X",W1[43]);
	GetDlgItem(IDC_EDIT117)->SetWindowText(m_k44);
	m_k45.Format("%08X",W1[44]);
	GetDlgItem(IDC_EDIT91)->SetWindowText(m_k45);
	m_k46.Format("%08X",W1[45]);
	GetDlgItem(IDC_EDIT118)->SetWindowText(m_k46);
	m_k47.Format("%08X",W1[46]);
	GetDlgItem(IDC_EDIT119)->SetWindowText(m_k47);
	m_k48.Format("%08X",W1[47]);
	GetDlgItem(IDC_EDIT120)->SetWindowText(m_k48);
//6
	m_k49.Format("%08X",W1[48]);
	GetDlgItem(IDC_EDIT12)->SetWindowText(m_k49);
	m_k50.Format("%08X",W1[49]);
	GetDlgItem(IDC_EDIT121)->SetWindowText(m_k50);
	m_k51.Format("%08X",W1[50]);
	GetDlgItem(IDC_EDIT122)->SetWindowText(m_k51);
	m_k52.Format("%08X",W1[51]);
	GetDlgItem(IDC_EDIT123)->SetWindowText(m_k52);
	m_k53.Format("%08X",W1[52]);
	GetDlgItem(IDC_EDIT124)->SetWindowText(m_k53);
	m_k54.Format("%08X",W1[53]);
	GetDlgItem(IDC_EDIT125)->SetWindowText(m_k54);
	m_k55.Format("%08X",W1[54]);
	GetDlgItem(IDC_EDIT126)->SetWindowText(m_k55);
	m_k56.Format("%08X",W1[55]);
	GetDlgItem(IDC_EDIT127)->SetWindowText(m_k56);
//7
	m_k57.Format("%08X",W1[56]);
	GetDlgItem(IDC_EDIT72)->SetWindowText(m_k57);
	m_k58.Format("%08X",W1[57]);
	GetDlgItem(IDC_EDIT128)->SetWindowText(m_k58);
	m_k59.Format("%08X",W1[58]);
	GetDlgItem(IDC_EDIT129)->SetWindowText(m_k59);
	m_k60.Format("%08X",W1[59]);
	GetDlgItem(IDC_EDIT130)->SetWindowText(m_k60);
	m_k61.Format("%08X",W1[60]);
	GetDlgItem(IDC_EDIT131)->SetWindowText(m_k61);
	m_k62.Format("%08X",W1[61]);
	GetDlgItem(IDC_EDIT132)->SetWindowText(m_k62);
	m_k63.Format("%08X",W1[62]);
	GetDlgItem(IDC_EDIT133)->SetWindowText(m_k63);
	m_k64.Format("%08X",W1[63]);
	GetDlgItem(IDC_EDIT134)->SetWindowText(m_k64);
//8
	m_k65.Format("%08X",W1[64]);
	GetDlgItem(IDC_EDIT135)->SetWindowText(m_k65);
	m_k66.Format("%08X",W1[65]);
	GetDlgItem(IDC_EDIT136)->SetWindowText(m_k66);
	m_k67.Format("%08X",W1[66]);
	GetDlgItem(IDC_EDIT137)->SetWindowText(m_k67);
	m_k68.Format("%08X",W1[67]);
	GetDlgItem(IDC_EDIT138)->SetWindowText(m_k68);
	m_k69.Format("%08X",W1[68]);
	GetDlgItem(IDC_EDIT139)->SetWindowText(m_k69);
	m_k70.Format("%08X",W1[69]);
	GetDlgItem(IDC_EDIT140)->SetWindowText(m_k70);
	m_k71.Format("%08X",W1[70]);
	GetDlgItem(IDC_EDIT141)->SetWindowText(m_k71);
	m_k72.Format("%08X",W1[71]);
	GetDlgItem(IDC_EDIT142)->SetWindowText(m_k72);
//9
	m_k73.Format("%08X",W1[72]);
	GetDlgItem(IDC_EDIT22)->SetWindowText(m_k73);
	m_k74.Format("%08X",W1[73]);
	GetDlgItem(IDC_EDIT143)->SetWindowText(m_k74);
	m_k75.Format("%08X",W1[74]);
	GetDlgItem(IDC_EDIT144)->SetWindowText(m_k75);
	m_k76.Format("%08X",W1[75]);
	GetDlgItem(IDC_EDIT145)->SetWindowText(m_k76);
	m_k77.Format("%08X",W1[76]);
	GetDlgItem(IDC_EDIT146)->SetWindowText(m_k77);
	m_k78.Format("%08X",W1[77]);
	GetDlgItem(IDC_EDIT147)->SetWindowText(m_k78);
	m_k79.Format("%08X",W1[78]);
	GetDlgItem(IDC_EDIT148)->SetWindowText(m_k79);
	m_k80.Format("%08X",W1[79]);
	GetDlgItem(IDC_EDIT149)->SetWindowText(m_k80);
//10

	UpdateData(FALSE);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
