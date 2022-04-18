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

void	Brain::setBrain(void) {
	std::ifstream	input("./word", std::ifstream::in);
	std::string 	temp[251];
	int 			index = 0;
	int				num;

	if (input.fail()) {
		std::cerr << "Error : Cannot open file." << std::endl;
		exit(1);
	}
	while (std::getline (input, temp[index])) {
		index++;
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

Brain::Brain(void) {
	setBrain();
	std::cout << "default brain created." << std::endl;
}

Brain::Brain(const Brain& ref) {
	for (int i = 0; i > SIZE; i++)
		setIdea(i, ref.ideas_[i]);
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