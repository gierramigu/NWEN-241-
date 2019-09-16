#include <iostream>

int main()
{
  std::cout.setf(std::hex); // try to turn on hex output
  std::cout << 27 << '\n';
  std::cout.unsetf(std::dec); // turn off decimal output
  std::cout.setf(std::hex); // turn on hexadecimal output
  std::cout << 27 << '\n';

return 0;
}
