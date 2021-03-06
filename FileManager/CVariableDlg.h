#pragma once


// CVariableDlg 대화 상자

class CVariableDlg : public CDialog
{
	DECLARE_DYNAMIC(CVariableDlg)

public:
	CVariableDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CVariableDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	CString m_edit;
	int m_num;
}; 