#pragma once


// m_propDlg 대화 상자

class m_propDlg : public CDialogEx
{
	DECLARE_DYNAMIC(m_propDlg)

public:
	m_propDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~m_propDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PROP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
};
