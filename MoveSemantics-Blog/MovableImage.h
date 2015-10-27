#pragma once
#include "Image.h"
class MovableImage :
	public Image
{
public:
	MovableImage();
	MovableImage(MovableImage && toMove);
	~MovableImage();

	friend MovableImage operator+(const MovableImage & first, const double constant);

	friend MovableImage operator*(const MovableImage & first, const MovableImage & second);

	MovableImage & operator=(MovableImage && toMove);

	void Swap(MovableImage && toMove);
};

