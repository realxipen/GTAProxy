#include <windows.h>

int thread() {
	while(1){

		// ctrl+l
		if(GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x4C)){
			char szFile[MAX_PATH];
			OPENFILENAMEA ofn = {0};
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = NULL;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = "DLL to Load\0*.dll\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if(GetOpenFileNameA(&ofn)) 
				LoadLibraryA(ofn.lpstrFile);
			
		}

		Sleep(5);

	}
	return 1;
}