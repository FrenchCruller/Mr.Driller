#include "systemManager.h"
#include"DxLib.h"


SystemManager::SystemManager()
{
}

SystemManager::~SystemManager()
{
}

/*
* SystemManager::gameIsInit(ウインドウの縦画面の長さ, ウインドウの横画面の長さ)
*起動時一度だけ行う初期化処理
*戻り値　TRUE：成功　FALSE：失敗
*/
bool SystemManager::gameIsInit(int width, int height) {
	
	//閉じるボタンが押されたときにシステムが正常に終了するための処理を定義する関数
	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	
	//ウインドウの名前を設定する
	SetMainWindowText("Mr.Driller");

	//ウインドウサイズを取得する
	SetWindowSize(width, height);

	//マウスカーソルを表示するか設定する　TRUE：表示　FALSE：非表示
	int GetMouseDispFlag(TRUE);

	//ウインドウの二重生成ができるかを設定する　TRUE：可能　FALSE：不可能
	SetDoubleStartValidFlag(FALSE);
	
	//ウインドウモードを設定する　TRUE：ウインドウモード　FALSE：フルスクリーンモード
	ChangeWindowMode(TRUE);

	//閉じるボタンが押されたときにシステムが正常に終了するための処理をする関数
	SetHookWinProc(WndProc);

	//DXライブラリの初期化、裏画面のセット　返り値　TRUE：成功 FALSE：失敗
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) {
		SystemManager::endFlag = false;
	}
	else {
		SystemManager::endFlag = true;
	}

	return SystemManager::endFlag;
}

int SystemManager::upDate() {

	
	



}
void SystemManager::gameEnd() {

	DxLib_End();
}