#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
    public:
        Base();
        virtual ~Base();
        static Base *generate(void);
        static void identify(Base *p);
};

#endif