#ifndef Base_HPP
# define Base_HPP
# include <iostream>
# include <fstream>
# include <exception>

class Base {
	public:
		virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif