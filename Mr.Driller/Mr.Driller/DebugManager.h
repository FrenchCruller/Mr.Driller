#pragma once
class DebugManager
{
private:
	DebugManager();
	bool errorEndFlag;

public:

	enum  class RenderErrorType
	{
		FailedInit = 0,

	};

	static DebugManager* Instance();
	~DebugManager();
	void RenderError(RenderErrorType);

	bool GetEndFlag();


};

