// m_propDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "FileManager.h"
#include "m_propDlg.h"
#include "afxdialogex.h"


// m_propDlg 대화 상자

IMPLEMENT_DYNAMIC(m_propDlg, CDialogEx)

m_propDlg::m_propDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PROP, pParent)
{

}

m_propDlg::~m_propDlg()
{
}

void m_propDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(m_propDlg, CDialogEx)
END_MESSAGE_MAP()


// m_propDlg 메시지 처리기


