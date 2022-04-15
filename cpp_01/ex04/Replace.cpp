#include "Replace.hpp"

void	Replace::replaceWord (std::string *str, const std::string& s1, const std::string& s2) {
	std::size_t found = 0;
	std::string	result;
	std::string after;
	
	if (!str || s1.empty() || s2.empty())
		return ;
	while (true) {
		found = (*str).find(s1, found);
		if (found == std::string::npos)
			break ;
		result = (*str).substr(0, found);
		result += s2;
		after = (*str).substr(found + s1.length());
		found += s2.length();
		result += after;
		(*str) = result;
	}
}

void	Replace::replaceFile(const std::string& file, const std::string& s1, const std::string& s2) {
	std::ifstream input;
	std::ofstream output;
	std::stringstream ss;
	std::string temp;

	if (file.empty() || s1.empty() || s2.empty()) {
		std::cerr << "Empty string." << std::endl;
		exit(1);
	}
	input.open(file);
	if (input.fail()) {
		std::cerr << "File does not exists" << std::endl;
		exit(1);
	}
	ss << input.rdbuf();
	input.close();
	temp = ss.str();
	replaceWord(&temp, s1, s2);
	output.open(file + ".replace", std::ofstream::out | std::ofstream::trunc);
	if (output.fail()) {
		std::cerr << "Open failed." << std::endl;
		exit(1);
	}
	output << temp;
	output.close();
}

Replace::Replace(void) {}

Replace::Replace(const std::string& file, const std::string& s1, const std::string& s2) {
	replaceFile(file, s1, s2);
}

Replace::~Replace(void) {}