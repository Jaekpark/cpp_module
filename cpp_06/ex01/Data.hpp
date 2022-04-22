#ifndef DATA_HPP
#define DATA_HPP

#define NAME	"Kaisa"
#define SPEED	335
#define AD		78
#define	AP		56

#include <iostream>
#include <string>
#include <ostream>
#include <stdexcept>
#include "Console.hpp"

class Data {
	private:
		std::string name_;
		int			speed_;
		int			ad_;
		int			ap_;

	public:
		std::string	getName(void) const;
		int			getSpeed(void) const;
		int			getAd(void) const;
		int			getAp(void) const;
		void		test(void);
		Data(void);
		Data(std::string name, int speed, int ad, int ap);
		Data(const Data& ref);
		Data& operator=(const Data& ref);
		~Data(void);
};

uintptr_t		serialize(Data* ptr);
Data*			deserialize(uintptr_t raw);
std::ostream&	operator<<(std::ostream& out, const Data& ref);

#endif