#pragma once
#ifndef ABSTRACTDBTABLE_H
#define ABSTRACTDBTABLE_H
#include <iostream>
#include "cstring"

#endif

namespace dbms2
{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };

    class AbstractDbTable{

    public:
      virtual int rows() = 0;
      virtual bool show(unsigned int) = 0;
      virtual bool add(movie&) = 0;
      virtual bool remove(unsigned long) =0;
      virtual const movie* get(unsigned int) = 0;
      bool loadCSV(const char *infn);
      bool saveCSV(const char *outfn);

    };
}
