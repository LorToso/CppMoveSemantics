#pragma once
#include "Image.h"
class CopyableImage :
	public Image
{
public:
	CopyableImage();
	CopyableImage(CopyableImage & toMove);
	~CopyableImage();

	friend CopyableImage operator+(const CopyableImage & first, const double constant);

	friend CopyableImage operator*(const CopyableImage & first, const CopyableImage & second);
	CopyableImage & operator+=(const double constant);

	CopyableImage & operator=(CopyableImage & toMove);

	void Swap(CopyableImage & toMove);
};

