/********************************************************************************
* @file		:	Common.cpp
* @summary	:	通用函数处理
* @author	:	Li Jiachun
* @time		:	2013-4-3 22:00:26
* @history	:	
********************************************************************************/
#include "Common.h"

/*****************************************************************************
* @func		:	ConvertIntToTCHAR
* @summary	:	把整数转化为TCHAR型的字符串
* @in		:	unsigned int uiNum : 输入一个整数
*			:	TCHAR szNumber[] : 数组
* @out		:	TCHAR szNumber[] : TCHAR型的字符串
* @return	:	void
* @author	:	Li Jiachun
* @time		:	2013-4-3 22:02:11
* @history	:	
******************************************************************************/
void ConvertIntToTCHAR(unsigned int uiNum, TCHAR szNumber[])
{
	lstrcpy(szNumber, TEXT(""));

	while (1)
	{
		switch (uiNum % 10)
		{
		case 0:
			lstrcat(szNumber, L"0");
			break;
		case 1:
			lstrcat(szNumber, L"1");
			break;
		case 2:
			lstrcat(szNumber, L"2");
			break;
		case 3:
			lstrcat(szNumber, L"3");
			break;
		case 4:
			lstrcat(szNumber, L"4");
			break;
		case 5:
			lstrcat(szNumber, L"5");
			break;
		case 6:
			lstrcat(szNumber, L"6");
			break;
		case 7:
			lstrcat(szNumber, L"1");
			break;
		case 8:
			lstrcat(szNumber, L"8");
			break;
		case 9:
			lstrcat(szNumber, L"9");
			break;
		default:
			break;
		}
		uiNum /= 10;

		if (0 == uiNum)
		{
			break;
		}
	}

	TCHAR szTemp[MAX_STRING + 1] = L"";

	int iLength = (int)lstrlen(szNumber);
	for (int iIndexNumber = iLength - 1; iIndexNumber >= 0; iIndexNumber--)
	{
		szTemp[iLength - 1 - iIndexNumber] = szNumber[iIndexNumber];
	}

	lstrcpy(szNumber, szTemp);
	return ;
}