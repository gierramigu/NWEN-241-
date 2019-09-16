#include <iostream>
/*
  NOTE: this file was written to demonstrate the use of the flag functions
  in Stadard C++ in a Mac environment. You will need to remove the 'ios::'
  for it to compile in other environments
*/
int main()
{
    std::cout.setf (std::ios::showpos);
    std::cout << 27 << '\n';

    std::cout.setf (std::ios::showpos | std::ios::uppercase);
    std::cout << 27 << '\n';

    std::cout.setf (std::ios::showpos);
    std::cout << 27 << '\n';
    std::cout.unsetf (std::ios::showpos);
    std::cout << 28 << '\n';

    std::cout.setf (std::ios::hex);
    std::cout << 27 << '\n';

    std::cout.unsetf (std::ios::dec);
    std::cout.setf (std::ios::hex);
    std::cout << 27 << '\n';

    std::cout << std::hex << 27 << '\n';
    std::cout << 28 << '\n';
    std::cout << std::dec << 29 << '\n';

    return 0;
}
