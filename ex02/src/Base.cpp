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
    std::srand(std::time(0));
    int randomValue = std::rand() % 3;

    switch (randomValue) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}

void Base::identify(Base *p) {
    if ((dynamic_cast<A *>(p))) {
        std::cout << "this is an A\n";
    }
    if ((dynamic_cast<B *>(p))) {
        std::cout << "this is a B\n";
    }
    if ((dynamic_cast<C *>(p))) {
        std::cout << "this is a C\n";
    }
    delete p;
}