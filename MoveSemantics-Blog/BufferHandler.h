#pragma once
#include "Size.h"
#include <map>

class BufferHandler
{
public:
	BufferHandler() = delete;
	~BufferHandler() = delete;

	static int RequestBuffer(Size size);
	static void RequestFree(int BufferId);
private:
	static std::map<int, Size> BufferMap;
	static int NextBufferId;

};

