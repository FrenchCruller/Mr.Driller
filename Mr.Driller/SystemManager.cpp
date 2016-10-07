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
*�Q�[���̏���������
*
*�����F�E�B���h�E�T�C�Y�� width,height
*���������s���Afalse���A��
*
*����ʂ��Z�b�g��A�E�B���h�E�T�C�Y��ݒ�
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
*���C�����[�v���������郁���o�֐�
*�G�X�P�[�v�L�[�������ƏI��
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
