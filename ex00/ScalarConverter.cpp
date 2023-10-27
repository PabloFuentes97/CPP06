#include "ScalarConverter.hpp"

	ScalarConverter::ScalarConverter(void)
	{
		//std::cout << "Default ScalarConverter Constructor" << std::endl;
	}
	
	
	ScalarConverter::ScalarConverter(ScalarConverter const & src)
	{
		//std::cout << "Copy ScalarConverter Constructor" << std::endl;
		*this = src;
		return ;
	}

	ScalarConverter::~ScalarConverter()
	{
		//std::cout << "ScalarConverter Destructor" << std::endl;
	}

	ScalarConverter &	ScalarConverter::operator=(ScalarConverter const & rhs)
	{
		//std::cout << "ScalarConverter assignation operator called" << std::endl;
		return (*this);
	}

	int	ScalarConverter::checkChar(std::string type)
	{
		if (type.length() > 1)
			return (0);
		if (type[0] < 32 || type[0] > 127) {
			std::cout << "Non printable character" << std::endl;
			return (0); }
		if ((type[0] >= 'A' && type[0] <= 'Z') || (type[0] >= 'a' && type[0] <= 'z'))
			return (1);
		return (0);
	}

	int	ScalarConverter::checkInt(std::string type)
	{
		int	len = type.length();
		
		if (!((type[0] >= '0' && type[0] <= '9') || type[0] == '+' || type[0] == '-'))
			return (0);
		for (int i = 1; i < len; i++)
		{
			if (!((type[i] >= '0' && type[i] <= '9') && (type[0] != '+' || type[0] != '-')))
				return (0);
		}
		return (1);
	}

	int		countCharStr(std::string str, char c)
	{
		int	count = 0;
		int	len = str.length();
	
		for (int i = 0; i < len; i++)
		{
			if (str[i] == c)
				count++;
		}
		return (count);
	}

	int	ScalarConverter::checkFloat(std::string type)
	{	
		int	len = type.length();
		
		std::string specialCases[3] = {"-inff", "+inff", "nanf"};

		for (int i = 0; i < 3; i++)
		{
			if (!type.compare(specialCases[i]))
				return (1);
		}
		if (countCharStr(type, '.') != 1)
			return (0);
		if (!(((type[0] >= '0' && type[0] <= '9') || type[0] == '+' || type[0] == '-')
				&& type[len - 1] == 'f'))
			return (0);
		for (int i = 1; i < len - 1; i++)
		{
			if (type[i] < '0' && type[i] > '9' && type[i] != '.')
				return (0);
		}
		return (1);
	}

	int	ScalarConverter::checkDouble(std::string type)
	{
		int	len = type.length();
		
		std::string specialCases[3] = {"-inf", "+inf", "nan"};

		for (int i = 0; i < 3; i++)
		{
			if (!type.compare(specialCases[i]))
				return (1);
		}
		if (countCharStr(type, '.') != 1)
			return (0);

		if (!((type[0] >= '0' && type[0] <= '9') || type[0] == '+' || type[0] == '-'))
			return (0);	
		for (int i = 1; i < len; i++)
		{
			if (type[i] < '0' && type[i] > '9' && type[i] != '.')
				return (0);
		}
		return (1);
	}

	int	ScalarConverter::checkType(std::string type)
	{
		int	(ScalarConverter::*checker[4])(std::string) = {&ScalarConverter::checkChar, 
				&ScalarConverter::checkInt, &ScalarConverter::checkFloat, &ScalarConverter::checkDouble};
		
		int	ret;

		for (int i = 0; i < 4; i++)
		{
			ret = (this->*checker[i])(type);
			if (ret == 1)
				return (i + 1);
		}
		return (0);
	}

	void	ScalarConverter::convertChar(std::string type)
	{
		char	c = type[0];
		
		std::cout << "Char: '" << c << "'" << std::endl;
		std::cout << "Int: " << static_cast<int>(c) << std::endl;
		std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;
	}

	void	ScalarConverter::convertInt(std::string type)
	{
		const char	*cArr = type.c_str();
		int			cInt = atoi(cArr);
		long double	cNum = atof(cArr);
		
		//char
		if (cNum < 32 || cNum > 127)
			std::cout << "Char: impossible" << std::endl;
		else
			std::cout << "Char: '" << static_cast<char>(cInt) << "'" << std::endl;
		//int 
		if (cNum < INT_MIN || cNum > INT_MAX)
			std::cout << "Int: impossible" << std::endl;
		else
			std::cout << "Int: " << cInt << std::endl;
		//float
		if (cNum < __FLT_MAX__ * -1 || cNum > __FLT_MAX__ )
			std::cout << "Float: impossible" << std::endl;
		else
			std::cout << "Float: " << static_cast<float>(cInt) << ".0f" <<std::endl;
		//double
		if (cNum < __DBL_MAX__ * -1 || cNum > __DBL_MAX__ )
			std::cout << "Double: impossible" << std::endl;
		else
			std::cout << "Double: " << static_cast<double>(cInt) << ".0" << std::endl;
	}

	bool	ScalarConverter::checkSpecialCases(std::string type, std::string cases[])
	{
		for (int i = 0; i < 3; i++)
		{
			if (!type.compare(0, cases[i].length(), cases[i]))
			{
				std::cout << "Char: impossible" << std::endl;
				std::cout << "Int: impossible" << std::endl;
				std::cout << "Float: " <<  cases[i] + "f" << std::endl;
				std::cout << "Double: " << cases[i] << std::endl;
				return (true);
			}
		}
		return (false);
	}
	void	ScalarConverter::convertFloat(std::string type)
	{
		const char	*cArr = type.c_str();
		float		cFloat = atof(cArr);
		long double	cNum = atof(cArr);
		
		std::string specialCases[3] = {"-inf", "+inf", "nanf"};
		if (checkSpecialCases(type, specialCases))
			return ;
		//char
		if (cNum < 32 || cNum > 127)
			std::cout << "Char: impossible" << std::endl;
		else
			std::cout << "Char: '" << static_cast<char>(cFloat) << "'" << std::endl;
		//int 
		if (cNum < INT_MIN || cNum > INT_MAX)
			std::cout << "Int: impossible" << std::endl;
		else
			std::cout << "Int: " << static_cast<int>(cFloat) << std::endl;
		//float
		if (cNum < __FLT_MAX__ * -1 || cNum > __FLT_MAX__ )
			std::cout << "Float: impossible" << std::endl;
		else
			std::cout << "Float: " << cFloat << "f" << std::endl;
		//double
		if (cNum < __DBL_MAX__ * -1 || cNum > __DBL_MAX__ )
			std::cout << "Double: impossible" << std::endl;
		else
			std::cout << "Double: " << static_cast<double>(cFloat) << std::endl;
	}

	void	ScalarConverter::convertDouble(std::string type)
	{
		const char	*cArr = type.c_str();
		long double	cNum = atof(cArr);
		double 		cDouble = atof(cArr);
	
		std::string specialCases[3] = {"-inf", "+inf", "nan"};
		if (checkSpecialCases(type, specialCases))
			return ;
		//char
		if (cNum < 32 || cNum > 127)
			std::cout << "Char: impossible" << std::endl;
		else
			std::cout << "Char: '" << static_cast<char>(cDouble) << "'" << std::endl;
		//int 
		if (cNum < INT_MIN || cNum > INT_MAX)
			std::cout << "Int: impossible" << std::endl;
		else
			std::cout << "Int: " << static_cast<int>(cDouble) << std::endl;
		//float
		if (cNum < __FLT_MAX__ * -1 || cNum > __FLT_MAX__ )
			std::cout << "Float: impossible" << std::endl;
		else
			std::cout << "Float: " << static_cast<float>(cDouble) << "f" <<std::endl;
		//double
		if (cNum < __DBL_MAX__ * -1 || cNum > __DBL_MAX__ )
			std::cout << "Double: impossible" << std::endl;
		else
			std::cout << "Double: " << cDouble << std::endl;
	}

	void	ScalarConverter::convert(std::string type)
	{
		switch (this->checkType(type))
		{
			//invalid type
			case 0:
			{
				std::cout << "Invalid type format" << std::endl;
				break ;
			}
			//char type
			case 1:
			{
				std::cout << "It's a char type!" << std::endl;
				this->convertChar(type);
				break ;
			}
			//int type
			case 2:
			{
				std::cout << "It's a int type!" << std::endl;
				this->convertInt(type);
				break ;
			}
			//float type
			case 3:
			{
				std::cout << "It's a float type!" << std::endl;
				this->convertFloat(type);
				break ;
			}
			//double type
			case 4:
			{
				std::cout << "It's a double type!" << std::endl;
				this->convertDouble(type);
				break ;
			}
		}
	}
