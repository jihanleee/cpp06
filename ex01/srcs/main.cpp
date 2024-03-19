#include "Serializer.hpp"
#include "Data.hpp"

int main () {

	Data a;
	Data *deserialized;
	a.intData = 1;
	a.stringData = "i'm a string";
	uintptr_t raw;
	raw = Serializer::serialize(&a);
	std::cout << "serialized pointer: " << raw << std::endl;
	deserialized = Serializer::deserialize(raw);
	std::cout << "deserialized int data: " << deserialized->intData << std::endl;
	std::cout << "deserialized string data: " << deserialized->stringData << std::endl;
	return 0;
}
