#include "systemManager.h"
#include"DxLib.h"
#include"DebugManager.h"


SystemManager::SystemManager()
{
	this -> GameIsInit();
}

SystemManager::~SystemManager()
{
	this -> GameEnd();
}

void SystemManager::GameEnd() {

	DxLib_End();

	return;
}

void SystemManager::GetWindowMode(int width, int height) {
	
		int flag;
		flag = MessageBox(NULL,"フルスクリーンモードで起動しますか？","スクリーン設定",MB_YESNO | MB_ICONQUESTION);
		if (flag == IDNO)
			ChangeWindowMode(TRUE);
			SetWindowSize(width, height);

}
/*
*SystemManager::IsGameEnd();
*ゲーム終了時、本当にゲームを終了するか確認し、誤操作を防ぐ
*TRUE：終了　FALSE：継続
*/

bool SystemManager::IsGameEnd() {

	//ホップアップウインドウの設定　戻り値　TRUE：終了　FALSE：継続
	systemEndFlag = MessageBox(NULL, "プログラムを終了しますか？", "END", MB_YESNO | MB_ICONQUESTION);

	if (systemEndFlag == IDNO) {

		endFlag = true;
	}
	else {
		endFlag = false;
	}
	
	return	endFlag;
}
 
/*
* SystemManager::gameIsInit()
*起動時一度だけ行う初期化処理
*戻り値　TRUE：成功　FALSE：失敗
*/
void SystemManager::GameIsInit() {

	//ウインドウモードを設定する　TRUE：ウインドウモード　FALSE：フルスクリーンモード
	this -> GetWindowMode(600,400);
	
	//ウインドウの名前を設定する
	SetMainWindowText("ミスタードリラー");	

	//マウスカーソルを表示するか設定する　TRUE：表示　FALSE：非表示
	int GetMouseDispFlag(TRUE);

	//ウインドウの二重生成ができるかを設定する　TRUE：可能　FALSE：不可能
	SetDoubleStartValidFlag(FALSE);
	
	//DXライブラリの初期化、裏画面のセット　返り値　TRUE：成功  FALSE：失敗
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) {

		DebugManager::Instance()->RenderError(DebugManager::RenderErrorType::FailedInit);
	
	}
}

int SystemManager::Update() {

	// DebugManager::Instance().ErrorEndFlag();
	// DebugManager::Instance().RenderError(id);

	while (ProcessMessage() != -1 && DebugManager::Instance()->GetEndFlag() != false) {

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {

			this->endFlag = this->IsGameEnd();
			if (this->endFlag == false)break;
		}

		ClearDrawScreen();
		ScreenFlip();
	}

	return 0;
}
