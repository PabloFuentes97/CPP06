#include "ScalarConverter.hpp"
#include <limits>

int	main(int argc, char **argv)
{
	{
		if (argc != 2)
			return (1);

		std::cout << "String introduced: " << argv[1] << std::endl;

		ScalarConverter	sC;

		sC.convert(argv[1]);
		return (0);
	}
}