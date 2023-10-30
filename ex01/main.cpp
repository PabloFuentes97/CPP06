#include "Serializer.hpp"

int	main(void)
{
	Data *data = new Data();
	std::cout << "Data inicial: " << data << std::endl;
	uintptr_t	s = Serializer::serialize(data);
	std::cout << "Serialize: " << s << std::endl;
	Data *desData = Serializer::deserialize(s);
	std::cout << "Deserialize: " << desData << std::endl;
	delete data;
	system("leaks -q Serializer");
	return (0);
}