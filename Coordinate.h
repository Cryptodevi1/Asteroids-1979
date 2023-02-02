#pragma once
class Coordinate
{
public:
	
	float x, y;

	Coordinate();
	Coordinate(float X, float Y);
	float getMagnitude();
	float getSqrMagnitude();
	void normalize();
	Coordinate getNormalize();

	Coordinate diff(Coordinate point)
	{
		return Coordinate(this->x - point.x, this->y - point.y);
	}

	Coordinate div(float val)
	{
		return Coordinate(this->x / val, this->y / val);
	}

	Coordinate mult(float val)
	{
		return Coordinate(this->x * val, this->y * val);
	}
};

