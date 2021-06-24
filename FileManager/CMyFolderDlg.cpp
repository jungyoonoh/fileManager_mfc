// CMyFolderDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "FileManager.h"
#include "CMyFolderDlg.h"
#include "afxdialogex.h"


// CMyFolderDlg 대화 상자

IMPLEMENT_DYNAMIC(CMyFolderDlg, CDialog)

CMyFolderDlg::CMyFolderDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CMyFolderDlg::~CMyFolderDlg()
{
}

void CMyFolderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CMyFolderDlg, CDialog)
END_MESSAGE_MAP()


// CMyFolderDlg 메시지 처리기


void CMyFolderDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_edit.GetWindowTextW(folderName);
	CDialog::OnOK();
}
