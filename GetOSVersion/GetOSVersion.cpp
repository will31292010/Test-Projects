// GetOSVersion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>



int _tmain(int argc, _TCHAR* argv[])
{
	OSVERSIONINFOEX osvi;
    BOOL bOsVersionInfoEx;
	
   // Try calling GetVersionEx using the OSVERSIONINFOEX structure.
   //
   // If that fails, try using the OSVERSIONINFO structure.

	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if( !(bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi)) )
	{
      // If OSVERSIONINFOEX doesn't work, try OSVERSIONINFO.

      osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
      if (! GetVersionEx ( (OSVERSIONINFO *) &osvi) ) 
         return FALSE;
	}

	printf("dwOSVersionInfoSize=%d\n", osvi.dwOSVersionInfoSize);
	printf("dwMajorVersion=%d\n", osvi.dwMajorVersion);
	printf("dwMinorVersion=%d\n", osvi.dwMinorVersion);
	printf("dwBuildNumber=%d\n", osvi.dwBuildNumber);
	printf("dwPlatformId=%d\n", osvi.dwPlatformId);
	printf("szCSDVersion=%s\n", osvi.szCSDVersion);
	printf("wServicePackMajor=%d\n", osvi.wServicePackMajor);
	printf("wServicePackMinor=%d\n", osvi.wServicePackMinor);
	printf("wSuiteMask=%d\n", osvi.wSuiteMask);
	printf("wProductType=%c\n", osvi.wProductType);
	printf("wReserved=%c\n", osvi.wReserved);

	char buf[100];

	scanf("%s", buf);


	return 0;
}

