#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include"IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materia[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &object);
		~MateriaSource(void);
		MateriaSource &operator=(const MateriaSource &object);

		void learnMateria(AMateria *meteria);
		AMateria *createMateria(std::string const & type);
};

#endif