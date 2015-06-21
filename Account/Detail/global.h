#pragma once

typedef struct tagFileData
{
	//store this item is which mode
	Tstring sMode;	
	//only for csv file mode
	int iIndex;	//store file index 
	Tstring sFile;	//store file full path 
	CString	sName;
	CString	sEntryID;
	CString	sStoreID;
	DWORD dwTypeFlag;	//FolderTypeFlag
	bool     bLoad;
}FileData;

//tree use 
#define MOBILE_PHONE	_T("MOBILE_PHONE")
#define SIM_CARD		_T("SIM CARD")
#define SLAVE_SIM_CARD	_T("SLAVE SIM CARD")
#define MEMORY			_T("MEMORY")
#define COMPUTER		_T("COMPUTER")
#define CSVFILE			_T("CSVFILE")
#define MSOUTLOOK			_T("MSOUTLOOK")

void getAppCurDir(TCHAR *curDir);
int LogtoFile(const TCHAR *pszFormat, ...);
