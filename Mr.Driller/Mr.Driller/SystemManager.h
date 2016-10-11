#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_

class SystemManager
{
private:
	bool endFlag = false;
public:
	SystemManager();

	~SystemManager();

	bool gameInit(int, int);
	void gameEnd();
	int upDate();
};

#endif // !systemManager