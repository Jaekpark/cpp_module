#ifndef WELLRANDOM_HPP
#define WELLRANDOM_HPP

#define SIZE 16
#include <iostream>
#include <ctime>

class WellRandom {
	private:
		const unsigned int	differ_;
	
	protected:
		unsigned int	index_;
		unsigned long	state_[SIZE];

	public:
		unsigned int	getValue(void);
		unsigned int	getValue(unsigned int max);
		unsigned int	getValue(unsigned int min, unsigned int max);
	
	WellRandom(void);
	WellRandom(unsigned int seed);
	WellRandom(const WellRandom& ref);
	WellRandom& operator=(const WellRandom& ref);
	~WellRandom(void);

};

#endif
