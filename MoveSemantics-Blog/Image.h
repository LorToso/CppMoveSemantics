#pragma once
#include "Size.h"
#include "BufferHandler.h"
#include "Operation.h"

class Image {
public:
	Image()
	{
		AllocBuffer(Size(0,0));
	}
	
	~Image()
	{
		FreeBuffer();
	};

	void AllocBuffer(Size size)
	{
		FreeBuffer();
		m_nBufferId = BufferHandler::RequestBuffer(size);
		m_Size = size;
	};

	void FreeBuffer()
	{
		if (m_nBufferId == 0)
			return;
		
		BufferHandler::RequestFree(m_nBufferId);
		m_nBufferId = 0;
	};

	void Arith(const Image & Source1, const Image & Source2, Operation op);
	void Arith(const Image & Source1, const double constant, Operation op);

	Size GetSize() const;


protected:
	int m_nBufferId = 0;
	Size m_Size;
};