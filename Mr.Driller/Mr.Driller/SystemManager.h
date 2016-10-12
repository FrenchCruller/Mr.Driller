#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_

#include"DxLib.h"

class SystemManager{
	
public:
	SystemManager();
	~SystemManager();

	bool gameIsInit(int, int);

	void gameEnd();

	int upDate();
	
	

	bool endFlag = false;
};

#endif // !_SYSTEM_MANAGER_H_