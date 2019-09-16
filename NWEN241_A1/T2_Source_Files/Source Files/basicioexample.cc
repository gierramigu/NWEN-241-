#include <iostream>
#include <cstdlib> 	/* for exit()*/

int main()
{
      std::cout << "Enter your age: " << std::endl;  	 /* use the insertion operator on cout to print text to the monitor */

      int age;
      std::cin >> age; 				 /* use the extraction operator on cin to get input from the user   */

      if (age <= 0)    {
         std::cerr << "Oops, you entered an invalid age!" << std::endl; /* use the insertion operator on cerr to print an error message  */
         exit(1);
       }

      std::cout << "You entered " << age << " years old" << std::endl; 		/* use insertion again on cout to print a result */

      return 0;
}
