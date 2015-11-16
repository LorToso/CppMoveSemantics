#include "CopyableImage.h"



CopyableImage::CopyableImage()
{
}

CopyableImage::CopyableImage(CopyableImage & toMove)
	:CopyableImage()
{
	Swap(toMove);
}
CopyableImage & CopyableImage::operator=(CopyableImage & toMove)
{
	Swap(std::move(toMove));
	return *this;
}
void CopyableImage::Swap(CopyableImage & toMove)
{
	std::swap(m_Size, toMove.m_Size);
	std::swap(m_nBufferId, toMove.m_nBufferId);
}


CopyableImage::~CopyableImage()
{
}
CopyableImage operator*(const CopyableImage & first, const CopyableImage & second)
{
	CopyableImage result;
	result.AllocBuffer(first.GetSize());
	result.Arith(first, second, Operation::MULT);
	return result;
}
CopyableImage operator+(const CopyableImage & first, const double constant)
{
	CopyableImage result;
	result.AllocBuffer(first.GetSize());
	result.Arith(first, constant, Operation::ADD);
	return result;
}
CopyableImage & CopyableImage::operator+=(const double constant)
{
	Arith(*this, constant, Operation::ADD);
	return *this;
}