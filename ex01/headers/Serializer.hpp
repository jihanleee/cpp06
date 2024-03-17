#ifndef Serializer_HPP
# define Serializer_HPP
# include <iostream>
# include <string>
# include <cstdint>

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif