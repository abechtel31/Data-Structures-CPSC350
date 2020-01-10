#include "classicgrid.h"

ClassicGrid:: ClassicGrid(): Grid() //classic grid default constructor inherited from the grid class
{
}

ClassicGrid::ClassicGrid(int rows, int columns, double gridDensity): Grid(rows, columns, gridDensity) //overloaded constructor inherited from the grid class
{
}

ClassicGrid::ClassicGrid(const ClassicGrid& classicGrid): Grid(classicGrid)//copy constructor inherited from the grid class
{
}

ClassicGrid::~ClassicGrid()=default; //default destructor from the base class grid

void ClassicGrid::updateShadowGrid()//overriden method from the base class of updating the shadow grid
{
  for(int i=0; i<rows; ++i){
    for(int j=0; j<columns; ++j){
      shadowGrid[i+1][j+1]=grid[i][j];
    }
  }
}
