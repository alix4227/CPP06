#include "ScalarConverter.hpp"

bool	isDouble(std::string input)
{
	if (input == "nan" || input == "+inf" || input == "-inf")
		return (true);
	std::stringstream str(input);
	double check;
	char c;
	if (str >> check && !(str >> c))
		return(true);
	return (false);
}

bool	isFloat(std::string input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return (true);
	std::stringstream str(input);
	float check;
	std::string c;
	if (str >> check && (str >> c))
	{
		if (c[0] == 'f' && c[1] == 0)
			return(true);
	}
	return (false);
}

bool	isInteger(std::string input)
{
	int len = input.size();
	int i = 0;
	while (i < len)
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

void	ScalarConverter::convert(std::string input)
{
	int size = input.size();
	
	if (size == 1 && isalpha(input[0]))
	{
		std::cout << "char: " << input[0] << std::endl;
		int i = static_cast <int> (input[0]);
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast <float> (i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast <double> (i) << std::endl;
	}
	
	else if (size >= 1 && isInteger(input))
	{
		int i;
		std::stringstream ss(input);
		ss >> i;
		std::cout << "char: " << static_cast <char> (i) << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast <float> (i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast <double> (i) << std::endl;
	}
	else if (size >= 1 && isFloat(input))
	{
		float i;
		std::stringstream ss(input);
		ss >> i;
		if (i == 0)
		{
			std::string str[3] = {"nanf", "+inff", "-inff"};
			float f[3] = {NAN, INFINITY, -INFINITY};
			int j = 0;
			while (j < 3)
			{
				if (input == str[j])
				{
					i = f[j];
					std::cout << "char: " << "impossible" << std::endl;
					std::cout << "int: " << "impossible" << std::endl;
					break ;
				}
				j++;
			}
		}
		else if (!std::isinf(i) || !std::isnan(i))
		{
			std::cout << "char: " << static_cast <char> (i) << std::endl;
			std::cout << "int: " << static_cast <int> (i) << std::endl;
		}
		std::cout << "float: " << std::fixed << std::setprecision(1) << i << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast <double> (i) << std::endl;
		
	}
	else if (size >= 1 && isDouble(input))
	{
		double i;
		std::stringstream ss(input);
		ss >> i;
		if (i == 0)
		{
			std::string str[3] = {"nan", "+inf", "-inf"};
			float f[3] = {NAN, INFINITY, -INFINITY};
			int j = 0;
			while (j < 3)
			{
				if (input == str[j])
				{
					i = f[j];
					std::cout << "char: " << "impossible" << std::endl;
					std::cout << "int: " << "impossible" << std::endl;
					break ;
				}
				j++;
			}
		}
		else if (!std::isinf(i) || !std::isnan(i))
		{
			std::cout << "char: " << static_cast <char> (i) << std::endl;
			std::cout << "int: " << static_cast <int> (i) << std::endl;
		}
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast <float> (i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << i << std::endl;
	}
}