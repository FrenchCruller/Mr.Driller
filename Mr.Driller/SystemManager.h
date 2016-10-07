#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_


class SystemManager{

private:
	bool endProcess = false;

public:
	SystemManager();

	bool Init(int,int);
	void Update();

	~SystemManager();
};

#endif

