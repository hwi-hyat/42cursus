#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &object)
: AForm("ShrubberyCreationForm", 145, 137), _target(object._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &object)
{
	AForm::operator=(object);
	this->_target = object._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->isItSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	std::ofstream file;
	std::string filename = this->_target + "_shrubbery";
	file.open(filename);
	
	file
		<< "														 .\n"
		<< "									  .         ;\n"  
		<< "		 .              .              ;%     ;;\n"   
		<< "		   ,           ,                :;%  %;\n"   
		<< "			:         ;                   :;%;'     .,\n"   
		<< "   ,.        %;     %;            ;        %;'    ,;\n"
		<< "	 ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
		<< "	  %;       %;%;      ,  ;       %;  ;%;   ,%;'\n" 
		<< "	   ;%;      %;        ;%;        % ;%;  ,%;'\n"
		<< "		`%;.     ;%;     %;'         `;%%;.%;'\n"
		<< "		 `:;%.    ;%%. %@;        %; ;@%;%'\n"
		<< "			`:%;.  :;bd%;          %;@%;'\n"
		<< "			  `@%:.  :;%.         ;@@%;'\n"   
		<< "				`@%.  `;@%.      ;@@%;\n"         
		<< "				  `@%%. `@%%    ;@@%;\n"        
		<< "					;@%. :@%%  %@@%;\n"       
		<< "					  %@bd%%%bd%%:;\n"     
		<< "						#@%%%%%:;;\n"
		<< "						%@@%%%::;\n"
		<< "						%@@@%(o);  . '\n"         
		<< "						%@@@o%;:(.,'\n"         
		<< "					`.. %@@@o%::;\n"         
		<< "					   `)@@@o%::;\n"         
		<< "						%@@(o)::;\n"        
		<< "					   .%@@@@%::;\n"         
		<< "					   ;%@@@@%::;.\n"          
		<< "					  ;%@@@@%%:;;;.\n"
		<< "				  ...;%@@@@@%%:;;;;,..\n";
	
	file.close();
	std::cout << executor.getName() << " executes " << this->getName() << std::endl;
}

const char *ShrubberyCreationForm::CouldNotOpenFileException::what() const throw()
{
	return "FAILED TO OPEN FILE";
}
