
// FileManagerDlg.h: 헤더 파일
//

#pragma once

//  !!메타데이터 열 번호 지정
enum COL_SND
{
	ARTIST = 1, TITLE
};
enum COL_IMG
{
	MOMENT = 3, LOCATION
};
//  !!속성창 크기
#define PROP_WIDTH 210
#define PROP_HEIGHT 270
#define PROP_LENGTH 200

#include <locale.h>
#include <vector>
#include "CMyListCtrl.h"
#include "CPropertyDlg.h"  //  !!선택한 항목 정보창
#include "CMyHelpDlg.h"

using namespace std;
// CFileManagerDlg 대화 상자
class CFileManagerDlg : public CDialog
{
	// 생성입니다.
public:
	CFileManagerDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.

												// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEMANAGER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV 지원입니다.


													   // 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	CMyListCtrl m_list;
	CListCtrl m_change;
	CTreeCtrl m_tree;
	CString m_strEdit;  //  !!에디트컨트롤 스트링
	CEdit m_ctrEdit;  //  !!에디트컨트롤
	CPropertyDlg* m_propDlg;

	void makeDirectory(vector<filenameInfo> f_info);

	int findeNode(HTREEITEM parm_item, CString parm_string, HTREEITEM * temp, bool *isChildren);
	vector<HTREEITEM> child_arr;
	afx_msg void OnBnClickedButton2();

	CString m_edit; //사용자지정변경 때 사용자가 지정한 이름
	int m_num; //사용자지정 변경 때 사용자가 지정한 번호
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnLvnItemchangedChange(NMHDR *pNMHDR, LRESULT *pResult);
	int showAfterName();
	virtual void OnOK();  //  !!메타데이터 수정시 엔터키로 입력
	virtual void PostNcDestroy();  //  !!프로그램종료시 GDI+종료

	afx_msg void OnBnClickedButton6(); // 폴더 이름 설정 후 바탕화면에 생성 -> 리스트에서 선택한 파일들 이동.
	void CreateFolder(CString csPath); // 폴더 생성 함수
	void MoveDirectory(CString parm_src_path, CString parm_dest_path); // 폴더속 내용물을 통째로 이동시키고 싶을 경우 사용하는 함수
	CString folderName; // 생성 폴더 이름

	afx_msg void OnBnClickedButton3();
	void makeChangeDirectory(vector<filenameInfo> f_info);
	afx_msg void OnBnClickedButton5();
	CBitmapButton m_returnBtn;
	CBitmapButton m_userBtn;
	CBitmapButton m_totalNumberingBtn;
	CBitmapButton m_applyBtn;
	CBitmapButton m_initBtn;
	CBitmapButton m_folderBtn;
	afx_msg void OnBnClickedbtn();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CBitmap m_background;
	CBitmapButton m_logoBtn;
	afx_msg void OnBnClickedButton7();
	CMyHelpDlg m_helpDlg;
};