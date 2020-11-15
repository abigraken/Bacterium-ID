// Name: identify.h
// Author: Abigail Kennedy
// Date: 11/14/2020
// Description: The header file for identify

#include "bacteria.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Identify {
 public:
  // Name: Identify (Constructor)
  // Desc: Creates a new ID and sets the filename based on what was passed
  // Precon: Input file passed
  // Postcon: Identify created
  Identify(string);
  // Name: Identify (Destructor)
  // Desc: Destroys all items in identify
  // Precon:
  // Postcon:
  ~Identify();
  // Name: LoadFile
  // Desc: Loads in a new file
  // Precon:
  // Postcon:
  void LoadFile();
  // Name: Menu
  // Desc: Displays the menu and the menu choices
  // Precon:
  // Postcon: Returns choice
  int Menu();
  // Name: Start
  // Desc: Starts the ID program
  // Precon:
  // Postcom:
  void Start();
  // Name: ID
  // Desc: IDs the item
  // Precon: Item exists
  // Postcon: Item has been IDd
  void IDMenu();
  // Name: Display
  // Desc: Displays all available items
  // Precon: Items exist
  // Postcon: Items have been displayed
  void Display();

  void GramID();
  int ShapeID();
  void AcidfastID();
  void CatalaseID();
  void MorphologyID();
  void ClusterID();
  void ID();

 private:
  vector<Bacteria*> m_ID; // List of all potential IDs
  string m_filename;
};
