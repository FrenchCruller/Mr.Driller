#pragma once
#include"SystemManager.h"
void RenderError(int ErrorCord) {

	SystemManager SysMgr;

	switch (ErrorCord) {
	case -1:
		MessageBox(NULL, "�������Ɏ��s���܂����B", "ERROR -1", MB_OK);
		SysMgr.gameEnd();
		exit(-1);
		break;
	}


	SysMgr.endFlag = false;

	return;

}