/**
 *  Implement the functions in dbms.hh into this file.
 */

#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>

#include "dbms.hh"

using namespace dbms;
using namespace std;

//constructor
DbTable::DbTable(){
  table = (album*) malloc (5*sizeof(album));
  rowsTotal = 5;
  rowsUsed = 0;
}


//destructor
DbTable::~DbTable () {
  free(table);
}

//task 5 show() function
bool DbTable::show(unsigned int findRow){
  //if the row is less than the rowsUsed then the record exists so print out the information
  if(findRow <= rowsUsed){
      album *c = table+findRow; //initializing pointer
      std::cout << "Print: " << c->id << c->title << c->year << c->artist << std::endl;
      return true;
  }
  return false;
}

//task 6
bool DbTable::add(album &row){
      if (rowsUsed >= rowsTotal){ //if rowsUsed is greater than the total then it means theres no more allocated space in the table
        table = (album *) realloc (table, (rowsTotal+5)*sizeof(album)); //reallocate the memory of the table, increase the size of the dynamic allocated array
        table[rowsUsed] = row;
        rowsUsed++;
        rowsTotal+=5;
        return true;
      }
      //add row into table
      else if (rowsUsed < rowsTotal) {
        table[rowsUsed] = row;
        rowsUsed++;
        return true;
      }
    return false;
}
