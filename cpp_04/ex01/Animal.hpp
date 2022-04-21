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
#include <sstream>

class Animal
{
	private:
		static int		animal_count_;
	
	protected:
		std::string		type_;
		int				id_;

	public:
		static int		getAnimalCount(void);
		static void		printHeader(void);
		static void		printPanel(const std::string str, const std::string color, int width);
		static void		printPanel(const std::string str, const std::string color);
		static void		printPanel(const std::string str);
		void			printClassPanel(const Animal& target, std::string color) const;
		void			printClassPanel(const Animal& target) const;
		void			printLog(const std::string str) const;
		void			printLog(const std::string str, const std::string color) const;
		void			printType(void) const;
		virtual void	makeSound(void) const;
		virtual void	printBrain(void);
		virtual void	printBrain(int index);
		int				getId(void) const;
		std::string		getType(void) const;
		void			setType(const std::string& type);

		Animal(void);
		Animal(const Animal& ref);
		Animal& operator=(const Animal& ref);
		virtual ~Animal(void);
};

#endif