/********************************************************************************
* @file		:	MusicPlayer.h
* @summary	:	MusicPlayer的主头文件
* @author	:	Li Jiachun
* @time		:	2013-3-24 13:26:03
* @history	:	
********************************************************************************/
#ifndef __MUSICPLAYER_H__
#define __MUSICPLAYER_H__
#include "resource.h"
#include "CMusicProcessor.h"
#include "CViewerProcessor.h"
#include "CFilesProcessor.h"

#define MusicPlayer CMusicProcessor::getInstance()
#define FilesProc CFilesProcessor::getInstance()
#define USER_MOUSEHWHEEL	(0x020A)

enum enum_Timer_em
{
	TIMER_TIMERPROC_ID = 1
};

/********************************************************************************
* USER_MUSICPLAYERWINDOW : 自定义MusicPlayer窗口格式
* WS_OVERLAPPED : 标题条和边框
* WS_CAPTION : 标题框
* WS_SYSMENU : 标题条上带有窗口菜单
* WS_MINIMIZEBOX : 允许最小化
********************************************************************************/
#define USER_MUSICPLAYERWINDOW (WS_OVERLAPPED		| \
								WS_CAPTION			| \
								WS_SYSMENU			| \
								WS_MINIMIZEBOX)

// 全局变量:
HINSTANCE hInst;												// 当前实例
TCHAR szTitle[MAX_LOADSTRING];									// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];							// 主窗口类名

const int ixClient = 800;										// 客户区宽度
const int iyClient = 600;										// 客户区高度

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
int CDECL MessageBoxPrintf(TCHAR* szCaption, TCHAR* szFormate, ...);
LRESULT MenuProc(HWND, UINT, WPARAM, LPARAM);
LRESULT ButtonProc(HWND, UINT, WPARAM, LPARAM);
LRESULT ListBoxProc(HWND, UINT, WPARAM, LPARAM);
int GetMouseDeltaPerLine();
void CALLBACK TimerProc(HWND, UINT, UINT, DWORD);

#endif // __MUSICPLAYER_H__