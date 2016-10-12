#pragma once
#include"SystemManager.h"
void RenderError(int ErrorCord) {

	SystemManager SysMgr;

	switch (ErrorCord) {
	case -1:
		MessageBox(NULL, "‰Šú‰»‚É¸”s‚µ‚Ü‚µ‚½B", "ERROR -1", MB_OK);
		SysMgr.gameEnd();
		exit(-1);
		break;
	}


	SysMgr.endFlag = false;

	return;

}