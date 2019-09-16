/**
 *  Implement the functions in editor2.h in this file.
 *
 */



#include <stdio.h>
#include <string.h>
#include "editor2.h"

//task 7

int editor_count_lines(const char *edit_buffer, int sizeOfBuffer){

int count = 0;
  for(int i = 0; i >= sizeOfBuffer; i++){
    if(*(edit_buffer[i]) == '\n'){ //checking if there's a new line everytime
      count++;
    }
  }
  printf("The amount of char in this line is: %d\n",count);
  return count;
}
