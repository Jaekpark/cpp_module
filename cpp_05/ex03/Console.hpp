#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define EOC "\033[0m"
#define BOLD "\033[1m"
#define WIDTH 18
#define CONS "Constructor"
#define DES "Destructor"
#define FUNC "Function"
#define COPY "Copy"
#define ASSG "Assignment"

#include <iostream>
#include <string>
#include <iomanip>

class Console {
	private:
		int id_;
	public:
		Console(void);
		Console(const Console& ref);
		~Console(void);
		Console&		operator=(const Console& ref);

		static void		header(std::string* title, int size);
		static void		pad(int size);
		static void		panel(std::string type);
		static void		panel(std::string type, const std::string color);
		static void		panel(std::string type, const std::string color, int width);
		static void		log(std::string log);
		static void		log(std::string log, const std::string color);
		static void		footer(void);
};

#endif