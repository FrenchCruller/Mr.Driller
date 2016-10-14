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
		flag = MessageBox(NULL,"�t���X�N���[�����[�h�ŋN�����܂����H","�X�N���[���ݒ�",MB_YESNO | MB_ICONQUESTION);
		if (flag == IDNO)
			ChangeWindowMode(TRUE);
			SetWindowSize(width, height);

}
/*
*SystemManager::IsGameEnd();
*�Q�[���I�����A�{���ɃQ�[�����I�����邩�m�F���A�둀���h��
*TRUE�F�I���@FALSE�F�p��
*/

bool SystemManager::IsGameEnd() {

	//�z�b�v�A�b�v�E�C���h�E�̐ݒ�@�߂�l�@TRUE�F�I���@FALSE�F�p��
	systemEndFlag = MessageBox(NULL, "�v���O�������I�����܂����H", "END", MB_YESNO | MB_ICONQUESTION);

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
*�N������x�����s������������
*�߂�l�@TRUE�F�����@FALSE�F���s
*/
void SystemManager::GameIsInit() {

	//�E�C���h�E���[�h��ݒ肷��@TRUE�F�E�C���h�E���[�h�@FALSE�F�t���X�N���[�����[�h
	this -> GetWindowMode(600,400);
	
	//�E�C���h�E�̖��O��ݒ肷��
	SetMainWindowText("�~�X�^�[�h�����[");	

	//�}�E�X�J�[�\����\�����邩�ݒ肷��@TRUE�F�\���@FALSE�F��\��
	int GetMouseDispFlag(TRUE);

	//�E�C���h�E�̓�d�������ł��邩��ݒ肷��@TRUE�F�\�@FALSE�F�s�\
	SetDoubleStartValidFlag(FALSE);
	
	//DX���C�u�����̏������A����ʂ̃Z�b�g�@�Ԃ�l�@TRUE�F����  FALSE�F���s
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
