#include <iostream>

int main ()
{
  std::cout << true << " " << false << '\n';

  std::cout.setf(std::boolalpha);
  std::cout << true << " " << false << '\n';

  std::cout << std::noboolalpha << true << " " << false << '\n';

  std::cout << std::boolalpha << true << " " << false << '\n';

  return 0;
}
