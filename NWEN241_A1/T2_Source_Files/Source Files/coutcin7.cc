#include <iostream>

int main ()
{
  std::cout.setf(std::ios::showpos); // turn on the std::showpos flag
  std::cout << 27 << '\n';

  return 0;
}
