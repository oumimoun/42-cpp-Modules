#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _templates[4];
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &other);
	virtual ~MateriaSource(void);
	MateriaSource const &operator=(MateriaSource const &other);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);

};

#endif
