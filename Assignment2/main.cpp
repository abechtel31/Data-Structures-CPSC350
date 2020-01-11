#include <iostream>
#include <string>
#include <limits>
#include "game.h"
#include "grid.h"
#include "classicgrid.h"
#include "donutgrid.h"
#include "mirrorgrid.h"
#include "Exception.h"

int main(int argc, char** argv)
{
  srand(static_cast<int>(time(nullptr))); //producing new random number each time the program is run

  Game* game;
  Grid* grid;

  string configChoice;
  string modeChoice;
  char outputChoice;

  int rows = 0;
  int columns = 0;
  double gridDensity = 1.0;

  cout << "You are begining the Game of Life! 12 hours of my life that I'll never get back" << endl;

  // configuration choice
  cout << "How would you like configure the program: \n1 - manually enter the grid \n2 - take a grid configuration from a file\n";
  cin >> configChoice;
  while ((configChoice != "1") && (configChoice != "2"))
  {
    cout << "Invalid input! Try again." << endl;
    cout << "Would you like configure the program: \n1 - manually enter the grid \n2 - take a grid configuration from a file\n";
    cin >> configChoice;
  }

  // output choice
  cout << "How would you like the grid outputed: \na - automatic output\nm - manual output\nf - file output\n";
  cin >> outputChoice;
  while ((outputChoice != 'a') && (outputChoice != 'm') && (outputChoice != 'f'))
  {
    cout << "Invalid input! Try again." << endl;
    cout << "How would you like the grid outputed: \na - automatic output\nm - manual output\nf - file output\n";;
    cin >> outputChoice;
  }

  // mode choice
  cout << "What mode would you like: \nc - classic mode\nd- donut mode\nm - mirror mode\n";
  cin >> modeChoice;
  while ((modeChoice != "c") && (modeChoice != "d") && (modeChoice != "m"))
  {
    cout << "Invalid input! Try again." << endl;
    cout << "What mode would you like: \nc - classic mode\nd- donut mode\nm - mirror mode\n";;
    cin >> modeChoice;
  }

  if (configChoice == "1")
  {
    // rows
    cout << "Enter a number of rows (if r <= 0, r = 1): ";
    cin >> rows;
    while (!(cin)) // if they don't enter a positive int
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // meed to flush out the new line
      cout << "Enter a number of rows (if r <= 0, r = 1): ";
      cin >> rows;
    }
    if (rows <= 0)
    {
      rows = 1;
    }

    // columns
    cout << "Enter a number of columns (if c <= 0, c = 1): ";
    cin >> columns;
    while (!(cin)) // if they don't enter a positive int
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // meed to flush out the new line
      cout << "Enter a number of columns (if c <= 0, c = 1): ";
      cin >> columns;
    }
    if (columns <= 0)
    {
      columns = 1;
    }

    // grid density
    cout << "Enter a grid density (0 < p <= 1, if p <= 0 or p > 1, p = 1): ";
    cin >> gridDensity;
    while (!(cin)) // if they don't enter a positive int
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // meed to flush out the new line
      cout << "Enter a grid density (0 < p <= 1, if p <= 0 or p > 1, p = 1): ";
      cin >> gridDensity;
    }
    if ((gridDensity <= 0) || (gridDensity > 1))
    {
      gridDensity = 1;
    }

    // creating grids based on mode preference
    if (modeChoice == "c")
    {
      grid = new ClassicGrid(static_cast<int>(rows), static_cast<int>(columns), gridDensity);
    }
    else if (modeChoice == "d")
    {
      grid = new DonutGrid(static_cast<int>(rows), static_cast<int>(columns), gridDensity);
    }
    else if (modeChoice == "m")
    {
      grid = new MirrorGrid(static_cast<int>(rows), static_cast<int>(columns), gridDensity);
    }
    else
    {
      grid = new ClassicGrid();
    }

    game = new Game(grid, outputChoice);
    game->start();
  }

  else if (configChoice == "2")
  {
    string inFileName;
    ifstream inFile;

    cout << "Enter the file name: ";
    cin >> inFileName;

    inFile.open(inFileName);

    while (!(inFile)) // if the map file is invalid
    {
      inFile.close();
      inFile.clear();
      cout << "Invalid file name" << endl;
      cout << "Enter the file name to input: ";
      cin >> inFileName;
      inFile.open(inFileName);
    }

    // generating grids from user mode choice
    if (modeChoice == "c")
    {
      grid = new ClassicGrid();
    }
    else if (modeChoice == "d")
    {
      grid = new DonutGrid();
    }
    else if (modeChoice == "m")
    {
      grid = new MirrorGrid();
    }
    else
    {
      grid = new ClassicGrid();
    }

    try
    {
      grid->fileToGrid(inFile);
    }
    catch (Exception& err)
    {
      cout << err.getErr() << endl;
      cout << "Ending program" << endl;
      delete grid;
      return 1;
    }
    inFile.close();

    game = new Game(grid, outputChoice);
    game->start();
  }
  else
  {
    grid = new ClassicGrid();
    game = new Game(grid, outputChoice);
    game->start();
  }
  delete game;
  return 0;
}
