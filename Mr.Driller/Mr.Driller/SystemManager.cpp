#include "systemManager.h"
#include"DxLib.h"
#include"ERROR.h"


SystemManager::SystemManager()
{
}

SystemManager::~SystemManager()
{
}
void SystemManager::gameEnd() {

	MessageBox(NULL, "プログラムを終了しました。", "END", MB_OK);
	DxLib_End();

	return;
}

 
/*
* SystemManager::gameIsInit(ウインドウの縦画面の長さ, ウインドウの横画面の長さ)
*起動時一度だけ行う初期化処理
*戻り値　TRUE：成功　FALSE：失敗
*/
bool SystemManager::gameIsInit(int width, int height) {
	
	
	//ウインドウの名前を設定する
	SetMainWindowText("ミスタードリラー");

	//ウインドウサイズを取得する
	SetWindowSize(width, height);

	//マウスカーソルを表示するか設定する　TRUE：表示　FALSE：非表示
	int GetMouseDispFlag(TRUE);

	//ウインドウの二重生成ができるかを設定する　TRUE：可能　FALSE：不可能
	SetDoubleStartValidFlag(FALSE);
	
	//ウインドウモードを設定する　TRUE：ウインドウモード　FALSE：フルスクリーンモード
	ChangeWindowMode(TRUE);

	//DXライブラリの初期化、裏画面のセット　返り値　TRUE：成功 FALSE：失敗
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) {

		RenderError(-1);
	}
	else {
		SystemManager::endFlag = true;
	}

	return SystemManager::endFlag;
}

int SystemManager::upDate() {

	
	


	return 0;
}
