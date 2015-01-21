#include <iostream>
#include <cmath>


void RGBtoHSV (double *r, double *g, double *b, double h, double s, double v);

void RGBtoHSV255 (double *r, double *g, double *b, double h, double s, double v);

void RGBtoHSVRange (double *r, double *g, double *b, double h, double s, double v, double start, double end);

int main() {
	double red = 0;
	double green = 0;
	double blue = 0;

	RGBtoHSV(&red, &green, &blue, 95, 0.658, 0.757);
	std::cout << "Red: ";
	std::cout << red;
	std::cout << " Green: ";
	std::cout << green;
	std::cout << " Blue: ";
	std::cout << blue;
}

/** This function converts HSV to RGB
 * Given a color with hue H ∈ [0°, 360°], saturation SHSV ∈ [0, 1], and value V ∈ [0, 1]
 * 
 * returns R, G, B ∈ [0, 1]
 *  */
void RGBtoHSV (double *r, double *g, double *b, double h, double s, double v) {
	
	// Find chroma
	double chroma = v * s;
	
	double hPrime = h / 60;
	
	double x = chroma*(1 - std::abs(fmod(hPrime, 2)- 1));
	
	double r1, g1, b1;
	r1 = 0;
	g1 = 0;
	b1 = 0;
	
	if (0 <= hPrime && hPrime < 1) {
		r1 = chroma;
		g1 = x;
	} else if (1 <= hPrime && hPrime < 2) {
		r1 = x;
		g1 = chroma;
	} else if (2 <= hPrime && hPrime < 3) {
		g1 = chroma;
		b1 = x;
	} else if (3 <= hPrime && hPrime < 4) {
		g1 = x;
		b1 = chroma;
	} else if (4 <= hPrime && hPrime < 5) {
		r1 = x;
		b1 = chroma;
	} else if (5 <= hPrime && hPrime < 6) {
		r1 = chroma;
		b1 = x;
	}
	
	double m = v - chroma;
	
	*r = r1 + m;
	*g = g1 + m;
	*b = b1 + m;
}

/** This function converts HSV to RGB 
 * Every parameter is ∈ [0, 255] */
void RGBtoHSV255 (double *r, double *g, double *b, double h, double s, double v) {
	h = (h / 255) * 360;
	s = (s / 255);
	v = (v / 255);
	
	RGBtoHSV(r, g, b, h, s, v);
	
	*r = *r * 255;
	*g = *g * 255;
	*b = *b * 255;
}

/** This function converts HSV to RGB 
 * Every parameter is ∈ [start, end] */
void RGBtoHSVRange (double *r, double *g, double *b, double h, double s, double v, double start, double end) {
	double mutliplier = end - start;
	
	h = ((h - start) / mutliplier) * 360;
	s = ((s - start) / mutliplier);
	v = ((v - start) / mutliplier);
	
	RGBtoHSV(r, g, b, h, s, v);
	
	*r = *r * mutliplier + start;
	*g = *g * mutliplier + start;
	*b = *b * mutliplier + start;
}
