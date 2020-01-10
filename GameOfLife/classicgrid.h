#ifndef CLASSICGRID_H
#define CLASSICGIRD_H

#include "grid.h"

class ClassicGrid: public Grid{
public:
  ClassicGrid(); //ClassicGrid default constructor
  ClassicGrid(int rows, int columns, double gridDensity); //classic grid overloaded constructor with the arguments of rows, columns, and gridDensity
  ClassicGrid(const ClassicGrid& classicGrid); //copy constructor of the classic grid class
  ~ClassicGrid() override; //overriden destructor from the grid class for the classic grid class

  void updateShadowGrid() override;// overridden method from the grid class to update the shadow grid
};
#endif
