#pragma once
#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP
#include <iostream>
#include "Data.hpp"

class Serializer
{
	private:


	public:
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer &	operator=(Serializer const & rhs);
		~Serializer();
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};
#endif