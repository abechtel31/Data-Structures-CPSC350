#include "donutgrid.h"

DonutGrid::DonutGrid(): Grid() //mirror grid default constructor inherited from the grid class
{
}

DonutGrid::DonutGrid(int rows, int columns, double gridDensity): Grid(rows, columns, gridDensity) //overloaded constructor inherited from the grid class
{
}

DonutGrid::DonutGrid(const DonutGrid& donutGrid): Grid(donutGrid) //copy constructor inherited from the grid class
{
}

DonutGrid::~DonutGrid() = default; //default destructor from the base class grid

void DonutGrid::updateShadowGrid()//overriden method from the base class of updating the shadow grid
{
  for(int i=0; i<rows; ++i){
    for(int j=0; j<0; ++j){
      shadowGrid[i+1][j+1]=grid[i][j];
    }
  }

  for(int i=1; i<(rows+1); ++i){
    shadowGrid[i][0]=grid[i-1][columns-1];
    shadowGrid[i][columns+1]=grid[i-1][0];
  }

  for(int j=1; j<(columns+1); ++j){
    shadowGrid[0][j]=grid[rows-1][j-1];
    shadowGrid[rows+1][j]=grid[0][j-1];
  }

  shadowGrid[0][0]=grid[rows-1][columns-1];
  shadowGrid[0][columns+1]=grid[rows-1][0];
  shadowGrid[rows+1][0]=grid[0][columns-1];
  shadowGrid[rows+1][columns+1]=grid[0][0];
}
