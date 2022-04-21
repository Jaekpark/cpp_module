#ifndef BRAIN_H
#define BRAIN_H

#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define MAGENTA	"\033[0;35m"
#define CYAN	"\033[0;36m"
#define EOC		"\033[0m"
#define BOLD	"\033[1m"
#define SIZE	100
#define WIDTH	18


#include <iostream>
#include <string>
#include <iomanip>
#include <istream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <cstdlib>

class	Brain {
	private:
		std::string ideas_[SIZE];

	public:
		void	setIdea(const int& index, const std::string& idea);
		void	randomString(void);
		void	setBrain(void);
		void	printBrain(int& id, std::string& type);
		void	printBrainIdea(int &id, std::string &type, int index);
		void	printLog(const std::string str, const std::string color) const;
		void	printLog(const std::string str) const;
		void	printPanel(const std::string str, const std::string color, int width);
		void	printPanel(const std::string str, const std::string color);
		void	printPanel(const std::string str);
		Brain(void);
		Brain(const Brain& ref);
		Brain& operator=(const Brain& ref);
		~Brain(void);
};

#endif