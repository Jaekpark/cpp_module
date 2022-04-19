#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

#define ROBOT_NAME	"RotobomyRequestForm"
#define ROBOT_SIGN	72
#define ROBOT_EXEC	45

class RobotomyRequestForm : public Form {
	private:
		RobotomyRequestForm(void);

	public:
		void					execute(const Bureaucrat& executor) const;
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& ref);

		explicit RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& r);
		~RobotomyRequestForm(void);
};

#endif