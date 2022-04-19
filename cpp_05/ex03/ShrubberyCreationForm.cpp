#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form() {
	setFormType(SHRU_NAME);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form(target, SHRU_SIGN, SHRU_EXEC) {
	setFormType(SHRU_NAME);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
	: Form(ref) {
	setFormType(SHRU_NAME);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void					ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	std::string tree =
	"	                                                         .\n"
	"                                             .         ;\n"
	"                 .              .              ;%     ;;   \n"
	"                   ,           ,                :;%  %; \n"  
	"                    :         ;                   :;%;'     .,  \n "
	"           ,.        %;     %;            ;        %;'    ,;\n"
	"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
	"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
	"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
	"                `%;.     ;%;     %;'         `;%%;.%;'\n"
	"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
	"                    `:%;.  :;bd%;          %;@%;'\n"
	"                      `@%:.  :;%.         ;@@%;'   \n"
	"                        `@%.  `;@%.      ;@@%;         \n"
	"                          `@%%. `@%%    ;@@%;        \n"
	"                            ;@%. :@%%  %@@%;       \n"
	"                              %@bd%%%bd%%:;     \n"
	"                                #@%%%%%:;;\n"
	"                                %@@%%%::;\n"
	"                                %@@@%(o);  . '         \n"
	"                                %@@@o%;:(.,'         \n"
	"                            `.. %@@@o%::;         \n"
	"                               `)@@@o%::;         \n"
	"                                %@@(o)::;        \n"
	"                               .%@@@@%::;         \n"
	"                               ;%@@@@%::;.          \n"
	"                              ;%@@@@%%:;;;. \n"
	"                          ...;%@@@@@%%:;;;;,.. \n";

	condition(executor);
	std::ofstream output(getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (output.fail())
		throw Form::FileFailedException();
	output << tree;
	output.close();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) {
	return *(dynamic_cast<ShrubberyCreationForm*>(&(Form::operator=(ref))));
}
