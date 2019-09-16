/**
 * dbms.hh
 */

#include <iostream>
#include "string.h"
#include <cstring>

namespace dbms{

  struct album {
  unsigned long id;
  char title[100];
  unsigned short year;
  char artist[100];
  //class DbTable;
};

  class DbTable{
  private:
    album *table;
    unsigned int rowsTotal;
    unsigned int rowsUsed;

  public:
    DbTable(); //constructor
    ~DbTable(); //destructor, Note: Destructors don't take any arguments and doesn't return anything
    bool show(unsigned int); //task 5
    bool add(album &); //task 6
    inline unsigned int allocated(){ return rowsTotal; }
    inline unsigned int rows(){ return rowsUsed; }    //implement in cc
  };

}
