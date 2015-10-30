#pragma once
#include "Image.h"
class OperatorImage :
	public Image
{
public:
	OperatorImage();
	~OperatorImage();

	friend OperatorImage operator+(const OperatorImage & first, const double constant)
	{
		OperatorImage result;
		result.AllocBuffer(first.GetSize());
		result.Arith(first, constant, Operation::ADD);
		return result;
	}

	friend OperatorImage operator*(const OperatorImage & first, const OperatorImage & second)
	{
		OperatorImage result;
		result.AllocBuffer(first.GetSize());
		result.Arith(first, second, Operation::MULT);
		return result;
	}

};

