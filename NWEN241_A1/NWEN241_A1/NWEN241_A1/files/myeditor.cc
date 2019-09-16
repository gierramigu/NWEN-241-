/**
 * myeditor.cc
 *
 * You must implement the member functions, including constructors, of your class defined in myeditor.hh.
 * Consult the assignment handout for the detailed specifications of each of the member functions.
 *
 * Student ID: 300411917
 * Name:Miguel Gierran
 */
#include <iostream>
#include <string>
#include <cstring>
#include "myeditor.hh"
using namespace std;

//task 6
bool MyEditingBuffer::replace(char c, char replacement, int offset){

  if(offset < 0 || offset > BUFFER_LEN || c =='\0' || replacement == '\0' ){
      return false;
    }

  for(int i = offset; i <= BUFFER_LEN; i++){
    if(buffer[i] ==c){
      buffer[i] = replacement;
      std::cout << (buffer) << "\n";
      return true;
    }
  }
return true;

}

//task 7
int MyEditingBuffer::replace(std::string str, std::string replacement, int offset){

      if(offset > BUFFER_LEN || offset < 0 || replacement == '\0'){
          return 0;
      }

      //converting buffer to string so we can use find and replace methods in c string
      std::string stringBuffer = buffer;
      int wordPosition = 0;
      wordPosition = stringBuffer.find(str,offset);
      //std::cout << wordPosition << "\n";
      stringBuffer.replace(wordPosition, str.length(), replacement);
      std::cout << stringBuffer << "\n";

      //Putting this back into buffer and reset it
      char buffer[BUFFER_LEN +1];
      strcpy(buffer, stringBuffer.c_str()); //gets the arrayList we want and the arraylist we want to copy
      std::cout << buffer << "\n";
      int index =  wordPosition + replacement.length();
      //std::cout << stringBuffer << "\n";
      std::cout << str  << "\n";
      std::cout << index << "\n";

      return index;
}

void MyEditingBuffer::justify(char **viewingBuffer, int rows, int cols){

}


//main method
int main(){

  //task 6
  MyEditingBuffer mEB;
  mEB.setBuffer("The quick brown fox \0", BUFFER_LEN);
  mEB.replace('b', 'B', 0);
  return 0;

  //task 7
  // MyEditingBuffer mEB;
  // mEB.setBuffer("The quick brown fox \0", BUFFER_LEN);
  // std::string s("brown");
  // std::string t("violet");
  // mEB.replace(s, t, 8);


  //task 8

}
