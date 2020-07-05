// CPropertyDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "FileManager.h"
#include "CPropertyDlg.h"
#include "afxdialogex.h"


// CPropertyDlg 대화 상자

IMPLEMENT_DYNAMIC(CPropertyDlg, CDialogEx)

CPropertyDlg::CPropertyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PROP, pParent)
{

}

CPropertyDlg::~CPropertyDlg()
{
}

void CPropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_THUMB, m_thumb);
	DDX_Control(pDX, IDC_STATIC_TEXT, m_text);
}


BEGIN_MESSAGE_MAP(CPropertyDlg, CDialogEx)
END_MESSAGE_MAP()


// CPropertyDlg 메시지 처리기
