#include "Data.hpp"
#include "Serializer.hpp"

int	main()
{
	Data* ptr = new Data;
	ptr->str = "lechat";
	std::cout << ptr->str << std::endl;
	uintptr_t i = Serializer::serialize(ptr);
	Data* string = Serializer::deserialize(i);
	std::cout << string->str << std::endl;
}