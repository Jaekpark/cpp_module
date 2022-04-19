#include "Brain.hpp"

void		Brain::printPanel(const std::string str, const std::string color, int width) {
	std::cout << BOLD << "[" << color << std::setw(width) << str << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		Brain::printPanel(const std::string str, const std::string color) {
	std::cout << BOLD << "[" << color << std::setw(WIDTH) << str << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		Brain::printPanel(const std::string str) {
	std::cout << BOLD << "[" << std::setw(WIDTH) << str << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		Brain::printLog(const std::string str, const std::string color) const {
	std::cout << std::setw(7) << "| " <<  color << str << EOC << std::endl;
}

void		Brain::printLog(const std::string str) const {
	std::cout << std::setw(7) << "| " << str << EOC << std::endl;
}

void		Brain::randomString(void) {
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	std::string temp;
	int num;

	for (int i = 0; i < SIZE; i++) {
		temp = "";
		for (int j = 0; j < 5; j++) {
			num = rand() % (str.length() - 1);
			temp += str[num];
		}
		ideas_[i] = temp;
	}
}

void	Brain::setBrain(void) {
	std::ifstream	input("./word", std::ifstream::in);
	std::string 	temp[251];
	int 			index = 0;
	int				num;

	if (input.fail()) {
		randomString();
		return ;
	}
	while (std::getline (input, temp[index])) {
		index++;
	}
	input.close();
	if (index != 250) {
		randomString();
		return ;
	}
	for (int i = 0; i < SIZE; i++) {
		num = rand() % 250;
		setIdea(i, temp[num]);
	}
}

void	Brain::setIdea(const int& index, const std::string& idea) {
	ideas_[index] = idea;
}

void	Brain::printBrain(int& id, std::string& type) {
	std::stringstream ss;
	std::string name;
	std::string index;
	
	ss << id;
	name = ss.str();
	name += " ";
	name += type;
	for (int i = 0; i < SIZE; i++) {
		ss.str("");
		ss << i;
		index = "ideas ";
		index += ss.str();
		printPanel(name, YELLOW);
		printPanel("Function Log", CYAN);
		printPanel(index, MAGENTA);
		printLog(ideas_[i]);
	}
}

void	Brain::printBrainIdea(int &id, std::string &type, int index) {
	std::stringstream ss;
	std::string name;
	std::string idea;
	
	ss << id;
	name = ss.str();
	name += " ";
	name += type;
	if (index >= SIZE || index < 0) {
		printPanel(name, YELLOW);
		printPanel("Function Log", CYAN);
		printPanel("Print Idea", MAGENTA);
		printLog("index out of range. (available 0 to 99)");
		return ;
	}
	ss.str("");
	ss << index;
	printPanel(name, YELLOW);
	printPanel("Function Log", CYAN);
	name = "idea ";
	name += ss.str();
	name += " [";
	ss.str("");
	ss << &ideas_[index];
	name += ss.str();
	name += "] : ";
	name += ideas_[index];
	printPanel("Print Idea", MAGENTA);
	printLog(name);
}

Brain::Brain(void) {
	setBrain();
	std::cout << "default brain created." << std::endl;
}

Brain::Brain(const Brain& ref) {
	for (int i = 0; i < SIZE; i++) {
		setIdea(i, ref.ideas_[i]);
	}
	std::cout << "brain copied." << std::endl;
}

Brain& Brain::operator=(const Brain& ref) {
	if (this != &ref) {
		for (int i = 0; i < SIZE; i++)
			setIdea(i, ref.ideas_[i]);
	}
	std::cout << "brain assigned." << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "brain deleted." << std::endl;
}