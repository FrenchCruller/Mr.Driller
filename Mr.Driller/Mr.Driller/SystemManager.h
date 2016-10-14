#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_

#include"DxLib.h"

class SystemManager{
private:
	int systemEndFlag;
public:
	SystemManager();
	~SystemManager();

	bool GameIsInit();

	void GameEnd();

	int Update();

	void GetWindowMode(int, int);
	bool IsGameEnd();

	bool errorEndFlag = false;
	bool endFlag = false;
	
};


#endif // !_SYSTEM_MANAGER_H_