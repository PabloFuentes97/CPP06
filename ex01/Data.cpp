#include "Data.hpp"

Data::Data(void)
{
	//std::cout << "Default Data Constructor" << std::endl;
}
	
	
Data::Data(Data const & src)
{
	//std::cout << "Copy Data Constructor" << std::endl;
	*this = src;
	return ;
}

Data::~Data()
{
	//std::cout << "Data Destructor" << std::endl;
}

Data &	Data::operator=(Data const & rhs)
{
	//std::cout << "Data assignation operator called" << std::endl;
	return (*this);
}