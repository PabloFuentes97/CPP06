#include "funcs.hpp"

int	main(void)
{
	Base	*base = generate();
	Base	&baseRef = *base;

	identify(base);
	identify(baseRef);
	return (0);
}