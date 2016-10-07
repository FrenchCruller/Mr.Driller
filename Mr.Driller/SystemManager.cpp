#include "SystemManager.h"
#include"Dxlib.h"
namespace {
	const int Error = -1;
}

SystemManager::SystemManager()
{
}


SystemManager::~SystemManager()
{
}

/*
*ゲームの初期化処理
*
*引数：ウィンドウサイズの width,height
*初期化失敗時、falseが帰る
*
*裏画面をセット後、ウィンドウサイズを設定
*
*/
bool SystemManager::Init(int width,int height) {


	if( DxLib_Init() == -1)return false;

	ChangeWindowMode(true);
	SetDrawScreen(DX_SCREEN_BACK);
	
	::SetWindowSize(width, height);

	return true;
}

/*
*メインループを処理するメンバ関数
*エスケープキーを押すと終了
*
*
*/
void SystemManager::Update() {

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		
		endProcess = SystemManager::Init(600, 400); 
		ScreenFlip();
	}

	if(endProcess == true)	DxLib_End();
}
