#include <iostream>

int main (void){

  std::cout << "Enter a character: ";

  // Then we'll use the extraction operator on cin to get input from the user
  char c;
  std::cin >> c;

  // Otherwise we'll use insertion again on cout to print a result
  std::cout << "You entered: " << c << std::endl;

}
