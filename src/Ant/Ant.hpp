#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#define PI 3.14159265

struct Ant
{
	double speed = 1;
	int angle = 0;
	double x = 0;
	double y = 0;
	int timeAlive = 0;

	Ant(int xx, int yy)
	{
		x = xx;
		y = yy;
	}

	Ant()
	{
	}

	Ant& move()
	{
		int randNum = (rand() % 3) + 1;
		switch (randNum)
		{
			case 1:
				angle += 45;
				break;
			case 2:
				angle -= 45;
				break;
			default:
				break;
		}
		angle %= 360;
		x += speed * cos(angle * PI / 180.0);
		y += speed * sin(angle * PI / 180.0);
		return *this;
	}

	Ant& update()
	{
		move();
		timeAlive += 1;
		return *this;
	}
};