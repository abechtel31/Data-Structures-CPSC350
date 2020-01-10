#ifndef GAME_H
#define GAME_H

#include"grid.h"
#include"donutgrid.h"
#include"donutgrid.h"
#include"mirrorgrid.h"

class Game{
public:
  Game(); //default constructor for the game class
  Game(Grid* grid, char output); //overloaded cosntructor for the game class given the arguments of a grid and an outpu
  Game(const Game& game); //copy constructor for the game class
  ~Game();//default constructor for the game class
  void start(); //start method to begin a game
  void sleep(int sec);//pause method given a time in seconds as an argument

private:
  Grid* grid;
  char output;
};

#endif
