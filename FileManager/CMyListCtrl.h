#pragma once
#include <locale.h>  //  !!한국어 인코딩 설정
#include<vector>
#include <iostream>
#include "FileNameInfo.h"
class CFileManagerDlg;  //  !!부모 클래스 선언

bool compare(const filenameInfo &s1, const filenameInfo& s2); //fileinfo 정렬
						// CMyListCtrl
using namespace std;
class CMyListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListCtrl)

public:
	CMyListCtrl();
	virtual ~CMyListCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	
	CFileManagerDlg * m_pDlg;  //  !!부모 다이얼로그 포인터
	vector<filenameInfo> f_info;

	int indexItem, indexSubitem;  //  !!클릭위치변수
	int totFileNum;  //  !!총 파일 수

	void UpdateThumbNail(CString str = _T(""), UINT width = 0, UINT height = 0, CString strRes = _T(""), CString strByte = _T(""));  //  !!썸네일 삭제
	CString GPStoLocation(double lat, double lon);  //  !!GPS 위도 경도를 장소로 변경

	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);  //  !!메타데이터 항목 더블클릭시 편집가능
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);  //  !!다른곳 클릭시 편집취소
	afx_msg void OnHdnBegintrack(NMHDR *pNMHDR, LRESULT *pResult);  //  !!항목 헤더크기 조절시 편집취소
	afx_msg void OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult);  //  !!항목 헤더클릭시 편집취소
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);  //  !!종스크롤시 편집취소
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);  //  !!횡스크롤시 편집취소
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);  //  !!마우스휠조작시(스크롤) 편집취소
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
};
