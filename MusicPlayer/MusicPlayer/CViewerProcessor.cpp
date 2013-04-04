/********************************************************************************
* @file		:	CViewerProcessor.h
* @summary	:	MusicPlayer视图控制类的实现。
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:48:05
* @history	:	
********************************************************************************/
#include "stdafx.h"
#include "CViewerProcessor.h"

/*****************************************************************************
* @func		:	CViewerProcessor
* @summary	:	有参の构造函数
* @in		:	HINSTANCE hInst : 实例句柄
*			:	HWND hWnd : 窗口实例
*			:	UINT message	: 消息
*			:	WPARAM wParam	: wParam
*			:	LPARAM lParam	: lParam
* @out		:	none
* @return	:	0
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:34:07
* @history	:	
******************************************************************************/
CViewerProcessor::CViewerProcessor(HINSTANCE hInst, HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	this->m_hWnd = hWnd;
	this->m_message = message;
	this->m_wParam = wParam;
	this->m_lParam = lParam;
	this->m_hInst = hInst;
}

/*****************************************************************************
* @func		:	CViewerProcessor
* @summary	:	无参の构造函数
* @in		:	void
* @out		:	none
* @return	:	0
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:34:07
* @history	:	
******************************************************************************/
CViewerProcessor::CViewerProcessor()
{
	this->m_hWnd = NULL;
	this->m_hWnd = NULL;
	this->m_message = NULL;
	this->m_wParam = NULL;
	this->m_lParam = NULL;
}

/*****************************************************************************
* @func		:	CViewerProcessor
* @summary	:	拷贝构造函数
* @in		:	const CViewerProcessor& obj	: 类的对象
* @out		:	none
* @return	:	0
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:35:16
* @history	:	
******************************************************************************/
CViewerProcessor::CViewerProcessor(const CViewerProcessor& obj)
{
	this->m_hInst = obj.m_hInst;
	this->m_hWnd = obj.m_hWnd;
	this->m_lParam = obj.m_lParam;
	this->m_message = obj.m_message;
	this->m_wParam = obj.m_wParam;
}

/*****************************************************************************
* @func		:	CreateButtonPreSong
* @summary	:	创建上一曲的Button
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateButtonPreSong()
{
	int iRet = FALSE;
	HWND hwndPreSong = CreateWindow(szButtonClass, 	// Button类名
	   szUPTitle, 									// 标题栏文本
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 		// 窗口样式
	   150,			 								// x
	   450, 										// y
	   100,											// 宽
	   30, 											// 高
	   m_hWnd, 										// 父窗口
	   (HMENU)BUTTON_PRESONG_ID, 					// 菜单
	   m_hInst, 									// 实例句柄
	   NULL);
	if (NULL != hwndPreSong)
	{
		iRet = TRUE;
	}
	return iRet;
}

/*****************************************************************************
* @func		:	CreateButtonNextSong
* @summary	:	创建下一曲的Button
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateButtonNextSong()
{
	int iRet = FALSE;
	HWND hwndNextSong = CreateWindow(szButtonClass, // Button类名
	   szDOWNTitle, 								// 标题栏文本
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 		// 窗口样式
	   550,			 								// x
	   450, 										// y
	   100,											// 宽
	   30, 											// 高
	   m_hWnd, 										// 父窗口
	   (HMENU)BUTTON_NEXTSONG_ID, 					// 菜单
	   m_hInst, 									// 实例句柄
	   NULL);										// lpParam
	if (NULL != hwndNextSong)
	{
		iRet = TRUE;
	}
	return iRet;
}

/*****************************************************************************
* @func		:	CreateButtonREW
* @summary	:	创建快退的Button
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateButtonREW()
{
	int iRet = FALSE;
	HWND hwndREW = CreateWindow(szButtonClass, 		// Button类名
	   szREWTitle, 									// 标题栏文本
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 		// 窗口样式
	   150,			 								// x
	   510, 										// y
	   100,											// 宽
	   30, 											// 高
	   m_hWnd, 										// 父窗口
	   (HMENU)BUTTON_REW_ID, 						// 菜单
	   m_hInst, 									// 实例句柄
	   NULL);										// lpParam

	if (NULL != hwndREW)
	{
		iRet = TRUE;
	}
	return iRet;
}

/*****************************************************************************
* @func		:	CreateButtonFF
* @summary	:	创建快进的Button
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateButtonFF()
{
	int iRet = FALSE;
	HWND hwndFF = CreateWindow(szButtonClass, 		// Button类名
	   szFFTitle, 									// 标题栏文本
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 		// 窗口样式
	   550,			 								// x
	   510, 										// y
	   100,											// 宽
	   30, 											// 高
	   m_hWnd, 										// 父窗口
	   (HMENU)BUTTON_FF_ID, 						// 菜单
	   m_hInst, 									// 实例句柄
	   NULL);

	if (NULL != hwndFF)
	{
		iRet = TRUE;
	}
	return iRet;
}

/*****************************************************************************
* @func		:	CreateButtonStop
* @summary	:	创建停止的Button
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateButtonStop()
{
	int iRet = FALSE;
	HWND hwndStop = CreateWindow(szButtonClass, 	// Button类名
	   szStopTitle, 								// 标题栏文本
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 		// 窗口样式
	   350,			 								// x
	   510, 										// y
	   100,											// 宽
	   30, 											// 高
	   m_hWnd, 										// 父窗口
	   (HMENU)BUTTON_STOP_ID, 						// 菜单
	   m_hInst, 									// 实例句柄
	   NULL);										// lpParam

	if (NULL != hwndStop)
	{
		iRet = TRUE;
	}

	return iRet;
}

/*****************************************************************************
* @func		:	CreateButtonPlayPause
* @summary	:	创建播放暂停的Button
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateButtonPlayPause()
{
	int iRet = FALSE;
	HWND hwndPlayPause = CreateWindow(szButtonClass,// Button类名
	   szPlayPauseTitle[0], 						// 标题栏文本
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 		// 窗口样式
	   350,			 								// x
	   450, 										// y
	   100,											// 宽
	   30, 											// 高
	   m_hWnd, 										// 父窗口
	   (HMENU)BUTTON_PLAYPAUSE_ID, 					// 菜单
	   m_hInst, 									// 实例句柄
	   NULL);										// lpParam

	if (NULL != hwndPlayPause)
	{
		iRet = TRUE;
	}

	return iRet;
}

/*****************************************************************************
* @func		:	CreateScrollList
* @summary	:	创建歌曲列表的滚动条
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateScrollList()
{
	int iRet = FALSE;
	HWND hwndScrollList = CreateWindow(szScrollBarClass,	// Button类名
		NULL,												// 标题栏文本
		WS_CHILD | WS_VISIBLE | SBS_VERT,					// 窗口样式
		60,													// x
		30,													// y
		40,													// 宽
		340,												// 高
		m_hWnd,												// 父窗口
		(HMENU)SCROLL_LIST_ID,								// 菜单
		m_hInst,											// 实例句柄
		NULL);												// lpParam

	if (NULL != hwndScrollList)
	{
		iRet = TRUE;
	}
	return iRet;
}

/*****************************************************************************
* @func		:	CreateScrollTime
* @summary	:	创建歌曲播放时间进度条
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateScrollTime()
{
	int iRet = FALSE;
	HWND hwndScrollTime = CreateWindow(szScrollBarClass,	// Button类名
		NULL,												// 标题栏文本
		WS_CHILD | WS_VISIBLE | SBS_HORZ,					// 窗口样式
		110,												// x
		390,												// y
		570,												// 宽
		10,													// 高
		m_hWnd,												// 父窗口
		(HMENU)SCROLL_TIME_ID,								// 菜单
		m_hInst,											// 实例句柄
		NULL												// lpParam
		);
	if (NULL != hwndScrollTime)
	{
		iRet = TRUE;
	}

	//EnableScrollBar(hwndScrollTime, SB_CTL, ESB_DISABLE_BOTH);
	return iRet;
}

/*****************************************************************************
* @func		:	CreateScrollVolume
* @summary	:	创建声音大小的滚动条
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateScrollVolume()
{
	int iRet = FALSE;
	HWND hwndScrollVolume = CreateWindow(szScrollBarClass,	// Button类名
		NULL,												// 标题栏文本
		WS_CHILD | WS_VISIBLE | SBS_VERT,					// 窗口样式
		700,												// x
		30,													// y
		40,													// 宽
		340,												// 高
		m_hWnd,												// 父窗口
		(HMENU)SCROLL_VOLUME_ID,							// 菜单
		m_hInst,											// 实例句柄
		NULL												// lpParam
		);

	if (NULL != hwndScrollVolume)
	{
		iRet = TRUE;
	}
	return iRet;
}

/*****************************************************************************
* @func		:	CreateListTable
* @summary	:	创建歌曲播放列表
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateListTable()
{
	int iRet = FALSE;

	HWND hwndListTable = CreateWindow(szListBox,			// Button类名
		NULL,												// 标题栏文本
		WS_CHILD | WS_VISIBLE | LBS_USER,					// 窗口样式
		120,												// x
		30,													// y
		550,												// 宽
		340,												// 高
		m_hWnd,												// 父窗口
		(HMENU)LIST_TABLE_ID,								// 菜单
		m_hInst,											// 实例句柄
		NULL												// lpParam
		);

	if (NULL != hwndListTable)
	{
		iRet = TRUE;
	}
	return iRet;
}

/*****************************************************************************
* @func		:	CreateListPath
* @summary	:	创建显示当前播放的歌曲的路径
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 创建成功
*			:	FALSE	: 创建失败
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
int CViewerProcessor::CreateListPath()
{
	int iRet = FALSE;

	HWND hwndListPath = CreateWindow(szStaticClass,			// Button类名
		NULL,												// 标题栏文本
		WS_CHILD | WS_VISIBLE | SS_LEFT,					// 窗口样式
		120,												// x
		10,													// y
		550,												// 宽
		20,													// 高
		m_hWnd,												// 父窗口
		(HMENU)STATIC_LISTPATH_ID,							// 菜单
		m_hInst,											// 实例句柄
		NULL												// lpParam
		);

	if (NULL != hwndListPath)
	{
		iRet = TRUE;
	}
	return iRet;
}

/*****************************************************************************
* @func		:	ShowPlayOrPause
* @summary	:	显示播放暂停的文言
* @in		:	bool bPlay = true : 暂停
*			:	bool bPlay = false : 播放
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:43:03
* @history	:	
******************************************************************************/
void CViewerProcessor::ShowPlayOrPause(bool bPlay)
{
	HWND hwndChild = GetDlgItem(m_hWnd, BUTTON_PLAYPAUSE_ID);

	if (bPlay)
	{
		SetWindowText(hwndChild, szPlayPauseTitle[1]);
	}
	else
	{
		SetWindowText(hwndChild, szPlayPauseTitle[0]);
	}

	return ;
}

/*****************************************************************************
* @func		:	InitListTable
* @summary	:	初始化歌曲播放列表
* @in		:	void
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
void CViewerProcessor::InitListTable()
{
	TCHAR szBuffer[MAX_LOADSTRING + 1];
	HWND hwndListPath = GetDlgItem(m_hWnd, STATIC_LISTPATH_ID);
	GetCurrentDirectory(lstrlen(szBuffer), szBuffer);
	SetWindowText(hwndListPath, szBuffer);

	HWND hwndChild = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	SendMessage(hwndChild, LB_DIR, DDL_READWRITE | DDL_DIRECTORY, (LPARAM)TEXT("*.MP3"));
	SendMessage(hwndChild, LB_DIR, DDL_READWRITE | DDL_DIRECTORY, (LPARAM)TEXT("*.WAV"));
	SendMessage(hwndChild, LB_SETCURSEL, 0, TRUE);

	return ;
}

/*****************************************************************************
* @func		:	ShowListTable
* @summary	:	更新歌曲播放列表
* @in		:	void
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:36:36
* @history	:	
******************************************************************************/
void CViewerProcessor::UpdateListTable()
{
	HWND hwndChild = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	SendMessage(hwndChild, LB_RESETCONTENT, 0, 0);
	SendMessage(hwndChild, LB_DIR, DDL_READWRITE, (LPARAM)TEXT("*.*"));

	return ;
}

/*****************************************************************************
* @func		:	InitWindows
* @summary	:	窗口初始化。
* @in		:	void
* @out		:	none
* @return	:	TRUE	: 各窗口创建成功
*			:	FALSE	: 窗口创建不成功
* @author	:	Li Jiachun
* @time		:	2013-3-24 21:02:57
* @history	:	
******************************************************************************/
int CViewerProcessor::InitWindows()
{
	if (CreateButtonFF()		&& 
		CreateButtonNextSong()	&& 
		CreateButtonPlayPause() && 
		CreateButtonPreSong()	&& 
		CreateButtonREW()		&& 
		CreateButtonStop()		&& 
		CreateListTable()		&& 
		CreateScrollList()		&& 
		CreateScrollTime()		&& 
		CreateScrollVolume()	&&
		CreateListPath())
	{
		return TRUE;
	}

	return FALSE;
}

/*****************************************************************************
* @func		:	GetSongsCount
* @summary	:	获取列表中所有歌曲的数目
* @in		:	void
* @out		:	none
* @return	:	int iNo	: 歌曲的数目
* @author	:	Li Jiachun
* @time		:	2013-3-30 11:30:04
* @history	:	
******************************************************************************/
int CViewerProcessor::GetSongsCount()
{
	int iNo = 0;
	HWND hwndListTable = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	iNo = SendMessage(hwndListTable, LB_GETCOUNT, 0, 0);
	return iNo;
}

/*****************************************************************************
* @func		:	GetListTopIndex
* @summary	:	获取列表中第一条的索引值
* @in		:	void
* @out		:	none
* @return	:	int iIndex	: 列表中第一条的索引值
* @author	:	Li Jiachun
* @time		:	2013-3-30 11:30:04
* @history	:	
******************************************************************************/
int CViewerProcessor::GetListTopIndex()
{
	int iIndex = 0;
	HWND hwndListTable = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	iIndex = SendMessage(hwndListTable, LB_GETTOPINDEX, 0, 0);
	return iIndex;
}

/*****************************************************************************
* @func		:	SetListTopIndex
* @summary	:	设置列表中第一条的索引值
* @in		:	int iIndex : 将要设置的列表中第一条的索引值
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-3-30 11:30:04
* @history	:	
******************************************************************************/
void CViewerProcessor::SetListTopIndex(int iIndex)
{
	HWND hwndListTable = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	iIndex = SendMessage(hwndListTable, LB_SETTOPINDEX, iIndex, 0);
	return ;
}

/*****************************************************************************
* @func		:	InitScrollList
* @summary	:	初始化列表滚动条
* @in		:	void
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-3-30 11:30:04
* @history	:	
******************************************************************************/
void CViewerProcessor::InitScrollList()
{
	TEXTMETRIC tm;
	RECT rect;
	HWND hwndScrollList = GetDlgItem(m_hWnd, SCROLL_LIST_ID);
	HDC hdc = GetDC(hwndScrollList);
	GetWindowRect(hwndScrollList, &rect);
	GetTextMetrics(hdc, &tm);
	int ixChar = tm.tmWeight;
	int iyChar = tm.tmHeight;
	int iMax = GetSongsCount() - (rect.bottom - rect.top) / iyChar;

	iMax = max(0, iMax);

	SetScrollRange(hwndScrollList, SB_CTL, 0, iMax, FALSE);
	SetScrollPos(hwndScrollList, SB_CTL, GetListTopIndex(), TRUE);
	ReleaseDC(m_hWnd, hdc);
	return ;
}

/*****************************************************************************
* @func		:	UpdateScrollList
* @summary	:	初始化列表滚动条
*			:	WndProcのWM_VSCROLL消息处用
* @in		:	void
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-3-30 11:30:04
* @history	:	
******************************************************************************/
void CViewerProcessor::UpdateScrollList()
{
	if (SCROLL_LIST_ID != GetWindowLong((HWND)m_lParam, GWL_ID))
	{
		return ;
	}
	static int iIndex = 0;
	switch(LOWORD(m_wParam))
	{
	case SB_PAGEDOWN:
		iIndex++;
		break;
	case SB_PAGEUP:
		iIndex--;
		break;
	case SB_LINEDOWN:
		iIndex++;
		break;
	case SB_LINEUP:
		iIndex--;
		break;
	case SB_TOP:
		iIndex = 0;
		break;
	case SB_BOTTOM:
		iIndex = GetSongsCount();
		break;
	case SB_THUMBTRACK:
	case SB_THUMBPOSITION:
		iIndex = HIWORD(m_wParam);
		break;
	default:
		break;
	}
	SetScrollPos((HWND)m_lParam, SB_CTL, iIndex, TRUE);
	SetListTopIndex(iIndex);
	return ;
}

/*****************************************************************************
* @func		:	GetCurrentSelectListName
* @summary	:	获取当前选中的歌曲名
* @in		:	TCHAR* szCurrentSelectName : 当前选中的歌曲名
* @out		:	none
* @return	:	int iLength : 歌曲名的长度
* @author	:	Li Jiachun
* @time		:	2013-3-31 19:37:18
* @history	:	
******************************************************************************/
int CViewerProcessor::GetCurrentSelectListName(TCHAR* szCurrentSelectName)
{
	HWND hwndListTable = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	int iCurIndex = SendMessage(hwndListTable, LB_GETCURSEL, 0, 0);
	int iLength = SendMessage(hwndListTable, LB_GETTEXT, iCurIndex, (LPARAM)szCurrentSelectName);
	return iLength;
}

/*****************************************************************************
* @func		:	UpdateScrollListByMouse
* @summary	:	鼠标滚轮更新播放列表
* @in		:	int iDeltaPerLine : 滚轮没滚动一下是的滚动大小
* @out		:	none
* @return	:	NULL	: 有消息处理の情况
*			:	DefWindowProc	: 没有消息对应的处理
* @author	:	Li Jiachun
* @time		:	2013-3-31 19:39:06
* @history	:	
******************************************************************************/
LRESULT CViewerProcessor::UpdateScrollListByMouse(int iDeltaPerLine)
{
	if (0 == iDeltaPerLine)
	{
		return DefWindowProc(m_hWnd, m_message, m_wParam, m_lParam);
	}

	HWND hwndScrollList = GetDlgItem(m_hWnd, SCROLL_LIST_ID);

	int iAccumDelta = (short)HIWORD(m_wParam);

	// 向下滚动鼠标
	while (iAccumDelta >= iDeltaPerLine)
	{
		SendMessage(m_hWnd, WM_VSCROLL, SB_LINEUP, (LPARAM)hwndScrollList);
		iAccumDelta -= iDeltaPerLine;
	}

	// 向上滚动鼠标
	while(iAccumDelta <= -iDeltaPerLine)
	{
		SendMessage(m_hWnd, WM_VSCROLL, SB_LINEDOWN, (LPARAM)hwndScrollList);
		iAccumDelta += iDeltaPerLine;
	}
	return NULL;
}

/*****************************************************************************
* @func		:	UpdateRectBeginTime
* @summary	:	更新开始时间区域的时间显示
* @in		:	TCHAR szBeginTime[] : 开始时间
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
void CViewerProcessor::UpdateRectBeginTime(TCHAR szBeginTime[])
{
	HDC hdc = GetDC(m_hWnd);
	TextOut(hdc, rectBegin.left, rectBegin.top, szBeginTime, lstrlen(szBeginTime));
	ReleaseDC(m_hWnd, hdc);
	return ;
}

/*****************************************************************************
* @func		:	UpdateRectTotalTime
* @summary	:	更新总时间的显示
* @in		:	TCHAR szTotalTime[] : 总时间
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
void CViewerProcessor::UpdateRectTotalTime(TCHAR szTotalTime[])
{
	// 更新总时间时会把当前播放到的时间更新掉
	//UpdateRectCurreTime(TEXT("00:00:000"));
	HDC hdc = GetDC(m_hWnd);
	TextOut(hdc, rectEnd.left, rectEnd.top, szTotalTime, lstrlen(szTotalTime));
	ReleaseDC(m_hWnd, hdc);
	return ;
}

/*****************************************************************************
* @func		:	UpdateRectCurreTime
* @summary	:	更新当前时间的显示
* @in		:	TCHAR szCurrentTime[] : 当前时间
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
void CViewerProcessor::UpdateRectCurreTime(TCHAR szCurrentTime[])
{
	HDC hdc = GetDC(m_hWnd);
	TextOut(hdc, rectCurrent.left, rectCurrent.top, szCurrentTime, lstrlen(szCurrentTime));
	ReleaseDC(m_hWnd, hdc);
	return ;
}

/*****************************************************************************
* @func		:	InvalidateRectCurrentTime
* @summary	:	是当前时间区域块无效
* @in		:	void
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
void CViewerProcessor::InvalidateRectCurrentTime()
{
	InvalidateRect(m_hWnd, &rectCurrent, TRUE);
	return ;
}

/*****************************************************************************
* @func		:	InvalidateRectTotalTime
* @summary	:	使总时间区域块无效
* @in		:	void
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
void CViewerProcessor::InvalidateRectTotalTime()
{
	InvalidateRectCurrentTime();
	InvalidateRect(m_hWnd, &rectEnd, TRUE);
	return ;
}

/*****************************************************************************
* @func		:	InitScrollTime
* @summary	:	初始化时间滚动条
* @in		:	void
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
void CViewerProcessor::InitScrollTime(int iTotalTime)
{
	HWND hwndScrollTime = GetDlgItem(m_hWnd, SCROLL_TIME_ID);

	SetScrollRange(hwndScrollTime, SB_CTL, 0, iTotalTime, FALSE);
	SetScrollPos(hwndScrollTime, SB_CTL, 0, TRUE);
	return ;
}

/*****************************************************************************
* @func		:	GetPreviousSongName
* @summary	:	获取上一首歌的名字
* @in		:	TCHAR* szPreSongName : 
* @out		:	TCHAR* szPreSongName : 获取上一首歌的名字并返回
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
int CViewerProcessor::GetPreviousSongName(TCHAR* szPreSongName)
{
	HWND hwndListTable = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	int iCurIndex = SendMessage(hwndListTable, LB_GETCURSEL, 0, 0);
	int iPreSongIndex = max(0, (iCurIndex - 1));
	int iLength = SendMessage(hwndListTable, LB_GETTEXT, iPreSongIndex, (LPARAM)szPreSongName);
	return iLength;
}

/*****************************************************************************
* @func		:	GetPreviousSongName
* @summary	:	获取上一首歌的名字
* @in		:	TCHAR* szNextName : 
* @out		:	TCHAR* szNextName : 获取下一首歌的名字并返回
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
int CViewerProcessor::GetNextSongName(TCHAR* szNextName)
{
	HWND hwndListTable = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	int iCurIndex = SendMessage(hwndListTable, LB_GETCURSEL, 0, 0);
	int iNextSongIndex = min(GetSongsCount(), (iCurIndex + 1));
	int iLength = SendMessage(hwndListTable, LB_GETTEXT, iNextSongIndex, (LPARAM)szNextName);
	return iLength;
}

/*****************************************************************************
* @func		:	SetPreviousIndex
* @summary	:	将当前的歌曲选择项设为上一首歌
* @in		:	void
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
void CViewerProcessor::SetPreviousIndex()
{
	TCHAR szSelectName[MAX_LOADSTRING + 1] = L"";
	HWND hwndListTable = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	int iCurIndex = SendMessage(hwndListTable, LB_GETCURSEL, 0, 0);
	iCurIndex--;
	SendMessage(hwndListTable, LB_GETTEXT, iCurIndex, (LPARAM)szSelectName);
	SendMessage(hwndListTable, LB_SELECTSTRING, iCurIndex, (LPARAM)szSelectName);
	return ;
}

/*****************************************************************************
* @func		:	SetPreviousIndex
* @summary	:	将当前的歌曲选择项设为下一首歌
* @in		:	void
* @out		:	none
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 21:53:53
* @history	:	
******************************************************************************/
void CViewerProcessor::SetNextIndex()
{
	TCHAR szSelectName[MAX_LOADSTRING + 1] = L"";
	HWND hwndListTable = GetDlgItem(m_hWnd, LIST_TABLE_ID);
	int iCurIndex = SendMessage(hwndListTable, LB_GETCURSEL, 0, 0);
	iCurIndex++;
	SendMessage(hwndListTable, LB_GETTEXT, iCurIndex, (LPARAM)szSelectName);
	SendMessage(hwndListTable, LB_SELECTSTRING, iCurIndex, (LPARAM)szSelectName);
	return ;
}

void CViewerProcessor::InitScrollVolume(unsigned int iVolume)
{
	HWND hwndScrollVolume = GetDlgItem(m_hWnd, SCROLL_VOLUME_ID);
	SetScrollRange(hwndScrollVolume, SB_CTL, 0, MAX_PLAYER_VOLUME, FALSE);
	SetScrollPos(hwndScrollVolume, SB_CTL, MAX_PLAYER_VOLUME - iVolume, TRUE);
	return ;
}

void CViewerProcessor::UpdateScrollVolume(unsigned int& iVolume)
{
	if (SCROLL_VOLUME_ID != GetWindowLong((HWND)m_lParam, GWL_ID))
	{
		return ;
	}
	static unsigned int iIndex = iVolume;
	switch(LOWORD(m_wParam))
	{
	case SB_PAGEDOWN:
		iIndex--;
		break;
	case SB_PAGEUP:
		iIndex++;
		break;
	case SB_LINEDOWN:
		iIndex--;
		break;
	case SB_LINEUP:
		iIndex++;
		break;
	case SB_TOP:
		iIndex = MAX_PLAYER_VOLUME;
		break;
	case SB_BOTTOM:
		iIndex = 0;
		break;
	case SB_THUMBTRACK:
	case SB_THUMBPOSITION:
		iIndex = MAX_PLAYER_VOLUME - HIWORD(m_wParam);
		break;
	default:
		break;
	}
	SetScrollPos((HWND)m_lParam, SB_CTL, MAX_PLAYER_VOLUME - iIndex, TRUE);
	iVolume = iIndex;
	return ;
}

void CViewerProcessor::UpdateScrollTime(unsigned int iTime)
{
	HWND hwndScrollTime = GetDlgItem(m_hWnd, SCROLL_TIME_ID);
	SetScrollPos(hwndScrollTime, SB_CTL, iTime, TRUE);
	return ;
}