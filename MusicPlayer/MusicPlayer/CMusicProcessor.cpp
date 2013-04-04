/*******************************************************************************
* @file		:	CMusicProcessor.cpp
* @summary	:	对libzplay开源库进行封转，MusicPlayer动作的处理类
* @author	:	Li Jiachun
* @time		:	2013-3-24 14:53:06
* @history	:	
********************************************************************************/

#include "stdafx.h"
#include "CMusicProcessor.h"

// 私有静态数据成员初始化
ZPlay* CMusicProcessor::player = CreateZPlay();

/*****************************************************
*	@func	:	getInstance
*	@summary:	单例模式实现
*	@in		:	void
*	@out	:	none
*	@return	:	CMusicProcessor*
*	@author	:	DaPPer
*	@time	:	2013-3-24 15:08:21
*	@history:	
******************************************************/
CMusicProcessor* CMusicProcessor::getInstance(void )
{
	static CMusicProcessor obj;
	return &obj;
}

/*****************************************************
*	@func	:	CMusicProcessor
*	@summary:	构造函数
*	@in		:	void
*	@out	:	none
*	@return	:	none
*	@author	:	DaPPer
*	@time	:	2013-3-24 15:14:37
*	@history:	
******************************************************/
CMusicProcessor::CMusicProcessor()
{
	// 文件状态初始化
	FileStatus.nformat = UNKNOWN;
	lstrcpyW(FileStatus.szFileName, TEXT(""));
	lstrcpyW(FileStatus.szTotalTime, TEXT("00:00:000"));

	// 播放状态初始化
	PlayStatus.bFileOpen = false;
	PlayStatus.bPlay = false;
	lstrcpyW(PlayStatus.szCurrentTime, TEXT("00:00:000"));
	player->GetPlayerVolume(&(PlayStatus.iLeftVolume), &(PlayStatus.iRightVolume));
}

/*****************************************************
*	@func	:	OpenFile(TCHAR* , enumMusicFormat_em )
*	@summary:	打开音乐文件
*	@in		:	TCHAR* szFileName	: 要打开的文件名
*			:	enumMusicFormat_em nFormate	: 要打开的文件格式
*	@out	:	none
*	@return	:	TRUE : ALL OK
*			:	FALSE : 打开文件失败
*	@author	:	DaPPer
*	@time	:	2013-3-24 15:46:31
*	@history:	
******************************************************/
int CMusicProcessor::OpenFile(const TCHAR* szFileName)
{
	if (NULL == player)
	{
		return FALSE;
	}
	int iRet = FALSE;

	lstrcpyW(FileStatus.szFileName, szFileName);
	int nFormat = player->GetFileFormatW(szFileName);
	if(nFormat == sfUnknown)
	{
	  return FALSE;
	}

	iRet = player->OpenFileW(FileStatus.szFileName, (TStreamFormat)nFormat);

	if (TRUE == iRet)
	{
		PlayStatus.bFileOpen = true;
		FileStatus.nformat = (enumMusicFormat_em)nFormat;
		SetMusicTotalTime();
	}
	else
	{
		PlayStatus.bFileOpen = false;
	}
	return iRet;
}

/*****************************************************
*	@func	:	GetZPlayError()
*	@summary:	获取ZPlay的错误
*	@in		:	void
*	@out	:	none
*	@return	:	ZPlay的错误信息
*	@author	:	DaPPer
*	@time	:	2013-3-24 15:48:25
*	@history:	
******************************************************/
TCHAR* CMusicProcessor::GetZPlayError()
{
	if (NULL == player)
	{
		return NULL;
	}
	return player->GetErrorW();
}

/*****************************************************
*	@func	:	MusicPlay()
*	@summary:	播放音乐文件
*	@in		:	void
*	@out	:	none
*	@return	:	TRUE : ALL OK
*			:	FALSE : 音乐播放失败
*	@author	:	DaPPer
*	@time	:	2013-3-24 16:06:55
*	@history:	
******************************************************/
int CMusicProcessor::MusicPlay()
{
	if (NULL == player)
	{
		return FALSE;
	}

	// 循环10次，打不开就不打了
	int iCount = 0;
	while (false == PlayStatus.bFileOpen)
	{
		iCount++;
		if (OpenFile(FileStatus.szFileName))
		{
			break;
		}
		
		if (10 == iCount)
		{
			break;
		}
	}

	int iRet = FALSE;

	if (true == PlayStatus.bFileOpen)
	{
		iRet = player->Play();

		if (TRUE == iRet)
		{
			PlayStatus.bPlay = true;
		}
	}

	return iRet;
}

/*****************************************************
*	@func	:	MusicPause()
*	@summary:	暂停音乐文件播放
*	@in		:	void
*	@out	:	none
*	@return	:	TRUE : ALL OK
*			:	FALSE : 音乐播放失败
*	@author	:	DaPPer
*	@time	:	2013-3-24 16:06:55
*	@history:	
******************************************************/
int CMusicProcessor::MusicPause()
{
	if (NULL == player)
	{
		return FALSE;
	}

	int iRet = FALSE;

	if (true == PlayStatus.bPlay)
	{
		iRet = player->Pause();
		if (TRUE == iRet)
		{
			PlayStatus.bPlay = false;
		}
	}
	else
	{
		iRet = MusicPlay();
	}	

	return iRet;

}

/*****************************************************
*	@func	:	MusicStop()
*	@summary:	停止播放音乐文件
*	@in		:	void
*	@out	:	none
*	@return	:	TRUE : ALL OK
*			:	FALSE : 音乐停止播放失败
*	@author	:	DaPPer
*	@time	:	2013-3-24 19:11:03
*	@history:	
******************************************************/
int CMusicProcessor::MusicStop()
{
	// 文件没打开直接返回
	if ((false == PlayStatus.bFileOpen) || (NULL == player))
	{
		return FALSE;
	}

	int iRet = TRUE;

	iRet = player->Stop();

	if (TRUE == iRet)
	{
		PlayStatus.bPlay = false;
	}

	return iRet;
}

/*****************************************************
*	@func	:	GetPlayStatus()
*	@summary:	获取播放状态
*	@in		:	void
*	@out	:	none
*	@return	:	PlayStatus : 播放状态结构体
*	@author	:	DaPPer
*	@time	:	2013-3-24 22:34:41
*	@history:	
******************************************************/
tagPlayStatus_t* CMusicProcessor::GetPlayStatus()
{
	return &PlayStatus;
}

/*****************************************************
*	@func	:	GetFileStatus()
*	@summary:	获取播放状态
*	@in		:	void
*	@out	:	none
*	@return	:	FileStatus : 文件状态结构体
*	@author	:	DaPPer
*	@time	:	2013-3-24 22:34:41
*	@history:	
******************************************************/
tagFileStatus_t* CMusicProcessor::GetFileStatus()
{
	return &FileStatus;
}

/*****************************************************
*	@func	:	MusicClose()
*	@summary:	关闭音乐播放文件，清空所有数据
*	@in		:	void
*	@out	:	none
*	@return	:	TRUE : ALL OK
*			:	FALSE : 音乐停止播放失败
*	@author	:	DaPPer
*	@time	:	2013-3-30 16:02:21
*	@history:	
******************************************************/
int CMusicProcessor::MusicClose()
{
	int iRet = FALSE;
	iRet = player->Close();

	if (iRet)
	{
		PlayStatus.bFileOpen = false;
		PlayStatus.bPlay = false;
	}
	return iRet;
}

/*****************************************************
*	@func	:	NewMusicPlay
*	@summary:	播放一首新的歌曲所需要的处理
*	@in		:	const TCHAR* szFileName	: 要播放的歌曲的名字
*	@out	:	none
*	@return	:	TRUE : ALL OK
*			:	FALSE : 音乐播放失败
*	@author	:	DaPPer
*	@time	:	2013-3-31 20:17:40
*	@history:	
******************************************************/
int CMusicProcessor::NewMusicPlay(const TCHAR* szFileName)
{
	int iRet = FALSE;
	if (MusicClose()			&&
		OpenFile(szFileName)	&&
		MusicPlay())
	{
		iRet = TRUE;
	}

	return iRet;
}

/*****************************************************
*	@func	:	SetMusicTotalTime
*	@summary:	设置音乐的总时间
*	@in		:	void
*	@out	:	none
*	@return	:	void
*	@author	:	DaPPer
*	@time	:	2013-4-3 22:03:40
*	@history:	
******************************************************/
void CMusicProcessor::SetMusicTotalTime()
{
	TCHAR szTimeMinute[MAX_LOADSTRING + 1] = L"";
	TCHAR szTimeSecond[MAX_LOADSTRING + 1] =  L"";
	TCHAR szTimeMilliSecond[MAX_LOADSTRING + 1] =  L"";
	TStreamInfo pInfo;
	player->GetStreamInfo(&pInfo);

	ConvertIntToTCHAR(pInfo.Length.hms.minute, szTimeMinute);
	ConvertIntToTCHAR(pInfo.Length.hms.second, szTimeSecond);
	ConvertIntToTCHAR(pInfo.Length.hms.millisecond, szTimeMilliSecond);

	wsprintf(FileStatus.szTotalTime, 
		TEXT("%02s:%02s:%03s"), 
		szTimeMinute, 
		szTimeSecond, 
		szTimeMilliSecond);
	return ;
}

/*****************************************************
*	@func	:	SetMusicCurrentTime
*	@summary:	设置音乐的当前时间
*	@in		:	void
*	@out	:	none
*	@return	:	void
*	@author	:	DaPPer
*	@time	:	2013-4-3 22:03:40
*	@history:	
******************************************************/
void CMusicProcessor::SetMusicCurrentTime()
{
	TCHAR szTimeMinute[MAX_LOADSTRING + 1] = L"";
	TCHAR szTimeSecond[MAX_LOADSTRING + 1] =  L"";
	TCHAR szTimeMilliSecond[MAX_LOADSTRING + 1] =  L"";
	TStreamTime pInfo;
	player->GetPosition(&pInfo);

	ConvertIntToTCHAR(pInfo.hms.minute, szTimeMinute);
	ConvertIntToTCHAR(pInfo.hms.second, szTimeSecond);
	ConvertIntToTCHAR(pInfo.hms.millisecond, szTimeMilliSecond);

	wsprintf(PlayStatus.szCurrentTime, 
		TEXT("%02s:%02s:%03s"), 
		szTimeMinute, 
		szTimeSecond, 
		szTimeMilliSecond);
	return ;
}

/*****************************************************
*	@func	:	GetStatus
*	@summary:	获取音乐的播放状态
*	@in		:	void
*	@out	:	none
*	@return	:	TRUE : 播放状态
*			:	FALSE : 播放完了
*	@author	:	DaPPer
*	@time	:	2013-4-3 22:03:40
*	@history:	
******************************************************/
int CMusicProcessor::GetStatus()
{
	TStreamStatus status;
	player->GetStatus(&status);
	return status.fPlay;
}

/*****************************************************
*	@func	:	Seek
*	@summary:	快进快退处理
*	@in		:	int iTime >= 0 : 快进
*			:	int iTime <  0 : 快退
*	@out	:	none
*	@return	:	void
*	@author	:	DaPPer
*	@time	:	2013-4-3 22:03:40
*	@history:	
******************************************************/
void CMusicProcessor::Seek(int iTime)
{
	TStreamTime pTime;
	if (0 <= iTime)
	{
		pTime.sec = iTime;
		player->Seek(tfSecond, &pTime, smFromCurrentForward);
	}
	else
	{
		pTime.sec = -iTime;
		player->Seek(tfSecond, &pTime, smFromCurrentBackward);
	}
}

void CMusicProcessor::SetPlayerVolume(int iVolume)
{
	player->SetPlayerVolume(iVolume, iVolume);
	player->GetPlayerVolume(&(PlayStatus.iLeftVolume), &(PlayStatus.iRightVolume));
	return ;
}

unsigned int CMusicProcessor::GetCurrentMilliSecond()
{
	TStreamTime pTime;
	player->GetPosition(&pTime);
	return pTime.ms;
}

unsigned int CMusicProcessor::GetTotalMilliSecond()
{
	TStreamInfo pInfo;
	player->GetStreamInfo(&pInfo);
	return pInfo.Length.ms;
}