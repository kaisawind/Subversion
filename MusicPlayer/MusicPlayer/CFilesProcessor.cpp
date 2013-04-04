
#include "stdafx.h"
#include "CFilesProcessor.h"

CFilesProcessor* CFilesProcessor::getInstance()
{
	static CFilesProcessor obj;
	return &obj;
}

TCHAR* CFilesProcessor::GetCurrentPath()
{
	GetCurrentDirectory(lstrlen(m_szCurrentPath), m_szCurrentPath);
	return m_szCurrentPath;
}

void CFilesProcessor::SetFilesPath(const TCHAR szFilesPath[])
{
	SetCurrentDirectory(szFilesPath);
	lstrcpy(this->m_szCurrentPath, szFilesPath);
	return ;
}

void CFilesProcessor::SetFilesCount(int iFilesCount)
{
	this->m_iFilesCount = iFilesCount;
	return ;
}

int CFilesProcessor::GetFilesCount()
{
	return m_iFilesCount;
}