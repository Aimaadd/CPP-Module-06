#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::Base() {
    std::cout << "Base constructor called" << std::endl;
}

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

Base *Base::generate() {
    srand(time(0));
    int randomValue = std::rand() % 3;

    switch (randomValue) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void Base::identify(Base *p) {
    try {
        if (p == NULL)
            throw std::bad_cast();
        if (dynamic_cast<A *>(p)) {
            std::cout << "this is an A\n";
        } else if (dynamic_cast<B *>(p)) {
            std::cout << "this is a B\n";
        } else if (dynamic_cast<C *>(p)) {
            std::cout << "this is a C\n";
        } else {
            std::cout << "Unknown type\n";
        }
    } catch (const std::bad_cast& e) {
        std::cerr << "Bad cast: " << e.what() << std::endl;
    }
    delete p;
}

void Base::identify(Base &p) {
    try {
        if (dynamic_cast<A *>(&p)) {
            std::cout << "this is an A\n";
        } else if (dynamic_cast<B *>(&p)) {
            std::cout << "this is a B\n";
        } else if (dynamic_cast<C *>(&p)) {
            std::cout << "this is a C\n";
        } else {
            std::cout << "Unknown type\n";
        }
    } catch (const std::bad_cast& e) {
        std::cerr << "Bad cast: " << e.what() << std::endl;
    }
}