#include "MovableImage.h"



MovableImage::MovableImage()
{
}

MovableImage::MovableImage(MovableImage && toMove)
	:MovableImage()
{
	Swap(std::move(toMove));
}


MovableImage::~MovableImage()
{
}
MovableImage operator*(const MovableImage & first, const MovableImage & second)
{
	MovableImage result;
	result.AllocBuffer(first.GetSize());
	result.Arith(first, second, Operation::MULT);
	return result;
}
MovableImage operator+(const MovableImage & first, const double constant)
{
	MovableImage result;
	result.AllocBuffer(first.GetSize());
	result.Arith(first, constant, Operation::ADD);
	return result;
}
MovableImage & MovableImage::operator=(MovableImage && toMove)
{
	Swap(std::move(toMove));
	return *this;
}
void MovableImage::Swap(MovableImage && toMove)
{
	std::swap(m_Size, toMove.m_Size);
	std::swap(m_nBufferId, toMove.m_nBufferId);
}