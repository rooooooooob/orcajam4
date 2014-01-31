#include <iostream>

#include <cmath>
#include "Day.hpp"

#define DAYLENGTH 240

namespace orca
{

Day::Day() : dayNumber (0), time (sf::Time::Zero), night(false), opacityOffSet (0)
{
	clock.restart();
}

int Day::getTimeOfDay () const
{
	 return opacityOffSet;
}

void Day::updateTime ()
{
	time += clock.restart();
	opacityOffSet = 40*cos(time.asSeconds()*3.14159265358979323846264/(DAYLENGTH/2));

	if (opacityOffSet < 0)
	{
		night = true;
	}
	else
	{
		night = false;
	}

	if (time.asSeconds() > DAYLENGTH)
	{
		dayNumber++;
		time = sf::Time::Zero;
	}
}

void Day::unpause ()
{
	clock.restart();
}

int Day::getDay ()
{
	return dayNumber;
}

void Day::resetDate ()
{
	dayNumber = 0;
	night = false;
	opacityOffSet = 0;
	time = sf::Time::Zero;
	clock.restart();
}

void Day::setTimer (int n) //n = number of seconds
{
	//to be filled in
}

}
