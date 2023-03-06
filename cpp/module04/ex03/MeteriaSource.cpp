#include"MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for(int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	std::cout << "MateriaSource created(default)" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &object)
{
	for(int i = 0; i < 4; i++)
		this->_materia[i] = object._materia[i];
	std::cout << "MateriaSource created(copy)" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for(int i = 0; i < 4; i++)
		delete this->_materia[i];
	std::cout << "MateriaSource destroyed" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &object)
{
	for(int i = 0; i < 4; i++)
		delete this->_materia[i];
	for(int i = 0; i < 4; i++)
		this->_materia[i] = object._materia[i];
	std::cout << "MateriaSource assigned" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *meteria)
{
	for(int i = 0; i < 4; i++)
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = meteria;
			std::cout << "MateriaSource learned " << meteria->getType() << std::endl;
			return;
		}
	std::cout << "MateriaSource is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
		{
			std::cout << "Meteria created " << type << std::endl;
			return (this->_materia[i]->clone());
		}
	std::cout << "cannot create meteria" << type << std::endl;
	return (NULL);
}
