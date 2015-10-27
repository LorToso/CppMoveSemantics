#include "BufferHandler.h"

int BufferHandler::NextBufferId = 0;
std::map<int, Size> BufferHandler::BufferMap = std::map<int, Size>();

int BufferHandler::RequestBuffer(Size size)
{
	BufferMap[NextBufferId] = size;
	NextBufferId++;
	return NextBufferId;
}
void BufferHandler::RequestFree(int BufferId)
{
	auto it = BufferMap.find(BufferId);
	
	if (it == BufferMap.end())
	{
		throw std::exception("BufferNotAllocatedException");
		return;
	}

	BufferMap.erase(it);
}