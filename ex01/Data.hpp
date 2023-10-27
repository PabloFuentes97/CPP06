#pragma once
#ifndef DATA_HPP

#define DATA_HPP
#include <iostream>

class Data
{
	private:
		int	data;

	public:
		Data(void);
		Data(Data const &src);
		Data &	operator=(Data const & rhs);
		~Data();
};
#endif