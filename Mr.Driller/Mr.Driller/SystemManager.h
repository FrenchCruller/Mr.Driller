#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_

#include"DxLib.h"

class SystemManager
{
private:
	bool endFlag = false;
public:
	SystemManager();

	~SystemManager();

	bool gameIsInit(int, int);

	void gameEnd();
	int upDate();

	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

		switch (msg) {
		case WM_QUIT:

			break;
		case WM_DESTROY:

			PostQuitMessage(0);
			break;
		}
		return 0;
	}
};

#endif // !_SYSTEM_MANAGER_H_