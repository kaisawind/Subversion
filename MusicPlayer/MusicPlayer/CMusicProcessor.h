/********************************************************************************
* @file		:	CMusicProcessor.h
* @summary	:	对libzplay开源库进行封转，MusicPlayer动作的处理类
* @author	:	Li Jiachun
* @time		:	2013-3-24 14:53:06
* @history	:	
********************************************************************************/

#ifndef __CMUSICPROCESSOR_H__
#define __CMUSICPROCESSOR_H__
#include "libzplay.h"
#pragma comment(lib, "libzplay.lib")
using namespace libZPlay;

#define COPY_CONSTRUCTOR_ASSIGNMENT(type) \
	type(const type&);\
	void operator=(const type)

#define MAX_LOADSTRING 100						// 最大字符数目

// 支持的文件格式种类
enum enumMusicFormat_em
{
	UNKNOWN = 0,
	MP3,
	OGG,
	WAV,
	PCM,
	FLAC,
	FLACOGG,
	AC3,
	AACADTS,
	WAVEIN,
	AUDIODETECT = 1000
};

// 播放状态
struct tagPlayStatus_t
{
	bool bFileOpen;								// 是否有文件打开
	bool bPlay;									// 当前是否为播放状态
	TCHAR szCurrentTime[MAX_LOADSTRING + 1];	// 当前歌曲播放的时间
	unsigned int iLeftVolume;					// 当前播放器的左声音
	unsigned int iRightVolume;					// 获取播放器的右声音
};

// 文件状态
struct tagFileStatus_t
{
	enumMusicFormat_em nformat;				// Music的编码格式
	TCHAR szFileName[MAX_LOADSTRING + 1];	// 文件名
	TCHAR szTotalTime[MAX_LOADSTRING + 1];	// 歌曲播放总时间
};

class CMusicProcessor
{
	// 共有成员函数
public:
	static CMusicProcessor* getInstance(void );
	int OpenFile(const TCHAR*);
	TCHAR* GetZPlayError();
	int MusicPlay();
	int MusicPause();
	int MusicStop();
	int MusicClose();
	int NewMusicPlay(const TCHAR*);
	void SetMusicCurrentTime();
	tagPlayStatus_t* GetPlayStatus();
	tagFileStatus_t* GetFileStatus();
	int GetStatus();
	void Seek(int );
	void SetPlayerVolume(int );
	unsigned int GetTotalMilliSecond();
	unsigned int GetCurrentMilliSecond();

	// 私有数据成员
private:
	static ZPlay *player;
	tagFileStatus_t FileStatus;
	tagPlayStatus_t PlayStatus;

	// 私有函数成员
private:
	CMusicProcessor();
	COPY_CONSTRUCTOR_ASSIGNMENT(CMusicProcessor);
	void SetMusicTotalTime();
};	// CMusicProcessor

#endif // __CMUSICPROCESSOR_H__