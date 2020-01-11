/*
Abby Bechtel
abechtel@chapman.edu
2312284
CPSC 350-03
Assignment 1 - header file
*/

#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <cstdlib>

using namespace std;

void countNucleotide(string fs);
void countBigram(string s);
string toString(double num);
void write(string tofile);

double calcVar(double x, double y, double n);
double calcLen(double mean, double varience);
string generateDNA(int len, double probA, double probC, double probG, double probT);
void writeStats();

#endif
