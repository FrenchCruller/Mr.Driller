#include "SceneManager.h"



SceneManager::SceneManager(ISceneChanger* changer) : mGraphicHandle(0){
	mSceneChanger = changer;
}


 SceneManager::~SceneManager(){
	DeleteGraph(mGraphicHandle);
}

 void SceneManager::Render() {
	 DrawGraph(0, 0, mGraphicHandle, FALSE);
 }
