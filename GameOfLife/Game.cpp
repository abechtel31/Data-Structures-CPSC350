#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <ctime>
#include "game.h"
#include "grid.h"
#include "classicgrid.h"
#include "donutgrid.h"
#include "mirrorgrid.h"

using namespace std;

//default game constructor creating a new classic grid with an automatic output method
Game::Game() : grid(new ClassicGrid()), output('a')
{
}

//overloaded game constructor taking a grid and an output method as an argument
Game::Game(Grid* grid, char output) : grid(grid), output(output)
{
}

//copy constructor for the game class
Game::Game(const Game& game)
: grid(game.grid), output(game.output)
{
}

//destructor for the game class
Game::~Game()
{
  delete grid;
}

//the start method to begin a simulation of the game
void Game::start()
{
switch (output)
{
  case 'a': //automatic output
  {
    cout << "Generation: " << grid->getGeneration()<<endl;
    grid->printGrid();
    cout<<endl;
    while (grid->genPossible())
    {
      sleep(2); // sleeps for 2 seconds
      grid->nextGen();
      cout << "Generation: " << grid->getGeneration() << endl;
      grid->printGrid();
      cout << endl;
    }
    cout << "Grid is stable or empty." << endl;
    break;
  }
  case 'm': //manual output
  {
    cout << "Generation: " << grid->getGeneration() << endl;
    grid->printGrid();
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores characters other then newline
    while (grid->genPossible())
    {
      cout << "Press enter for next generation: ";
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores characters other then newline
      grid->nextGen();
      cout << "Generation: " << grid->getGeneration() << endl;
      grid->printGrid();
      cout << endl;
    }
    cout << "Grid is stable or empty." << endl;
    break;
    }
    case 'f': //file output
    {
      string outFileName;
      ofstream outFile;
      cout << "Enter a file to output the grid generations to: ";
      cin >> outFileName;
      cout << endl;
      outFile.open(outFileName, ios::app);

      while (!(outFile.is_open()))
      {
        outFile.close();
        outFile.clear();
        cout << "Error opening file. Enter a file to output the grid generations to: ";
        cin >> outFileName;
        cout << endl;
        outFile.open(outFileName, ios::app);
      }

      outFile << "Generation: " << grid->getGeneration() << endl;
      grid->gridToFile(outFile);
      while (grid->genPossible())
      {
        grid->nextGen();
        outFile << "Generation: " << grid->getGeneration() << endl;
        grid->gridToFile(outFile);
      }
      outFile << "Grid is stable or empty." << endl;
      outFile.close();
      break;
    }
    default:
      cout << "Invalid output method" << endl;
  }
}

//sleeps the progrmam for the specified number of seconds
void Game::sleep(int seconds)
{
  clock_t t;
  t = clock() + (seconds * CLOCKS_PER_SEC);
  while (clock() < t)
  {
  }
}
