#ifndef DONUTGRID_H
#define DONUTGRID_H

#include "grid.h"

class DonutGrid: public Grid{
public:
  DonutGrid();//donut grid default constructor inherits from the grid class
  DonutGrid(int rows, int columns, double gridDensity); //donut grid overloaded constructor with the arguments of rows, columns, and gridDensity
  DonutGrid(const DonutGrid& donutGrid); //copy constructor of the donut grid class
  ~DonutGrid() override; //overriden destructor from the grid base class
  void updateShadowGrid() override; //overriden method from the grid class to update the shadow grid
};

#endif
