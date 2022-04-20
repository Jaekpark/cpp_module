#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

class Convert {
	private:
		double		value_;
		std::string input_;
		Convert(void);

	public:
		Convert(char *input);
		Convert(const Convert& ref);
		~Convert(void);
		Convert& operator=(const Convert& ref);

		char	toChar(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		double 	toDouble(void) const;
		
		class impossible : public std::exception {
			public:
				const char*	what(void) const throw();
		};

		class nonDisplayable : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};
};
#endif