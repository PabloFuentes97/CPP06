#pragma once

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &	operator=(ScalarConverter const & rhs);
		static int	checkChar(std::string type);
		static int	checkInt(std::string type);
		static int	checkFloat(std::string type);
		static int	checkDouble(std::string type);
		static int	checkType(std::string type);
		static void	convertChar(std::string type);
		static void	convertInt(std::string type);
		static bool	checkSpecialCases(std::string type, std::string cases[]);
		static void	convertFloat(std::string type);
		static void	convertDouble(std::string type);
	public:
		static void	convert(std::string type);
};

int		countCharStr(std::string str, char c);

#endif