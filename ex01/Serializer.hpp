#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string>
#include "iostream"
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
	Serializer();
	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	~Serializer();
};
#endif