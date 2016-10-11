#include "systemManager.h"
#include"DxLib.h"


SystemManager::SystemManager()
{
}

SystemManager::~SystemManager()
{
}

/*
* SystemManager::gameIsInit(�E�C���h�E�̏c��ʂ̒���, �E�C���h�E�̉���ʂ̒���)
*�N������x�����s������������
*�߂�l�@TRUE�F�����@FALSE�F���s
*/
bool SystemManager::gameIsInit(int width, int height) {
	
	//����{�^���������ꂽ�Ƃ��ɃV�X�e��������ɏI�����邽�߂̏������`����֐�
	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	
	//�E�C���h�E�̖��O��ݒ肷��
	SetMainWindowText("Mr.Driller");

	//�E�C���h�E�T�C�Y���擾����
	SetWindowSize(width, height);

	//�}�E�X�J�[�\����\�����邩�ݒ肷��@TRUE�F�\���@FALSE�F��\��
	int GetMouseDispFlag(TRUE);

	//�E�C���h�E�̓�d�������ł��邩��ݒ肷��@TRUE�F�\�@FALSE�F�s�\
	SetDoubleStartValidFlag(FALSE);
	
	//�E�C���h�E���[�h��ݒ肷��@TRUE�F�E�C���h�E���[�h�@FALSE�F�t���X�N���[�����[�h
	ChangeWindowMode(TRUE);

	//����{�^���������ꂽ�Ƃ��ɃV�X�e��������ɏI�����邽�߂̏���������֐�
	SetHookWinProc(WndProc);

	//DX���C�u�����̏������A����ʂ̃Z�b�g�@�Ԃ�l�@TRUE�F���� FALSE�F���s
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