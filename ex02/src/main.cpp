#include "../includes/Base.hpp"
#include "../includes/A.hpp"

int main() {
    Base *test = Base::generate();

    Base::identify(Base::generate());
    Base::identify(*test);
}