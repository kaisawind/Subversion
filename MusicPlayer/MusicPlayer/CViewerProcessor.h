/********************************************************************************
* @file		:	CViewerProcessor.h
* @summary	:	MusicPlayer视图控制类。
* @author	:	Li Jiachun
* @time		:	2013-3-29 20:48:05
* @history	:	
********************************************************************************/
#ifndef __CVIEWERPROCESSOR_H__
#define __CVIEWERPROCESSOR_H__

#define MAX_LOADSTRING 100										// 最大字符数目
#define LBS_USER	(LBS_NOTIFY | LBS_SORT | WS_BORDER)			// 去掉自带的滚动条
#define MAX_PLAYER_VOLUME	100									// 设置最大的播放器声音

// 子窗口ID 
enum enumWindowID_em
{
	BUTTON_REW_ID = 1,
	BUTTON_FF_ID,
	BUTTON_PLAYPAUSE_ID,
	BUTTON_STOP_ID,
	BUTTON_PRESONG_ID,
	BUTTON_NEXTSONG_ID,
	SCROLL_LIST_ID,
	SCROLL_VOLUME_ID,
	SCROLL_TIME_ID,
	LIST_TABLE_ID,
	STATIC_LISTPATH_ID
};


const TCHAR szButtonClass[]	= TEXT("button");						// Button 类名
const TCHAR szScrollBarClass[] = TEXT("scrollbar");					// ScrollBar 类名
const TCHAR szListBox[] = TEXT("listbox");							// ListBox 类名
const TCHAR szStaticClass[] = TEXT("static");						// 静态类

const TCHAR szREWTitle[] = TEXT("快退");							// 快退
const TCHAR szFFTitle[]	= TEXT("快进");								// 快进
const TCHAR szPlayPauseTitle[2][3] = {TEXT("播放"), TEXT("暂停")};	// 播放暂停
const TCHAR szStopTitle[] = TEXT("停止");							// 停止
const TCHAR szUPTitle[] = TEXT("上一曲");							// 上一曲
const TCHAR szDOWNTitle[] = TEXT("下一曲");							// 下一曲

const RECT rectBegin = {110, 410, 190, 430};
const RECT rectEnd = {610, 410, 690, 430};
const RECT rectCurrent = {360, 410, 440, 430};

class CViewerProcessor
{
public: // 共有成员函数
	CViewerProcessor();
	CViewerProcessor(HINSTANCE , HWND , UINT , WPARAM , LPARAM );
	CViewerProcessor(const CViewerProcessor&);	
	void ShowPlayOrPause(bool );
	void InitListTable();
	void UpdateListTable();
	int InitWindows();
	int GetSongsCount();
	int GetListTopIndex();
	void SetListTopIndex(int );
	void InitScrollList();
	void UpdateScrollList();
	int GetCurrentSelectListName(TCHAR*);
	LRESULT UpdateScrollListByMouse(int );
	void UpdateRectBeginTime(TCHAR []);
	void UpdateRectTotalTime(TCHAR []);
	void UpdateRectCurreTime(TCHAR []);
	void InvalidateRectCurrentTime();
	void InvalidateRectTotalTime();
	void InitScrollTime(int );
	int GetPreviousSongName(TCHAR*);
	int GetNextSongName(TCHAR*);
	void SetPreviousIndex();
	void SetNextIndex();
	void InitScrollVolume(unsigned int );
	void UpdateScrollVolume(unsigned int& );
	void UpdateScrollTime(unsigned int);

private: // 私有成员函数
	int CreateButtonPreSong();
	int CreateButtonNextSong();
	int CreateButtonREW();
	int CreateButtonFF();
	int CreateButtonStop();
	int CreateButtonPlayPause();
	int CreateScrollList();
	int CreateScrollTime();
	int CreateScrollVolume();
	int CreateListTable();
	int CreateListPath();

private: // 私有成员变量
	HINSTANCE m_hInst;
	HWND m_hWnd;
	UINT m_message;
	WPARAM m_wParam;
	LPARAM m_lParam;
};
#endif // __CVIEWERPROCESSOR_H__