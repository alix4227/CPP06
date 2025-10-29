#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
	private:
	ScalarConverter();
	public:
	static void convert(std::string input);
};
#endif