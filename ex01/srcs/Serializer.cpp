#include "Serializer.hpp"

Serializer::Serializer() {
	/*constructor*/
}

Serializer::Serializer(const Serializer & a) {
	/*copy constructor*/
	(void) a;
}

Serializer & Serializer::operator = (const Serializer & a) {
	/*copy assignment operator*/
	(void) a;
	return(*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
