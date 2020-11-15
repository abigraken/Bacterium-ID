// Title: hackumbc.cpp
// Author: Abigail Kennedy
// Date: 11/14/2020
// Description: This is the main file for my HackUMBC project
#include "identify.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int arg, char* argv[]) {
  srand(time(NULL)); // Seeds the random number generator
  cout << "Welcome!" << endl;
  while (arg < 2) { // Ensure the user passes a file
    cout << "Please load in a datafile." << endl;
    return 0;
  }
  Identify myID(argv[1]); // Creates a new ID, passing the file name
  myID.Start(); // Starts the program
  return 0;
}
