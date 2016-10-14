#include"SystemManager.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SystemManager SysMgr;

	SysMgr.GameIsInit();

	while (ProcessMessage() != -1  && SysMgr.errorEndFlag != false) {

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			SysMgr.endFlag = SysMgr.IsGameEnd();
			if (SysMgr.endFlag == false)break;
		}

	SysMgr.Update();
		
	}
	
	SysMgr.GameEnd();
	return 0;
}
