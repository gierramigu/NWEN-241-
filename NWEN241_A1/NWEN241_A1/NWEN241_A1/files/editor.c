/**
 * editor.c
 *
 * You must implement the functions in editor.h in this file.
 * Consult the assignment handout for the detailed specifications of each of the functions.
 *
 * Student ID: gierramigu
 * Name: Miguel Gierran
 */
#include <stdio.h>
#include "editor.h"
#include <stdlib.h>
#include <string.h>

// this main method calls the various from below with its specific parameters
int main(){
char editing_buffer[EDITING_BUFLEN] = "The quick brown fox\0";

//task 1
int r = editor_insert_char(editing_buffer, 's', 9);

//task 2
//int r = editor_delete_char(editing_buffer, 'f', 10 );

//task 3
// int r = editor_replace_str(editing_buffer, "brown", "blue", 0);
// char *pointer = NULL;

}


//task 1
int editor_insert_char(char *editing_buffer, char to_insert, int pos){

	//return 0 if no insertion occurs or position to insert is invalid
    if (pos < 0 || pos > EDITING_BUFLEN || to_insert == '\0'){
      printf("INVALID\n");
      return 0;
    }

  //editing_buflen array size = 2000
    for(int i = EDITING_BUFLEN-2; i >= pos-1; i--){
      editing_buffer[i+1] = editing_buffer[i];
    }
    editing_buffer[pos] = to_insert;

    for(int i = 0; i >= EDITING_BUFLEN ; i++){
    printf("%s", editing_buffer[i]);
    }
    return 1;

  }



//task 2
int editor_delete_char(char *editing_buffer, char to_delete, int offset){

  //returns 0 if no index is available
	if (offset < 0 || offset > EDITING_BUFLEN || to_delete == '\0'){
		printf("INVALID\n");
		return 0;
	}
		for (int i = offset; i <= EDITING_BUFLEN; i++) {
			if (editing_buffer[i] == to_delete) {
				for (int j = i; j <= EDITING_BUFLEN-1; j++){
					editing_buffer[j] = editing_buffer[j+1];
				}
        break;
			}
		}
    printf("%s\n", editing_buffer);
  	return 1;
}




//task 3

int editor_replace_str(char *editing_buffer, const char *str, const char *replacement, int offset){

  if(replacement == "\0" || offset > EDITING_BUFLEN || offset < 0 ){
    return 0;
  }

  char *pointer = strstr(editing_buffer, str );
  int startingPosition = pointer - editing_buffer;

  printf("%s\n", editing_buffer);
  if(pointer!=NULL){
    //iterating through the string of characters that we want to remove which at this case would be brown
      for(int i =0; i <= strlen(str); i++){
        editor_delete_char(editing_buffer, str[i], offset); //delete the characters in strlen(str)
      }

    //iterating through the stirng of characters that we want to insert which is the given parameter.
      for(int i=0;  i <= strlen(replacement); i++){
       editor_insert_char(editing_buffer,  replacement[i], offset +(pointer+i));   //replace the current word with a new one by using the insert char method
      }
  }
    printf("%s\n", editing_buffer);
    return 1;

}
