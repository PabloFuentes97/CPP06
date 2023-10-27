#include "Serializer.hpp"

int	main(void)
{
	Data *data = new Data();
	std::cout << "Data inicial: " << data << std::endl;
	Serializer	serial;
	uintptr_t	s = serial.serialize(data);
	std::cout << "Serialize: " << s << std::endl;
	Data *desData = serial.deserialize(s);
	std::cout << "Deserialize: " << desData << std::endl;
	return (0);
}