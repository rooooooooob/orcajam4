#include <iostream>

#include "Day.hpp"

namespace orca
{

Day::Day() : dayNumber (0), time (sf::Time::Zero), afternoon(true)
{
    clock.restart();
}

int Day::getTimeOfDay () const
{
    if (afternoon)
    {
        return time.asSeconds();
    }
    else
    {
        return 80 - time.asSeconds();
    }
}

void Day::updateTime ()
{
    if (time.asSeconds() > 80) //2 minutes per day/night cycle
    {
        if (afternoon)
        {
            dayNumber++;
            afternoon = false;
        }
        else
        {
            afternoon = true;
        }
        time = sf::Time::Zero;
    }

    time += clock.restart();
    std::cout << "Time: " << time.asSeconds() << "\n";
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
    afternoon = true;
    time = sf::Time::Zero;
    clock.restart();
}

void Day::setTimer (int n) //n = number of seconds
{
    //to be filled in
}

}
