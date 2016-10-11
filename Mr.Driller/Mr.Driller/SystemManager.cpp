#include "systemManager.h"
#include"DxLib.h"


SystemManager::SystemManager()
{
}


SystemManager::~SystemManager()
{
}

bool SystemManager::gameInit(int width, int height) {

	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return false;

	ChangeWindowMode(TRUE);
	SetWindowSize(width, height);

	return true;
}
int SystemManager::upDate() {

	SystemManager::endFlag = SystemManager::gameInit(600, 400);

	if (SystemManager::endFlag == false) {
		return -1;
	}
	else {
		return 0;
	}

}
void SystemManager::gameEnd() {

	DxLib_End();
}