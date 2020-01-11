#ifndef MIRRORGRID_H
#define MIRRORGRID_H

#include "grid.h"

class MirrorGrid : public Grid{
public:
  MirrorGrid(); //default mirror grid constructor
  MirrorGrid(int rows, int column, double gridDensity); //mirror grid overloaded constructor with the arguments of rows, columns, and gridDensity
  MirrorGrid(MirrorGrid& mirrorGrid); //mirror grid copy constructor
  ~MirrorGrid() override; //overriden destructor from the grid class for the mirror class
  void updateShadowGrid() override; // overridden method from the grid class to update the shadow grid
};

#endif
