#include <windows.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc != 2){
		printf("Incorrect number of arguments! (%d/1\n", argc-1);
		return 1;
	}
	size_t len = strlen(argv[1]) + 1;
	HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), argv[1], len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
	return 0;
}