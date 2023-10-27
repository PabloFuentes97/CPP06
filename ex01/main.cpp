#include "Serializer.hpp"

int	main(void)
{
	Data *data = new Data();
	std::cout << data << std::endl;
	Serializer	serial;
	uintptr_t	s = serial.serialize(data);
	Data *desData = serial.deserialize(s);
	std::cout << desData << std::endl;
	return (0);
}