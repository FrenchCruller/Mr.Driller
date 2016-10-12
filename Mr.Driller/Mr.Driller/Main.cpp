#include"SystemManager.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SystemManager SysMgr;

	if( SysMgr.gameIsInit(600,400) == false) return -1;

	while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != 1) {

		if (SysMgr.endFlag == false) break;
	}

	SysMgr.gameEnd();
	return 0;
}
