/*
Abby Bechtel
abechtel@chapman.edu
2312284
CPSC 350-03
Assignment 1 - main.cpp
*/

/*
This program takes the name of a file
consisting of nucleotides/bigrams as a command line argument.
It reads the files contents to calculate statistics.
It then generates 1000 dna strings of random length (using the previously calculated statistics)
and outputs the dna strings to a .out file
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include "nucleotide.h"

using namespace std;

const double pi = 3.1415926535897;
double lineCount = 0;
double sum;
double mean;
double varience;
double deviation;
double probA, probT, probC, probG, probAA, probAT, probAC, probAG, probCA, probCC, probCG, probCT, probTA, probTC, probTT, probTG, probGA, probGT, probGC, probGG;

int main(int argc, char **argv)
{
  //error handling if a file is not entered as an argument
	if(argc < 2)
	{
		cout << "A file name was not entered as an argument" << endl;
		return 0;
	}

	ifstream inputFile;
  string inputString;

	inputFile.open(argv[1]);

	srand(time(NULL));

	if(inputFile.is_open())
	{

		//calculates sum and counts the number of lines
		while(inputFile.good())
		{
			getline(inputFile, inputString);

			countNucleotide(inputString);
			countBigram(inputString);
			sum += inputString.length();
			lineCount++;
		}

	}

	inputFile.close();

	inputFile.open(argv[1]);


	if(inputFile.is_open())
	{
		mean = sum/lineCount; //calculates the mean

		//calculates the varience
		while(inputFile.good())
		{
			getline(inputFile, inputString);
			varience += calcVar(inputString.length(), mean, lineCount);
		}

		deviation = pow(varience, 0.5);

	}
	inputFile.close();

	probA = probA / sum;
	probT = probT / sum;
	probC = probC / sum;
	probG = probG / sum;
  probAA = probAA / sum;
  probAT = probAT / sum;
  probAC = probAC / sum;
  probAG = probAG / sum;
  probCA = probCA / sum;
  probCT = probCT / sum;
  probCC = probCC / sum;
  probCG = probCG / sum;
  probGA = probGA / sum;
  probGT = probGT / sum;
  probGC = probGC / sum;
  probGG = probGG / sum;
  probTA = probTA / sum;
  probTT = probTT / sum;
  probTC = probTC / sum;
  probTG = probTG / sum;

	writeStats();

	for(int i = 0; i < 1000; ++i)
	{
		double C = calcLen(mean, varience);
		double D = rint((pow(varience, 0.5) * C) + mean);
		write(generateDNA(D, probA, probC, probG, probT) + " ");
	}

	return 0;
}

//counts the number of each nucleotide
void countNucleotide(string s)
{
  for(int i = 0; i < s.length(); ++i)
  {
    if (toupper(s[i]) == 'A') probA++;
    else if (toupper(s[i]) == 'C') probC++;
    else if (toupper(s[i]) == 'T') probT++;
    else if (toupper(s[i]) == 'G') probG++;
  }
}

//counts the number of each bigram
void countBigram(string s)
{
	for(int i = 0; i < s.length(); i += 2)
	{
		if (toupper(s[i]) == 'A' && toupper(s[i+1]) == 'A') probAA++;
		else if (toupper(s[i]) == 'A' && toupper(s[i+1]) == 'C') probAC++;
		else if (toupper(s[i]) == 'A' && toupper(s[i+1]) == 'T') probAT++;
		else if (toupper(s[i]) == 'A' && toupper(s[i+1]) == 'G') probAG++;
    else if (toupper(s[i]) == 'C' && toupper(s[i+1]) == 'A') probCA++;
    else if (toupper(s[i]) == 'C' && toupper(s[i+1]) == 'C') probCC++;
    else if (toupper(s[i]) == 'C' && toupper(s[i+1]) == 'T') probCT++;
    else if (toupper(s[i]) == 'C' && toupper(s[i+1]) == 'G') probCG++;
    else if (toupper(s[i]) == 'G' && toupper(s[i+1]) == 'A') probGA++;
    else if (toupper(s[i]) == 'G' && toupper(s[i+1]) == 'C') probGC++;
    else if (toupper(s[i]) == 'G' && toupper(s[i+1]) == 'T') probGT++;
    else if (toupper(s[i]) == 'G' && toupper(s[i+1]) == 'G') probGG++;
    else if (toupper(s[i]) == 'T' && toupper(s[i+1]) == 'A') probTA++;
    else if (toupper(s[i]) == 'T' && toupper(s[i+1]) == 'C') probTC++;
    else if (toupper(s[i]) == 'T' && toupper(s[i+1]) == 'T') probTT++;
    else if (toupper(s[i]) == 'T' && toupper(s[i+1]) == 'G') probTG++;
	}
}

//converts a double to a string
string toString(double num)
{
  ostringstream temp;
  temp << num;

  return temp.str();
}

//creates and writes a string to a .out file
void write(string tofile)
{
  ofstream myfile;

  myfile.open ("bechtel.out", ios_base::app);
  myfile << tofile;
  myfile.close();
}


//calculates varience
double calcVar(double x, double y, double n)
{
  double var;

  var += pow((x-y),2.0);
  var = var * (1/n);
  return var;
}

//calculates the random length of a dna string
double calcLen(double mean, double varience)
{
  double a, b, c;

	a = rand() % 100;
	b = rand() % 100;
	a = a / 100.00;
	b = b / 100.00;
	c = pow(((-2.0)*log(a)), 0.5);
	c *= cos(2.0*pi*b);

	return c;
}

//generates a dna string of nucleotides using the each nucleotides probability
string generateDNA(int len, double probA, double probC, double probG, double probT)
{
  string dna;

	double a = probA * 100;
	double c = (probC * 100) + a;
	double g = (probG * 100) + c;
	double t = (probT * 100) + g;

	for(int i = 0; i < len; ++i)
	{
		int r = rand() % 100;
		if(r <= a) dna.append("A");
		else if(r > a && r <= c) dna.append("C");
		else if(r > c && r <= g) dna.append("G");
		else dna.append("T");
	}

	return dna;
}

//writes the statistics to a .out file
void writeStats()
{
	write("Name: Abby Bechtel\n");
	write("ID: 2312281\n");
	write("- Assignment 1 - \n\n");
	write("Sum: " + toString(sum) + "\n");
	write("Mean: " + toString(mean) + "\n");
	write("Varience: " + toString(varience) + "\n");
	write("Standard Deviation: " + toString(deviation) + "\n");
	write("Probability of A: " + toString(probA*100) + "%" + "\n");
	write("Probability of T: " + toString(probT*100) + "%" + "\n");
  write("Probability of C: " + toString(probC*100) + "%" + "\n");
  write("Probability of G: " + toString(probG*100) + "%" + "\n\n");
  write("Probability of AA: " + toString(probAA*100) + "%" + "\n");
  write("Probability of AT: " + toString(probAT*100) + "%" + "\n");
  write("Probability of AC: " + toString(probAC*100) + "%" + "\n");
  write("Probability of AG: " + toString(probAG*100) + "%" + "\n");
  write("Probability of CA: " + toString(probCA*100) + "%" + "\n");
  write("Probability of CT: " + toString(probCT*100) + "%" + "\n");
  write("Probability of CC: " + toString(probCC*100) + "%" + "\n");
  write("Probability of CG: " + toString(probCG*100) + "%" + "\n");
  write("Probability of GA: " + toString(probGA*100) + "%" + "\n");
  write("Probability of GT: " + toString(probGT*100) + "%" + "\n");
  write("Probability of GC: " + toString(probGC*100) + "%" + "\n");
  write("Probability of GG: " + toString(probGG*100) + "%" + "\n");
  write("Probability of TA: " + toString(probTA*100) + "%" + "\n");
  write("Probability of TT: " + toString(probTT*100) + "%" + "\n");
  write("Probability of TC: " + toString(probTC*100) + "%" + "\n");
  write("Probability of TG: " + toString(probTG*100) + "%" + "\n\n");
}
