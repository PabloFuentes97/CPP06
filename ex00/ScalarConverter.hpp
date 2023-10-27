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
		int		checkChar(std::string type);
		int		checkInt(std::string type);
		int		checkFloat(std::string type);
		int		checkDouble(std::string type);
		int		checkType(std::string type);
		void	convertChar(std::string type);
		void	convertInt(std::string type);
		bool	checkSpecialCases(std::string type, std::string cases[]);
		void	convertFloat(std::string type);
		void	convertDouble(std::string type);
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &	operator=(ScalarConverter const & rhs);
		void	convert(std::string type);
};

int		countCharStr(std::string str, char c);

#endif