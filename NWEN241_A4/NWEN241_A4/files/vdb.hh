#pragma once
#ifndef VECTORDBTABLE_H
#define VECTORDBTABLE_H
#include <vector>
#include "dbms2.hh"
#endif

using namespace dbms2;
  class VectorDbTable: public AbstractDbTable{

      //member functions
    private:
      std::vector<movie> movies;

    public:
      int rows();
      bool show(unsigned int) ;
      bool add(movie&);
      bool remove(unsigned long);
      const movie* get(unsigned int);
      VectorDbTable(); //constructor
      ~VectorDbTable(); //destructor
  };
