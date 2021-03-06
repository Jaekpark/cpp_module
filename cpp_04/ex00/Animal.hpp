#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define MAGENTA	"\033[0;35m"
#define CYAN	"\033[0;36m"
#define EOC		"\033[0m"
#define BOLD	"\033[1m"
#define WIDTH	18

#define ANIMAL	"Animal"
#define CONS	"Constructor"
#define DES		"Destructor"
#define COPY	"Copy Constructor"
#define ASSG	"Assignment"
#define LOG		"System Log"
#define FUNC	"Function Log"

#include <iostream>
#include <string>
#include <iomanip>

class	Animal {
	private:
		std::string		type_;

	public:
		static void		printHeader(void);
		static void		printPanel(const std::string str, const std::string color, int width);
		static void		printPanel(const std::string str, const std::string color);
		static void		printPanel(const std::string str);
		void			printLog(const std::string str) const;
		void			printLog(const std::string str, const std::string color) const;
		void			printType(void) const;
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		void			setType(const std::string& type);

		Animal(void);
		Animal(const Animal& ref);
		Animal& operator=(const Animal& ref);
		virtual ~Animal(void);
};

#endif