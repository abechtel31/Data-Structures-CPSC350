#ifndef GRID_H
#define GRID_H

#include<iostream>
#include<fstream>
#include<string>
#include "Exception.h"

using namespace std;

class Grid{
  public:
    Grid(); //default constructor for the grid
    Grid(int rows, int columns, double gridDensity); //overloaded constructor with arguments of rows, colunms, and gridDensity
    virtual ~Grid(); //virtual destructor in base class grid
    Grid(const Grid& Grid); //copy constructor
    void printGrid(); //method to print the grid
    bool genPossible(); //method to check if the next generation is possible
    void gridToFile(ofstream& outfile); //method to write the grid to a file
    void fileToGrid(ifstream& infile); //method to generate a grid from a file
    void nextGen(); //method to create the next generation of the grid
    int getGeneration(); //accessor for the grid's generation

  protected:
    char** grid;
    char** histGrid;
    char** shadowGrid;
    double gridDensity;
    int rows;
    int columns;
    int generation;

    void copyToHistGrid(); //copies the current grid to the history grid
    virtual void updateShadowGrid()=0;

  private:
    bool isNumeric(string& s); //checks if a string is a number
    void generateGrid(int rows, int columns, double gridDensity); //generates a grid
};

#endif
