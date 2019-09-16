
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
//#include "vdb.hh"
#include "dbms2.hh"


using namespace dbms2;
using namespace std;

bool AbstractDbTable::loadCSV(const char* infn){
  //Input file stream to read csv
movie m;
  FILE *csv;
  csv = fopen(infn, "r");

  //check for worse case
  if(csv == NULL || !csv){
    cout << "Failed to open infn.csv\n" << endl;
    return false;
  }

//
//   movie movie;
//   bool invalid = false;
//
//   //Parse CSV file and load the records
//   while(!csv.eof()){
//     string t;
//
//     if(!getline(csv, t, ',')) { //read line until ','
//       invalid = true;
//       break;
//     }
//     movie.id = stoul(t); //convert string to unsigned integer. Parses str and interprets it into an int.
//
//     if(!getline(csv, t, ',')){
//       invalid = true;
//       break;
//     }
//     strcpy(movie.title,t.c_str()); //char* strcpy(char* dest, const char* src)
//
//     if(!getline(csv, t, ',')){
//       invalid = true;
//       break;
//     }
//     movie.year = (unsigned short)stoul(t);
//
//     if(!getline(csv, t, ',')){
//       invalid = true;
//       break;
//     }
//     strcpy(movie.director,t.c_str()); //char* strcpy(char* dest, const char* src)
//
//     add(movie);
//   }
//
// //if its not invalid then return
//   if(!invalid){  return false;  }
  //check for first line
   int check = fscanf(csv, "%lu,%[^,],%hd,%[^\n]%*c", &m.id, m.title, &m.year, m.director); //uses file pointer FILE *csv;
   while (check >= 4){ //There should be 4 tokens on each line
           add(m);
           check = fscanf(csv, "%lu,%[^,],%hd,%[^\n]%*c", &m.id, m.title, &m.year, m.director); //Scan next line
       }

  //close
  fclose(csv);
  return true;
}

bool AbstractDbTable::saveCSV(const char *outfn){

  const struct movie *mov;
  FILE *f = fopen(outfn, "w");


  if(f == NULL){ //if file can't be opened
    cout << "Error\n" << endl;
    return false;
  }

  int row = 0;
  while(row < rows()){// while row is less than the movie size
    //get that line and print it out
    mov = get(row);
    string line = "";
    cout << "Print: " << mov[row].id << mov[row].title << mov[row].year << mov[row].director << endl;
    row++;
  }

  //close
  fclose(f);
  return true;
}
