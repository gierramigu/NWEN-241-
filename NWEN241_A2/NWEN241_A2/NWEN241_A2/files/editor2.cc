/**
 *  Implement the functions in editor2.hh into this file.
 */

 #include <stdio.h>
 #include <string.h>
 #include "editor2.hh"

using namespace editor2;

//task 10
int EditorUtilities::countWords(const char *editing_buffer, int sizeOfBuffer){

  int words = 1;
  bool whitespace = false;

  for(int i = 0; i < sizeOfBuffer; i++ ){
    if(editing_buffer[i] == ' ' || editing_buffer[i] == '\t' || editing_buffer[i] == '\n' || editing_buffer[i] == '\v' || editing_buffer[i] == '\f' || editing_buffer[i] == '\r'){ //checking the first white space if it exists in the array
        whitespace == true;
      if(editing_buffer[i+1] == ' ' || editing_buffer[i+1] == '\t' || editing_buffer[i+1] == '\n' || editing_buffer[i+1] == '\v' || editing_buffer[i+1] == '\f' || editing_buffer[i] == '\r'){ //checking the second white space if it exists in the array
        whitespace == true;
          }
          else {
              words++; //increment words when it doesn't meet the previous conditions
              whitespace = false; //places back whitespace field into false and resets
          }
        }
    }
    std::cout << "Total Words in Array: " << words << '\n';
    std::cout << "size: " << sizeOfBuffer << '\n';
    return words;
}
