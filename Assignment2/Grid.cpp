#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "grid.h"
#include "Exception.h"

using namespace std;

Grid::Grid() //default grid constructor
{
  rows=1;
  columns=1;
  gridDensity=1.0;
  generation=0;
}

Grid::Grid(int rows, int columns, double gridDensity)//constructor for a grid of size row*column and a gridDensity
{
  this->rows=rows;
  this->columns=columns;
  this->gridDensity=gridDensity;
  generation=0;
  generateGrid(rows, columns, gridDensity);

}

Grid::Grid(const Grid& grid) //copy constructor for a grid
{
  rows=grid.rows;
  columns=grid.columns;
  gridDensity=grid.gridDensity;
  generation=0;
  generateGrid(grid.rows, grid.columns, grid.gridDensity);
}

Grid::~Grid() //destructor for the grid class
{
  for (int i = 0; i < rows; ++i)
  {
    delete[] grid[i];
    delete[] histGrid[i];
    delete[] shadowGrid[i];
  }

  delete[] grid;
  delete[] histGrid;
  delete[] shadowGrid;
}

void Grid::printGrid()//prints the grid
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < columns; ++j){
      cout << grid[i][j];
    }
    cout<<endl;
  }
  cout << "\n" << endl;
}

void Grid::gridToFile(ofstream& outfile)//takes an output file stream as an argument and puts the grid into a file
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < columns; ++j)
    {
      outfile << grid[i][j];
    }
    outfile << endl;
  }
  cout << "\n" << endl;
}

bool Grid::genPossible()//checks to see if the next generation is possible
{
  int matched = 0;
  int empty = 0;
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < columns; ++j){
      if(grid[i][j] == histGrid[i][j]){
        ++matched;
      }
      if (grid[i][j] == '-'){
        ++empty;
      }
    }
  }
  return !(((matched == (rows * columns)) && generation > 0) || (empty == (rows * columns)));
}

void Grid::fileToGrid(ifstream& infile){ //take a file input stream and converts it to a grid if possible
  string line;
  int lineCount = 0;
  int columns = 1;
  int rows = 1;
  int rowNum = 0;
  int columnNum = 0;
  int aliveNum = 0;
  int deadNum = 0;

  while(getline(infile, line)){
    if (isNumeric(line) && (lineCount == 0)){
      rows = stoi(line);
    }
    else if (isNumeric(line) && (lineCount == 1)){
      columns = stoi(line);
      grid = new char*[rows];
      histGrid = new char*[rows];
      for (int i = 0; i < rows; ++i){
        grid[i] = new char[columns];
        histGrid[i] = new char[columns];
      }
    }
    else if ((rows > 0) && (columns > 0) && (line.size() == columns) && (lineCount > 1 && lineCount <= (rows + 1))){
      for (char c : line){
        if (c == 'X'){
          ++aliveNum;
          grid[rowNum][columnNum] = 'X';
          histGrid[rowNum][columnNum] = 'X';
        }
        else if (c == '-'){
          ++deadNum;
          grid[rowNum][columnNum] = '-';
          histGrid[rowNum][columnNum] = '-';
        }
        else{
          throw Exception("File improperly formatted.");
        }
        ++columnNum;
      }
      columnNum = 0;
      ++rowNum;
    }
    else if ((line.size() != columns) && (lineCount > 1 && lineCount <= (rows + 1))){
      throw Exception("Invalid columns.");
    }
    else if (lineCount > (rows + 1)){
      continue;
    }
    else if (rowNum > rows){
      throw Exception("Invalid rows.");
    }
    else{
      grid = new char *[rows];
      histGrid = new char *[rows];
      for (int i = 0; i < rows; ++i){
        grid[i] = new char[columns];
        histGrid[i] = new char[columns];
      }
      throw Exception("File improperly formatted.");
    }
    ++lineCount;
  }
  double gridDensity = (static_cast<double>(aliveNum)) / (deadNum);

  this->rows = rows;
  this->columns = columns;
  this->gridDensity = gridDensity;

  generation=0;

  shadowGrid = new char*[rows + 2];
  for (int i = 0; i < (rows + 2); ++i){
    shadowGrid[i] = new char[columns + 2];
    for (int j = 0; j < (columns + 2); ++j){
      shadowGrid[i][j] = '-';
    }
  }
  updateShadowGrid();
}

void Grid::nextGen(){ //calculating the next generation
    int neighbors = 0;
    copyToHistGrid();
    updateShadowGrid();

    for (int i = 0; i < rows; ++i){
      for (int j = 0; j < columns; ++j)
      {
        if (shadowGrid[i][j] == 'X')//top left
        {
          ++neighbors;
        }
        if (shadowGrid[i][j+1] == 'X')//top
        {
          ++neighbors;
        }
        if (shadowGrid[i][j+2] == 'X')//top right
        {
          ++neighbors;
        }
        if (shadowGrid[i+1][j] == 'X')//left
        {
          ++neighbors;
        }
        if (shadowGrid[i+1][j+2] == 'X')//right
        {
          ++neighbors;
        }
        if (shadowGrid[i + 2][j] == 'X')//bottom left
        {
          ++neighbors;
        }
        if (shadowGrid[i + 2][j + 1] == 'X')//bottom
        {
          ++neighbors;
        }
        if (shadowGrid[i + 2][j + 2] == 'X')//bottom right
        {
          ++neighbors;
        }

        //debugging cout<<neighbors<<endl;
        if ((neighbors <= 1) || (neighbors >= 4))
        {
          grid[i][j] = '-';
        }
        else if ((neighbors == 3) && (grid[i][j] != 'X'))
        {
          grid[i][j] = 'X';
        }
      neighbors = 0;
    }
  }
  ++generation;
}

int Grid::getGeneration() //accessor for the generation number
{
    return generation;
}

void Grid::copyToHistGrid() //copies the current grid to the history grid
{
  for (int i = 0; i < rows; ++i){
    delete[] histGrid[i];
  }
  delete[] histGrid;
  histGrid = new char*[rows];
  for (int i = 0; i < rows; ++i){
    histGrid[i] = new char[columns];
    for (int j = 0; j < columns; ++j){
      histGrid[i][j] = grid[i][j];
    }
  }
}


bool Grid::isNumeric(string& s) //determines if the contents of a string are numeric
{
  if ((s.empty())){
    return false;
  }
  for (char c : s){
    if (!(isdigit(c))){
      return false;
    }
  }
  return true;
}

void Grid::generateGrid(int rows, int columns, double gridDensity) //generates the next generation of the grid
{
  //local variables
  int count = 0;
  double random;
  srand(time(NULL));

  //2D arrays of pointers
  grid = new char*[rows];
  histGrid = new char*[rows];

  //iterating throught the 2D arrays
  for (int i = 0; i < rows; ++i)
  {
    grid[i] = new char[columns];
    histGrid[i] = new char[columns];

    //populating each row
    for (int j = 0; j < columns; ++j)
    {

      random = (double)rand() /(double)RAND_MAX;

      if (random <= gridDensity)
      {
        grid[i][j] = 'X';
        histGrid[i][j] = 'X';
        ++count;
      }
      else
      {
        grid[i][j] = '-';
        histGrid[i][j] = '-';
      }
    }
  }

  shadowGrid = new char*[rows + 2];
  for (int i = 0; i < (rows + 2); ++i)
  {
    shadowGrid[i] = new char[columns + 2];
    for (int j = 0; j < (columns + 2); ++j)
    {
      shadowGrid[i][j] = '-';
    }
  }
}
