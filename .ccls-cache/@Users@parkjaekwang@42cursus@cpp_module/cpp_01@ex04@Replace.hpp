#ifndef REPLACE_H
#define REPLACE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class	Replace {
	private:
		Replace(void);

	public:
		static void	replaceWord(std::string *str, const std::string &s1, const std::string &s2);
		static void	replaceFile(const std::string& file, const std::string& s1, const std::string& s2);
		Replace(const std::string& file, const std::string& s1, const std::string& s2);
		~Replace(void);
};

#endif
