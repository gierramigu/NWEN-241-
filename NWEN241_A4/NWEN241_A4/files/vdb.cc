
#include <cstring>
#include <iostream>

#include "vdb.hh"

using namespace dbms2;
using namespace std;

VectorDbTable::VectorDbTable(){
}

VectorDbTable::~VectorDbTable(){
}

int VectorDbTable::rows(){
   int size = movies.size(); // returns the size of the array.
   return size;
}

bool VectorDbTable::show(unsigned int rowNum){
    if(rowNum < rows()){
       std::cout << "Print: " << movies[rowNum].id << movies[rowNum].title << movies[rowNum].year << movies[rowNum].director << std::endl;
       return true;
     }
   return false;
}

bool VectorDbTable::add(movie &row){
//  movies = (movie *) realloc (movies, (rows()-5)*sizeof(movie));
  movies.push_back(row); //add the row into the end of the array using the push_back function specific for dynamic arrays
  return true;
}

bool VectorDbTable::remove(unsigned long IDnumber){

  //iterate through the array
  for( int i= 0; i < movies.size(); i++){
    if(movies[i].id == IDnumber ){
        movies.erase(movies.begin()+i); //remove from the vector
      return true;
    }
  }

  return false;
}

 const movie* VectorDbTable::get(unsigned int rowNum){
   return &movies[rowNum]; //returns the value at that row in the vector
 }
