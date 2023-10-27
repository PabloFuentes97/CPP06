#include "Serializer.hpp"

Serializer::Serializer(void)
{
	//std::cout << "Default Serializer Constructor" << std::endl;
}
	
	
Serializer::Serializer(Serializer const & src)
{
	//std::cout << "Copy Serializer Constructor" << std::endl;
	*this = src;
	return ;
}

Serializer::~Serializer()
{
	//std::cout << "Serializer Destructor" << std::endl;
}

Serializer &	Serializer::operator=(Serializer const & rhs)
{
	//std::cout << "Serializer assignation operator called" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	s;

	s = reinterpret_cast<uintptr_t>(ptr);
	return (s);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	Data *dS;

	dS = reinterpret_cast<Data *>(raw);
	return (dS);
}