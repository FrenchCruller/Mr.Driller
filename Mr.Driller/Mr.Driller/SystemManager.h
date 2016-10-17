#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_

#include"DxLib.h"

class SystemManager{
private:
	int systemEndFlag;
	void GameIsInit();
	void GameEnd();
	bool IsGameEnd();
	bool endFlag = false;

public:
	SystemManager();
	~SystemManager();

	int Update();
	void GetWindowMode(int, int);
};


#endif // !_SYSTEM_MANAGER_H_