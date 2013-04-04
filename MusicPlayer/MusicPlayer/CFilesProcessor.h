#ifndef __CFILESPROCESSOR_H__
#define __CFILESPROCESSOR_H__

#define MAX_LOADSTRING 100						// 最大字符数目

class CFilesProcessor
{
public:
	static CFilesProcessor* getInstance();
	TCHAR* GetCurrentPath();
	void SetFilesPath(const TCHAR[]);
	void SetFilesCount(int );
	int GetFilesCount();
private:
	TCHAR m_szCurrentPath[MAX_LOADSTRING + 1];
	int m_iFilesCount;
};

#endif // __CFILESPROCESSOR_H__