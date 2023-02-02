#include "Coordinate.h"
#include <math.h>
Coordinate::Coordinate()
{
	x = 0;
	y = 0;
}

Coordinate::Coordinate(float X, float Y)
{
	this->x = X;
	this->y = Y;
}

float Coordinate::getMagnitude()
{
	return (float) sqrt((double)x * x + (double)y * y);
}

float Coordinate::getSqrMagnitude()
{
	return (x * x + y * y);
}

void Coordinate::normalize()
{
	float magnitude = getMagnitude();
	x /= magnitude;
	y /= magnitude;
}
Coordinate Coordinate::getNormalize()
{
	float magnitude = getMagnitude();
	return Coordinate(x / magnitude, y / magnitude);
}
