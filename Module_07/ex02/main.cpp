#include "Array.hpp"
#include <ctime>
#include <cstdlib>                                      // For srand and rand
#include <iomanip>                                      // For std::setw
int main()
{
    srand(time(NULL));                                  // Seed for random number generator

    const int count = 6;

    Array<int> a(count);
    for (unsigned int i = 0; i < a.getSize(); i++)      // Fill array with random numbers 
        a[i] = rand() % 100 + 1;

    Array<std::string> c(count);
    c[0] = "hemosiderosis";
    c[1] = "occasionalism";
    c[2] = "serpentinization";
    c[3] = "overdecorated";
    c[4] = "naturalization";
    c[5] = "discombobulating";

    Array<int> b(a);                                    // Copy array of integers
    Array<std::string> d(c);                            // Copy array of strings

    std::cout << "\n" << GREEN << "Before modification:" << RST << std::endl;
    std::cout << std::left;
    std::cout << YELLOW
              << std::setw(5) << "a" 
              << std::setw(5) << "b" 
              << std::setw(25) << "c" 
              << std::setw(25) << "d" 
              << RST
              << std::endl;
    
    for (unsigned int i = 0; i < b.getSize(); i++)
    {
        std::cout << BLUE 
                  << std::setw(5) << a[i] 
                  << std::setw(5) << b[i] 
                  << std::setw(25) << c[i] 
                  << std::setw(25) << d[i] 
                  << RST
                  << std::endl;
    }
    for (unsigned int i = 0; i < a.getSize(); i++)
        a[i] = a[i] * 2;
    for (unsigned int i = 0; i < c.getSize(); i++)
        c[i] = c[i].append("_new").data();
    std::cout << std::left;
    
    std::cout << "\n" << GREEN << "After modification:" << RST << std::endl;
    std::cout << YELLOW
              << std::setw(5) << "a" 
              << std::setw(5) << "b" 
              << std::setw(25) << "c" 
              << std::setw(25) << "d" 
              << RST
              << std::endl;
    
    for (unsigned int i = 0; i < b.getSize(); i++)
    {
        std::cout << BLUE
                  << std::setw(5) << a[i] 
                  << std::setw(5) << b[i] 
                  << std::setw(25) << c[i] 
                  << std::setw(25) << d[i] 
                  << RST
                  << std::endl;
    }
    std::cout << std::endl;

    Array<int> ints;

    try
    {
        if (ints.getSize() > 0)
        {
            std::cout << ints[0] << std::endl;
        }
        else
        {
            std::cerr << RED << "Error: Array is empty" << RST << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RST << std::endl;
    }
}