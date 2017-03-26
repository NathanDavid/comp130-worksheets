// Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;

int colourSet(double nooftimes, int colourchosen)
{
	double colour;

	//Picks the shade of the colour based on the number of iterations that were perfomed. 
	colour = colourchosen / (nooftimes / 18);

	return colour;
}

int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Minimum and maximum coordinates for the fractal
	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	float Imagewidth = image.width();

	int red = 125;
	int green = 0;
	int blue = 125;

	// Generate the image
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		double y0 = (pixelY / Imagewidth) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			double x0 = (pixelX / Imagewidth) * (maxX - minX) + minX;

			double x = 0.0;
			double y = 0.0;
			double iteration = 0;
			int MaxIteration = 255;

			while ((x*x + y*y < 2 * 2) && (iteration < MaxIteration))
			{
				double xTemp = x*x - y*y + x0;
				y = 2 * x*y + y0;
				x = xTemp;
				iteration++;
			}

			image(pixelX, pixelY, 0, 0) = colourSet(iteration, red); // red component
			image(pixelX, pixelY, 0, 1) = colourSet(iteration, green); // green component
			image(pixelX, pixelY, 0, 2) = colourSet(iteration, blue); // blue component
		}
	}


	// Display the complete image
	display.display(image);

	// Uncomment this line to save the image to disk
	//image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}
