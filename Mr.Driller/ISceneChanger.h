#pragma once


class ISceneChanger {
private:
	ISceneChanger();

public:
	virtual ~ISceneChanger() = default;
	
	enum class eScene {

		eScene_Menu,
		eScene_Title,
		eScene_Game,
		eScene_Grow,
		eSecne_Config,

		eScene_NULL,
	};

	virtual void ChangeScene(eScene NextScene) = 0;
};

