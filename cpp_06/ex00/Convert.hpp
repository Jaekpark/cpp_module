#ifndef CONVERT_HPP
#define CONVERT_HPP

#define MIN_PRINTABLE	32
#define MAX_PRINTABLE	126
#define NON_PRINTABLE	"Non Displayble"
#define CHR				"char: "
#define INT				"int: "
#define FLT				"float: "
#define DBL				"double: "
#define SUFIX_FLT		"f"
#define SUFIX_DEC		".0"
#define SUFIX_FLT_DEC	".0f"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <math.h>

class Convert {
	private:
		double		value_;
		
		Convert(void);

	public:
		Convert(char c);
		Convert(char *input);
		Convert(const Convert& ref);
		~Convert(void);
		Convert& operator=(const Convert& ref);

		char	toChar(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		double 	toDouble(void) const;
		int		toInt(char c) const;
		float	toFloat(char c) const;
		double 	toDouble(char c) const;

		static bool	isPrintable(char c);
		static bool	isNumber(char c);

		void	printFloat(void);
		void	printDouble(void);
		void	printChar(void);
		void	printInt(void);
		void	printValue(void);
		
		class impossible : public std::exception {
			public:
				const char*	what(void) const throw();
		};

		class nonDisplayable : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};

		class inputUnavailable : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};
};

#endif
