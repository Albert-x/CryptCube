// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// CryptCubeDoc.cpp : CCryptCubeDoc ���ʵ��
//

#include "stdafx.h"
#include "CryptCube.h"

#include "CryptCubeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCryptCubeDoc

IMPLEMENT_DYNCREATE(CCryptCubeDoc, CDocument)

BEGIN_MESSAGE_MAP(CCryptCubeDoc, CDocument)
END_MESSAGE_MAP()


// CCryptCubeDoc ����/����

CCryptCubeDoc::CCryptCubeDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CCryptCubeDoc::~CCryptCubeDoc()
{
}

BOOL CCryptCubeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CCryptCubeDoc ���л�

void CCryptCubeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CCryptCubeDoc ���

#ifdef _DEBUG
void CCryptCubeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCryptCubeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCryptCubeDoc ����
