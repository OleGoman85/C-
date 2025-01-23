#include "Generator.hpp"
#include "Identify.hpp"
#include <unistd.h> //sleep
#include <iostream>

int main()
{
    srand(static_cast<unsigned>(time(0))); // Seed random generator once (start from 1 january 1970 year (Unix Epoch). (in seconds))

    Base* bases[5];

    for (int i = 0; i < 5; ++i)
    {
        bases[i] = generate();
        std::cout << "Using pointer: ";
        identify(bases[i]);
        std::cout << "Using reference: ";
        identify(*bases[i]);
        std::cout << "=========" << std::endl;
    }

    for (int i = 0; i < 5; ++i)
        delete bases[i];

    return 0;
}
