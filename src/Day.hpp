#ifndef DAY_HPP
#define DAY_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace orca
{

class Day
{
	public:
		Day();
		int getTimeOfDay () const;
		void updateTime ();
		void unpause ();
		int getDay ();
		void resetDate ();
		void setTimer (int n);

	private:
	    sf::Clock clock;
		sf::Time time;
		int dayNumber;
		bool night;
		short int opacityOffSet;
};

}
#endif
