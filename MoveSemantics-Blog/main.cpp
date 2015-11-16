#include "MovableImage.h"
#include "CopyableImage.h"
#include "OperatorImage.h"
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

void ManipulateImage2()
{
	Size imageSize(100, 100); 										// Create a 100x100 CSize-object
	OperatorImage inputImage1;										// Construct Image
	inputImage1.AllocBuffer(imageSize);								// Allocate Buffer
	inputImage1 = inputImage1 + 0.5;								// Add 0.5 to itself

	OperatorImage inputImage2;										// Construct Image
	inputImage2.AllocBuffer(imageSize);								// Allocate Buffer

	OperatorImage resultImage = inputImage1 * inputImage2;			// Multiplies im1 and im2 and stores the result into resultImage
}
void ManipulateImage3()
{
	Size imageSize(100, 100); 										// Create a 100x100 CSize-object
	MovableImage inputImage1;										// Construct Image
	inputImage1.AllocBuffer(imageSize);								// Allocate Buffer
	inputImage1 = inputImage1 + 0.5;								// Add 0.5 to itself

	MovableImage inputImage2;										// Construct Image
	inputImage2.AllocBuffer(imageSize);								// Allocate Buffer

	MovableImage resultImage = inputImage1 * inputImage2;			// Multiplies im1 and im2 and stores the result into resultImage
}

void ManipulateImage4()
{
	Size imageSize(100, 100); 										// Create a 100x100 CSize-object
	MovableImage inputImage1;										// Construct Image
	inputImage1.AllocBuffer(imageSize);								// Allocate Buffer
	inputImage1 += 0.5;											// Add 0.5 to itself

	MovableImage inputImage2;										// Construct Image
	inputImage2.AllocBuffer(imageSize);								// Allocate Buffer

	MovableImage resultImage = inputImage1 * inputImage2;			// Multiplies im1 and im2 and stores the result into resultImage
}
void ManipulateImage5()
{
	Size imageSize(100, 100); 										// Create a 100x100 CSize-object
	CopyableImage inputImage1;										// Construct Image
	inputImage1.AllocBuffer(imageSize);								// Allocate Buffer
	inputImage1 += 0.5;											// Add 0.5 to itself

	CopyableImage inputImage2;										// Construct Image
	inputImage2.AllocBuffer(imageSize);								// Allocate Buffer

	CopyableImage resultImage = inputImage1 * inputImage2;			// Multiplies im1 and im2 and stores the result into resultImage
}

int main()
{
	try {
		ManipulateImage();			// Works but is ugly code
		//ManipulateImage2();		// This crashes
		ManipulateImage3();			// Works well
		ManipulateImage4();			// Works and is even slightly nicer
		ManipulateImage5();			// Works but is non intuitive for the user
	}
	catch (std::exception e)
	{
		std::cout << " Unhandled Exception: " << e.what();
		return 1;
	}
	std::cout << "Success" << std::endl;
	return 0;
}