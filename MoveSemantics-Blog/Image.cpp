#include "Image.h"

void Image::Arith(const Image & Source1, const Image & Source2, Operation op)
{
}

void Image::Arith(const Image & Source1, const double constant, Operation op)
{
}

Size Image::GetSize() const
{
	return m_Size;
}
