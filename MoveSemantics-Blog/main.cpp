#include "Image.h"
#include <iostream>

void ManipulateImage()
{
	Size imageSize(100, 100); 										// Create a 100x100 CSize-object
	Image inputImage1;												// Construct Image
	inputImage1.AllocBuffer(imageSize);								// Allocate Buffer
	inputImage1.Arith(inputImage1, 0.5, Operation::ADD);			// Add 0.5 to itself

	Image inputImage2;												// Construct Image
	inputImage2.AllocBuffer(imageSize);								// Allocate Buffer

	Image resultImage;												// Allocate ResultImage
	resultImage.AllocBuffer(imageSize);								// Allocate Buffer

	resultImage.Arith(inputImage1, inputImage2, Operation::MULT);	// Multiplies im1 and im2 and stores the result into resultImage

}

int main()
{
	try {
		ManipulateImage();
	}
	catch (std::exception e)
	{
		std::cout << " Unhandled Exception: " << e.what();
		return 1;
	}
	std::cout << "Success" << std::endl;
	return 0;
}