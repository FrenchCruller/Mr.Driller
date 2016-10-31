#pragma once
#include"IScene.h"
#include"ISceneChanger.h"

class SceneManager:public IScene{
protected:
	int mGraphicHandle;
	ISceneChanger* mSceneChanger;

public:
	SceneManager(ISceneChanger* changer);
	~SceneManager();
	virtual void Update() override {};
	virtual void Init() override {};
	virtual void Render() override {};
	virtual void Final() override {};

};

