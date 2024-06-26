#include "app.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    b2e::App app = {};
    
    try
    {
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}