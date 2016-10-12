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

	MessageBox(NULL, "�v���O�������I�����܂����B", "END", MB_OK);
	DxLib_End();

	return;
}

 
/*
* SystemManager::gameIsInit(�E�C���h�E�̏c��ʂ̒���, �E�C���h�E�̉���ʂ̒���)
*�N������x�����s������������
*�߂�l�@TRUE�F�����@FALSE�F���s
*/
bool SystemManager::gameIsInit(int width, int height) {
	
	
	//�E�C���h�E�̖��O��ݒ肷��
	SetMainWindowText("�~�X�^�[�h�����[");

	//�E�C���h�E�T�C�Y���擾����
	SetWindowSize(width, height);

	//�}�E�X�J�[�\����\�����邩�ݒ肷��@TRUE�F�\���@FALSE�F��\��
	int GetMouseDispFlag(TRUE);

	//�E�C���h�E�̓�d�������ł��邩��ݒ肷��@TRUE�F�\�@FALSE�F�s�\
	SetDoubleStartValidFlag(FALSE);
	
	//�E�C���h�E���[�h��ݒ肷��@TRUE�F�E�C���h�E���[�h�@FALSE�F�t���X�N���[�����[�h
	ChangeWindowMode(TRUE);

	//DX���C�u�����̏������A����ʂ̃Z�b�g�@�Ԃ�l�@TRUE�F���� FALSE�F���s
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
