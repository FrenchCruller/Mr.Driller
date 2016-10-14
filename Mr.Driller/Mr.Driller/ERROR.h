#pragma once
#include"SystemManager.h"
void RenderError(int ErrorCord) {

	SystemManager SysMgr;

	switch (ErrorCord) {
	case -1:
		MessageBox(NULL, "ERROR CODE:-1", "ERROR", MB_OK);
		exit(-1);
		break;
	}


	SysMgr.errorEndFlag = false;

	return;

}