
// FileManagerDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "FileManager.h"
#include "FileManagerDlg.h"
#include "afxdialogex.h"
#include "CVariableDlg.h"
#include "CMyFolderDlg.h"
#include "CMyHelpDlg.h"

#include "tag.h"
#include "fileref.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//  !!GDI+ 설정
#include <gdiplus.h>  //  !!GDI+용 헤더
using namespace Gdiplus;
ULONG_PTR g_GdiplusToken;


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

														// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileManagerDlg 대화 상자



CFileManagerDlg::CFileManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_FILEMANAGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//  !!GDI+ 시작
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiplusToken, &GdiplusStartupInput, NULL);
}

void CFileManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_CHANGE, m_change);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Control(pDX, IDC_EDIT1, m_ctrEdit);
	DDX_Control(pDX, IDC_BUTTON3, m_returnBtn);
	DDX_Control(pDX, user_btn, m_userBtn);
	DDX_Control(pDX, IDC_BUTTON1, m_totalNumberingBtn);
	DDX_Control(pDX, IDC_BUTTON4, m_applyBtn);
	DDX_Control(pDX, IDC_BUTTON5, m_initBtn);
	DDX_Control(pDX, IDC_BUTTON6, m_folderBtn);
	DDX_Control(pDX, IDC_BUTTON7, m_logoBtn);
}

BEGIN_MESSAGE_MAP(CFileManagerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDC_BUTTON2, &CFileManagerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CFileManagerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CFileManagerDlg::OnBnClickedButton4)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_CHANGE, &CFileManagerDlg::OnLvnItemchangedChange)
	ON_BN_CLICKED(IDC_BUTTON6, &CFileManagerDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &CFileManagerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CFileManagerDlg::OnBnClickedButton5)
	ON_BN_CLICKED(user_btn, &CFileManagerDlg::OnBnClickedbtn)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON7, &CFileManagerDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CFileManagerDlg 메시지 처리기

BOOL CFileManagerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);         // 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);      // 작은 아이콘을 설정합니다.

								  // TODO: 여기에 추가 초기화 작업을 추가합니다.

	setlocale(LC_ALL, "korean"); // 인코딩 관련

	m_returnBtn.LoadBitmaps(IDB_BITMAP2, IDB_BITMAP2, IDB_BITMAP2, IDB_BITMAP2);
	m_returnBtn.SizeToContent();
	m_userBtn.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP3, IDB_BITMAP3, IDB_BITMAP3);
	m_userBtn.SizeToContent();
	m_totalNumberingBtn.LoadBitmaps(IDB_BITMAP4, IDB_BITMAP4, IDB_BITMAP4, IDB_BITMAP4);
	m_totalNumberingBtn.SizeToContent();
	m_applyBtn.LoadBitmaps(IDB_BITMAP6, IDB_BITMAP6, IDB_BITMAP6, IDB_BITMAP6);
	m_applyBtn.SizeToContent();
	m_initBtn.LoadBitmaps(IDB_BITMAP7, IDB_BITMAP7, IDB_BITMAP7, IDB_BITMAP7);
	m_initBtn.SizeToContent();
	m_folderBtn.LoadBitmaps(IDB_BITMAP8, IDB_BITMAP8, IDB_BITMAP8, IDB_BITMAP8);
	m_folderBtn.SizeToContent();
	m_logoBtn.LoadBitmaps(IDB_BITMAP9, IDB_BITMAP9, IDB_BITMAP9, IDB_BITMAP9);
	m_logoBtn.SizeToContent();

	m_list.InsertColumn(0, _T("현재 이름"), LVCFMT_LEFT, 200);
	m_change.InsertColumn(0, _T("변경 이름"), LVCFMT_LEFT, 200);

	m_list.InsertColumn(ARTIST, _T("가수 이름"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(TITLE, _T("노래 제목"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(MOMENT, _T("촬영 날짜"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(LOCATION, _T("촬영 장소"), LVCFMT_LEFT, 100);

	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT/* | LVS_EX_TRACKSELECT*/);
	m_change.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT/* | LVS_EX_TRACKSELECT*/);

	//  !!속성창 부착
	CRect rect;
	GetClientRect(&rect);
	this->m_propDlg = new CPropertyDlg();  //  !!메모리 할당
	m_propDlg->Create(IDD_DIALOG_PROP);  //  !!생성
	m_propDlg->ShowWindow(SW_SHOW);  //  !!출력
	m_propDlg->MoveWindow(rect.Width() - PROP_WIDTH - 13, rect.Height() - PROP_HEIGHT - 13, PROP_WIDTH, PROP_HEIGHT);  //  !!13: 가장자리 여백


	m_background.LoadBitmapW(IDB_BITMAP1);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFileManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFileManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFileManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileManagerDlg::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CFileManagerDlg::makeChangeDirectory(vector<filenameInfo> f_info) {
	m_tree.DeleteAllItems();
	child_arr.clear();
	for (int i = 0; i < f_info.size(); i++) {

		CStringArray cstr_arr;
		int nTokenPos = 0;
		CString strToken;
		if (m_list.f_info[i].afterPath != _T(""))
			strToken = f_info[i].afterPath.Tokenize(_T("\\"), nTokenPos);
		else
			strToken = f_info[i].beforePath.Tokenize(_T("\\"), nTokenPos);
		while (!strToken.IsEmpty())
		{
			cstr_arr.Add(strToken);
			if (m_list.f_info[i].afterPath != _T(""))
				strToken = f_info[i].afterPath.Tokenize(_T("\\"), nTokenPos);
			else
				strToken = f_info[i].beforePath.Tokenize(_T("\\"), nTokenPos);

		}
		if (m_tree.GetRootItem() == NULL) { //처음 추가하는건지 판단

			HTREEITEM root_branch = m_tree.InsertItem(cstr_arr[0]);

			child_arr.push_back(root_branch);
			for (int i = 1; i < cstr_arr.GetCount(); i++) {
				child_arr.push_back(m_tree.InsertItem(cstr_arr[i], child_arr[i - 1]));
			}
			cstr_arr.RemoveAll();

		}
		else {
			bool isChildren = NULL;
			HTREEITEM start = m_tree.GetRootItem();
			HTREEITEM index = NULL;
			HTREEITEM temp;//자식있을 때 체크하는 변수
			int count = 0;
			for (count = 0; count < cstr_arr.GetCount(); count++) {
				if (!findeNode(start, cstr_arr.GetAt(count), &index, &isChildren)) {
					//0:없음 1: 있음 
					//index -> 다른 경로에 있는 같은 폴더명일 경우: 먼저 추가된 것을 기준으로 추가됨 시불탱
					break;
				}
				else {
					if (isChildren) {
						start = index;
					}
				}
			}
			for (int i = count; i < cstr_arr.GetCount(); i++) {
				if (i == count)
					child_arr.push_back(m_tree.InsertItem(cstr_arr[i], index));
				else
					child_arr.push_back(m_tree.InsertItem(cstr_arr[i], child_arr[child_arr.size() - 1]));
			}

		}

	}
}

void CFileManagerDlg::makeDirectory(vector<filenameInfo> f_info)
{

	m_tree.DeleteAllItems();
	child_arr.clear();
	for (int i = 0; i < f_info.size(); i++) {

		CStringArray cstr_arr;
		int nTokenPos = 0;
		CString strToken = f_info[i].beforePath.Tokenize(_T("\\"), nTokenPos);
		while (!strToken.IsEmpty())
		{
			cstr_arr.Add(strToken);
			strToken = f_info[i].beforePath.Tokenize(_T("\\"), nTokenPos);

		}
		if (m_tree.GetRootItem() == NULL) { //처음 추가하는건지 판단

			HTREEITEM root_branch = m_tree.InsertItem(cstr_arr[0]);

			child_arr.push_back(root_branch);
			for (int i = 1; i < cstr_arr.GetCount(); i++) {
				child_arr.push_back(m_tree.InsertItem(cstr_arr[i], child_arr[i - 1]));
			}
			cstr_arr.RemoveAll();

		}
		else {
			bool isChildren = NULL;
			HTREEITEM start = m_tree.GetRootItem();
			HTREEITEM index = NULL;
			HTREEITEM temp;//자식있을 때 체크하는 변수
			int count = 0;
			for (count = 0; count < cstr_arr.GetCount(); count++) {
				if (!findeNode(start, cstr_arr.GetAt(count), &index, &isChildren)) {
					//0:없음 1: 있음 
					//index -> 다른 경로에 있는 같은 폴더명일 경우: 먼저 추가된 것을 기준으로 추가됨 시불탱
					break;
				}
				else {
					if (isChildren) {
						start = index;
					}
				}
			}
			for (int i = count; i < cstr_arr.GetCount(); i++) {
				if (i == count)
					child_arr.push_back(m_tree.InsertItem(cstr_arr[i], index));
				else
					child_arr.push_back(m_tree.InsertItem(cstr_arr[i], child_arr[child_arr.size() - 1]));
			}

		}

	}
}
int CFileManagerDlg::findeNode(HTREEITEM parm_item, CString parm_string, HTREEITEM * temp, bool *isChildren)
{
	if (m_tree.GetItemText(parm_item) == parm_string) {
		// 검색하고자 하는 항목을 찾은 경우..
		m_tree.Select(parm_item, TVGN_CARET);
		*temp = parm_item;
		return 1;
	}
	else {
		if (m_tree.ItemHasChildren(parm_item)) {
			// 자식노드가 있는 경우, 자식노드를 탐색해야 한다.
			HTREEITEM child_item = m_tree.GetChildItem(parm_item);

			do {
				if (1 == findeNode(child_item, parm_string, temp, isChildren)) { *isChildren = true; return 1; }
			} while ((child_item = m_tree.GetNextSiblingItem(child_item)) != NULL);
		}
	}

	return 0;
}




void CFileManagerDlg::OnBnClickedButton2() //사용자 지정
{

	CVariableDlg m_dlg;
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (pos != NULL) {
		while (pos) {
			int nItem = m_list.GetNextSelectedItem(pos);
			m_list.f_info[nItem].select = true;
		}
	}
	int num = 1;

	if (m_dlg.DoModal() == IDOK) {

		for (int i = 0; i < m_list.f_info.size(); i++) {
			//m_list.f_info.at(i).afterName = _T("");
		}

		m_num = m_dlg.m_num;
		m_edit = m_dlg.m_edit;
		CString sel = _T("");
		for (int i = 0; i < m_list.f_info.size(); i++) {
			if (m_list.f_info.at(i).select) {
				CStringArray cstr_arr;
				CString before_str = m_list.f_info.at(i).beforePath;
				int nTokenPos = 0;
				CString strToken = before_str.Tokenize(_T("\\"), nTokenPos);
				while (!strToken.IsEmpty())
				{
					cstr_arr.Add(strToken);
					strToken = before_str.Tokenize(_T("\\"), nTokenPos);
				}
				nTokenPos = 0;
				CString test = cstr_arr.GetAt(cstr_arr.GetCount() - 1).Tokenize(_T("."), nTokenPos);

				CStringArray type;
				while (!test.IsEmpty())
				{
					type.Add(test);
					test = cstr_arr.GetAt(cstr_arr.GetCount() - 1).Tokenize(_T("."), nTokenPos);
				}


				CString str = _T("");
				for (int j = 0; j < cstr_arr.GetCount() - 1; j++) {
					str = str + cstr_arr[j] + _T("\\");
				}
				int d_nTokenPos = 0;
				CString d_str;
				CString d_strToken;
				switch (m_num) {
				case 0:
					sel = _T("");
					break;
				case 1:
					if (m_list.f_info[i].strDate == _T("")) {
						sel = _T("_날짜_");
					}
					else {
						d_str = m_list.f_info[i].strDate;
						d_strToken = d_str.Tokenize(_T(" "), d_nTokenPos);
						sel = _T("_") + d_strToken + _T("_");
					}
					break;
				case 2:
					if (m_list.f_info[i].strLocation == _T("")) {
						sel = _T("_장소_");
					}
					else
						sel = _T("_") + m_list.f_info[i].strLocation + _T("_");
					break;
				case 3:
					if (m_list.f_info[i].strArtist == _T("")) {
						sel = _T("_가수_");
					}
					else {
						sel = _T("_") + m_list.f_info[i].strArtist + _T("_");
					}
					break;
				case 4:
					if (m_list.f_info[i].strTitle == _T("")) {
						sel = _T("_노래제목_");
					}
					else
						sel = _T("_") + m_list.f_info[i].strTitle + _T("_");
					break;
				default:
					break;
				}
				CString str2 = m_edit;
				CString str4;
				str4.Format(_T("%d"), num);
				CString str3 = sel + str4;
				num++;
				str = str + str2 + str3 + _T(".") + type.GetAt(type.GetCount() - 1);
				m_list.f_info[i].afterPath = str;
				m_list.f_info[i].type = type.GetAt(type.GetCount() - 1);
				m_list.f_info[i].afterName = str2 + str3;
				m_list.f_info[i].select = false;
			}
		}
		showAfterName();
	}

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFileManagerDlg::OnBnClickedButton1() //일괄
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = 1;
	CString before_change;
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (pos != NULL) {
		for (int i = 0; i < m_list.f_info.size(); i++) {
			m_list.f_info.at(i).afterName = _T("");
		}
		while (pos) {			
			int nItem = m_list.GetNextSelectedItem(pos);
			before_change = m_list.f_info[nItem].beforePath;
			CStringArray cstr_arr;
			int nTokenPos = 0;
			CString strToken = before_change.Tokenize(_T("\\"), nTokenPos);
			while (!strToken.IsEmpty())
			{
				cstr_arr.Add(strToken);
				strToken = before_change.Tokenize(_T("\\"), nTokenPos);
			}
			nTokenPos = 0;
			CString test = cstr_arr.GetAt(cstr_arr.GetCount() - 1).Tokenize(_T("."), nTokenPos);
			CStringArray type;
			while (!test.IsEmpty())
			{
				type.Add(test);
				test = cstr_arr.GetAt(cstr_arr.GetCount() - 1).Tokenize(_T("."), nTokenPos);
			}
			CString str = _T("");
			for (int j = 0; j < cstr_arr.GetCount() - 1; j++) {
				str = str + cstr_arr[j] + _T("\\");
			}
			CString str2 = folderName;
			CString str3;
			str3.Format(_T("%d"), num);
			num++;
			str = str + str2 + str3 + _T(".") + type.GetAt(type.GetCount() - 1);
			m_list.f_info[nItem].afterName = str2 + str3;
			m_list.f_info[nItem].afterPath = str;
			m_list.f_info[nItem].type = type.GetAt(type.GetCount() - 1);

		}
		showAfterName();
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFileManagerDlg::OnBnClickedButton4() //변경버튼 눌렀을 때(아예 확정!!)
{
	for (int i = 0; i < m_list.f_info.size(); i++) {
		if (!m_list.f_info[i].changeCheck) {
			rename((CStringA)m_list.f_info[i].beforePath, (CStringA)m_list.f_info[i].afterPath);
			m_list.f_info[i].changeCheck = true;
		}
	}
	child_arr.clear(); //트리 자식들 지우기
	makeChangeDirectory(m_list.f_info); //바뀐거 트리에서 보여주기
//	child_arr.clear(); //트리 자식들 지우기
	//전부 리셋
//	m_list.f_info.clear();

	m_change.DeleteAllItems();
	for (int i = 0; i < m_list.f_info.size(); i++) {
		if (m_list.f_info[i].afterName == _T(""))
			m_list.SetItemText(i, 0, m_list.f_info[i].beforeName);
		else
			m_list.SetItemText(i, 0, m_list.f_info[i].afterName);
		m_list.SetItemText(i, 1, m_list.f_info[i].strArtist);
		m_list.SetItemText(i, 2, m_list.f_info[i].strTitle);
		m_list.SetItemText(i, 3, m_list.f_info[i].strDate);
		m_list.SetItemText(i, 4, m_list.f_info[i].strLocation);

		m_change.InsertItem(i, _T(""), 0);
	}

//	showAfterName();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFileManagerDlg::OnLvnItemchangedChange(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


int CFileManagerDlg::showAfterName()
{
	// TODO: 여기에 구현 코드 추가.
	m_change.DeleteAllItems();
	for (int i = 0; i < m_list.f_info.size(); i++) {
		m_change.InsertItem(i, m_list.f_info[i].afterName, 0);
	}
	return 0;
}



void CFileManagerDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	HWND hEdit;  //  !!에디트컨트롤 핸들러
	hEdit = ::GetDlgItem(GetSafeHwnd(), IDC_EDIT1);

	if (hEdit == GetFocus()->GetSafeHwnd()) {  //  !!현재 포커스가 에디트컨트롤
		AfxMessageBox(_T("메타데이터 변경"));
		m_ctrEdit.GetWindowTextW(m_strEdit);  //  !!m_strEdit : 입력받은 스트링

		if (m_list.SetItemText(m_list.indexItem, m_list.indexSubitem, m_strEdit) == FALSE)
			return;

		//  !!메타데이터 저장
		TagLib::FileName pathSound(m_list.f_info[m_list.indexItem].beforePath);
		TagLib::FileRef sndFile(pathSound);
		TagLib::String artist, title;

		switch (m_list.indexSubitem)
		{
		case ARTIST:
			artist = m_strEdit;
			sndFile.tag()->setArtist(artist);
			m_list.f_info[m_list.indexItem].strArtist = m_strEdit;
			sndFile.save();
			break;
		case TITLE:
			title = m_strEdit;
			sndFile.tag()->setTitle(title);
			m_list.f_info[m_list.indexItem].strTitle = m_strEdit;
			sndFile.save();
			break;
		case MOMENT:
			
			break;
		case LOCATION:
			break;
		default:
			break;
		}

		::SendMessage(hEdit, WM_KILLFOCUS, 0, 0);
		m_ctrEdit.ShowWindow(SW_HIDE);
		m_list.SetFocus();
	}

	//CDialog::OnOK();
}


void CFileManagerDlg::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	//  !!GDI+ 종료
	GdiplusShutdown(g_GdiplusToken);

	CDialog::PostNcDestroy();
}


void CFileManagerDlg::OnBnClickedButton6() // 폴더 생성 후 이동하기 (바뀌기 전 이름, 바뀐 후 이름 구분)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMyFolderDlg folderDlg;
	POSITION pos = m_list.GetFirstSelectedItemPosition();

	TCHAR path[MAX_PATH]; // 바탕화면 경로
	SHGetSpecialFolderPath(NULL, path, CSIDL_DESKTOP, FALSE);
	CString folderPath = path;


	if (pos != NULL) {
		while (pos) {
			int nItem = m_list.GetNextSelectedItem(pos);
			m_list.f_info[nItem].select = true;
		}
	}

	if (folderDlg.DoModal() == IDOK) {
		folderName = folderDlg.folderName;
		folderPath += "\\";
		folderPath += folderName; // 생성될 폴더 경로 지정
		CreateFolder(folderPath); // 폴더 생성
		for (int i = 0; i < m_list.f_info.size(); i++) {
			if (m_list.f_info.at(i).select) {
				CString strTok, temp = m_list.f_info.at(i).beforePath, insert;
				int iSub = 0;
				while (AfxExtractSubString(strTok, temp, iSub++, '\\'))
				{
					if (strTok != _T("\r\n"))
						insert = strTok;
				}

				CString savPath = folderPath;
				savPath += "\\";
				savPath += insert;
				CopyFile(m_list.f_info.at(i).beforePath, savPath, TRUE);
				DeleteFile(m_list.f_info.at(i).beforePath);
				m_list.f_info.at(i).beforePath = savPath; //beforePath 유지하기 위해
			}
		}
		child_arr.clear(); //트리 자식들 지우기
		makeChangeDirectory(m_list.f_info); //바뀐거 트리에서 보여주기

	}
								  //	child_arr.clear(); //트리 자식들 지우기
								  //전부 리셋
								  //	m_list.f_info.clear();
	/*m_list.DeleteAllItems();
	m_change.DeleteAllItems();*/
}
void CFileManagerDlg::CreateFolder(CString csPath) // 폴더 생성 함수
{
	// UpdateData(TRUE);
	// csPath = m_csTopFolderName + csPath; 

	CString csPrefix(_T("")), csToken(_T(""));
	int nStart = 0, nEnd;
	while ((nEnd = csPath.Find('/', nStart)) >= 0)
	{
		CString csToken = csPath.Mid(nStart, nEnd - nStart);
		CreateDirectory(csPrefix + csToken, NULL);

		csPrefix += csToken;
		csPrefix += _T("/");
		nStart = nEnd + 1;
	}
	csToken = csPath.Mid(nStart);
	CreateDirectory(csPrefix + csToken, NULL);
}

void CFileManagerDlg::MoveDirectory(CString parm_src_path, CString parm_dest_path)
{
	CString src_file_path, dest_file_path;
	WIN32_FIND_DATA file_data;

	// 지정된 경로에 존재하는 모든 파일에 대한 목록을 구성하고 해당 정보의 핸들값을 얻는다.
	// 만약 해당 경로에 파일이나 자식 폴더가 존재하지 않는다면 INVALID_HANDLE_VALUE 값을
	// 반환한다. 그리고 이 함수가 성공적으로 목록을 구성한 경우에는 file_data 변수에
	// 구성된 목록중에서 첫번째 존재하는 파일의 정보를 넣어준다.
	HANDLE search_handle = FindFirstFile(parm_src_path + "*.*", &file_data);
	if (INVALID_HANDLE_VALUE != search_handle) {

		// 파일 목록을 성공적으로 구성한 경우..
		// 파일들이 복사될 폴더를 생성한다.
		::CreateDirectory(parm_dest_path, NULL);

		do {
			// 검색된 정보가 파일인지를 속성을 체크하여 확인한다.
			if (FILE_ATTRIBUTE_ARCHIVE & file_data.dwFileAttributes) {
				// 현재 정보가 파일인 경우, file_data.cFileName에 파일이름이 들어있다.

				// 원본 파일의 경로를 구성한다.
				src_file_path.Format(_T("%s%s"), parm_src_path, file_data.cFileName);
				AfxMessageBox(src_file_path);
				// 복사될 파일의 경로를 구성한다.
				dest_file_path.Format(_T("%s%s"), parm_dest_path, file_data.cFileName);

				// 구성된 두 경로를 이용하여 파일을 복사한다.
				CopyFile(src_file_path, dest_file_path, TRUE);

				// 원본 파일을 삭제한다.
				DeleteFile(src_file_path);
			}

			// 구성된 목록에서 다음 파일의 정보를 file_data에 복사하여 가져온다.
			// 더이상의 정보가 없다면 FindNextFile 함수는 0을 반환한다.
		} while (FindNextFile(search_handle, &file_data));

		// 검색을 위해 사용했던 핸들을 닫는다.
		FindClose(search_handle);
	}

	// 원본 파일이 들어있던 폴더도 삭제한다.
	//RemoveDirectory(parm_src_path);
}

void CFileManagerDlg::OnBnClickedButton3() //되돌리기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = 0; i < m_list.f_info.size(); i++) {
		if (m_list.f_info[i].changeCheck) {
			rename((CStringA)m_list.f_info[i].afterPath, (CStringA)m_list.f_info[i].beforePath);	
			m_list.f_info[i].changeCheck = false;
			/*m_list.f_info[i].beforePath = m_list.f_info[i].afterPath;*/
		}
	}
	child_arr.clear(); //트리 자식들 지우기
	makeDirectory(m_list.f_info); //바뀐거 트리에서 보여주기
	//	child_arr.clear(); //트리 자식들 지우기
	//전부 리셋
	//	m_list.f_info.clear();
	m_change.DeleteAllItems();
	for (int i = 0; i < m_list.f_info.size(); i++) {
		m_list.SetItemText(i, 0, m_list.f_info[i].beforeName);
		m_list.SetItemText(i, 1, m_list.f_info[i].strArtist);
		m_list.SetItemText(i, 2, m_list.f_info[i].strTitle);
		m_list.SetItemText(i, 3, m_list.f_info[i].strDate);
		m_list.SetItemText(i, 4, m_list.f_info[i].strLocation);
	}

}


void CFileManagerDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_list.UpdateThumbNail();
	child_arr.clear(); //트리 자식들 지우기
	m_list.f_info.clear();
	makeDirectory(m_list.f_info); //바뀐거 트리에서 보여주기
								  //	child_arr.clear(); //트리 자식들 지우기
								  //전부 리셋
								  //	m_list.f_info.clear();
	m_list.DeleteAllItems();
	m_change.DeleteAllItems();
}


void CFileManagerDlg::OnBnClickedbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CFileManagerDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(&rect);
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap *pOldBitmap = dc.SelectObject(&m_background);

	BITMAP bmap;
	m_background.GetBitmap(&bmap);
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, bmap.bmWidth, bmap.bmHeight, SRCCOPY);
	dc.SelectObject(pOldBitmap);

	return true;/*CDialog::OnEraseBkgnd(pDC);*/
}


void CFileManagerDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_helpDlg.DoModal();
}
