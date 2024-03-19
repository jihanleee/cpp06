#ifndef Serializer_HPP
# define Serializer_HPP
# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer {
	public:
		Serializer();
		virtual ~Serializer() = 0;
		Serializer(const Serializer & a);
		Serializer & operator = (const Serializer & a);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif