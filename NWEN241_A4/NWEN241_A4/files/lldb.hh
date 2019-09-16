
#include "dbms2.hh"
#include <iostream>

namespace dbms2{
  class LinkedListDbTable : public AbstractDbTable{

    LinkedListDbTable(); //constructor
    ~LinkedListDbTable(); //destructor

  public:
    int rows() = 0;
    bool show(unsigned int) = 0;
    bool add(movie&) = 0;
    bool remove(unsigned long) = 0;
    movie* get(unsigned int) = 0;
    bool loadCSV(const char *infn);
    bool saveCSV(const char *outfn);

  };
}
