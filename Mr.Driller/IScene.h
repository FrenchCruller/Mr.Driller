#pragma once
#include"DxLib.h"
class IScene{
public:

	virtual ~IScene() = default;

	virtual void Update() = 0;
	virtual void Init() = 0;
	virtual void Render() = 0;
	virtual void Final() = 0;
};

