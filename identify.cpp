// Name: identify.cpp
// Author: Abigail Kennedy
// Date: 11/14/2020
// Description: The cpp file for identify

#include "identify.h"

Identify::Identify(string filename){ // Constructor
  m_filename = filename;
}

Identify::~Identify(){ // Destructor
  // Destroys all items in m_ID

  for (int i = 0; i < int(m_ID.size()); i++){
    delete m_ID.at(i); // Vector data deleted
    m_ID.at(i) = nullptr; // Set data to null
  }
}

void Identify::LoadFile(){
  // Opens the file and reads everything in

  // Open file
  ifstream identity;
  identity.open(m_filename);

  while(identity){
    // Variables
    string name = "";
    int gram = 0;
    char shapeChar = ' ';
    string shape = "";
    int acidfast = 0;
    int catalase = 0;
    string  morphology = "";
    string clusters = "";

    bool gramBool = false;
    bool acidfastBool = false;
    bool catalaseBool = false;

    // Read in the file
    // For all, read in the name, gram, and shape
          
    getline(identity, name, ','); // Get name
    identity >> gram; // Get gram + or - status
    if(identity.peek()== ','){
      identity.ignore();
    }
    identity >> shapeChar; // Gets the shape
    if(identity.peek()==','){
      identity.ignore();
    }
    
    // If shape is rods
    if (shapeChar == 'r'){
      shape = "Rods"; // Update shape
      
      identity >> acidfast; // Acidfast
      if (identity.peek() == ','){
	identity.ignore();
      }
      
      getline(identity, morphology, ','); // Morphology

      // Convert gram and acidfast strings to bools
      if (gram == 1) {
      	gramBool = true;
      }
      if (acidfast == 1) {
      	acidfastBool = true;
      }
      if (identity.peek() == '\n') { //End of line
	identity.ignore();
      }
      // Fill in others
      catalaseBool = false;
      clusters = "Regular clusters";
    }

    // If shape is cocci
    else if (shapeChar == 'c') { // Shape was cocci
      shape = "Cocci"; // Update shape
      
      // Catalase, Clusters
      identity >> catalase; // Catalaste type
      if (identity.peek() == ','){
        identity.ignore();
      }
      getline(identity, clusters, '\n'); // Cluster type
      if (identity.peek() == '\n'){
     	identity.ignore();
      }

      // Convert gram and acidfast strings to bools
      if (gram == 1) {
	gramBool = true;
      }
      if (catalase == 1) {
      catalaseBool = true;
      }
      if (identity.peek() == '\n') { //End of line
        identity.ignore();
      }
      // Fill in others
      acidfastBool = false;
      morphology = "Regular";
    }

    //For testing the file status
    /*        
    cout << "Name: " << name << endl
	 << "Gram: " << gramBool << endl
	 << "Shape: " << shape << endl
	 << "Acid fast: " << acidfastBool << endl
	 << "Catalse: " << catalaseBool << endl
	 << "Morphology: " << morphology << endl
	 << "Clusters: " << clusters << endl;
    */
    
    Bacteria* object = new Bacteria(name, gramBool, shape, acidfastBool, catalaseBool, morphology,clusters);
    m_ID.push_back(object); // Add to vector
  }
    
  // Vector is m_ID
  // Close file when done
  identity.close();
  
}

int Identify::Menu(){
  // Displays the menu and the choices
  int choice = 0;
  cout << "What would you like to do?" << endl
       << "1. ID a bacterium" << endl
       << "2. View bacteria available for ID" << endl
       << "3. Exit program" << endl;
  cin >> choice;

  while (choice < 1 || choice > 3) {
    cout << "Please enter a valid choice (1-3)" << endl;
    cin >> choice;
  }

  switch(choice) {
  case 1: { // ID a bacterium
    IDMenu();
    return 3; // End the program
  }
  case 2: { // Display bacteria
    Display();
    return 2;
  }
  case 3: { // Exit
    return 3;
  }
  }
  return 0; // We should never reach this
}

void Identify::Start(){
  // Starts the ID program
  int control = 0; // Controls the program

  LoadFile();

  // Under game conditions
  do {
    control = Menu();
  } while (control != 3);

  cout << "Thank you for using!" << endl;
}

void Identify::IDMenu(){
  // The menu from which an item is IDd
  int shape = 2;
  
  // Create the unnamed item
  Bacteria* object = new Bacteria(); // creates a default
  m_ID.push_back(object);

  // Add some if statements in here for the rods and cocci
  
  // Get the gram
  GramID();
  // Get the shape
  shape = ShapeID(); // 0 is rods, 1 is cocci

  if (shape == 0){
  // Get the acid-fast
  AcidfastID();
  // Get the morphology
  MorphologyID();
  }
  else if (shape == 1) {
  // Get the catalase
  CatalaseID();
  // Get the cluster type
  ClusterID();
  }
  else {
    cout << "Something went wrong." << endl;
  }
  
  // Call ID
  ID();

}

void Identify::GramID(){
  string response = "";
  bool answered = false;
  cout << "Is your bacteria Gram Positive or Gram Negative?" << endl;
  cin >> response;

  if (response == "positive" ||response == "Positive" ||
      response == "Gram Positive" || response == "Gram positive" ||
      response == "gram positive") {
    for (int i = 0; i < int(m_ID.size()); i++) {// Find Unnamed
      if (m_ID.at(i)->GetName() == "Unnamed") {
	// Update the gram bool to true
	m_ID.at(i)->SetGram(true);
      }
    }
  }
  else if (response == "negative" ||response == "Negative" ||
	   response == "Gram Negative" || response == "Gram negative" ||
	   response == "gram negative") {
    for (int i = 0; i < int(m_ID.size()); i++) {// Find Unnamed                
      if (m_ID.at(i)->GetName() == "Unnamed") {
	// Keep bool as false
        m_ID.at(i)->SetGram(false);
      }
    }
  }
  else{
    while (answered == false) {
      cout << "That is not a valid gram type." << endl
           << "Is your bacteria Gram Positive or Gram Negattive?" << endl;
      cin >> response;
      if (response == "positive" || response == "Positive" ||
          response == "Gram Positive" || response == "Gram positive" ||
	  response == "gram positive") {
        for (int i = 0; i < int(m_ID.size() ); i++) {
          if (m_ID.at(i)->GetName() == "Unnamed") {
            m_ID.at(i)->SetGram(true);
            answered = true;
          }
        }
      }
      else if (response == "negative" ||response == "Negative" ||
	       response == "Gram Negative" || response == "Gram negative" ||
	       response == "gram negative") {
	for (int i = 0; i < int(m_ID.size()); i++) {// Find Unnamed 
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    // Keep bool as false                    
	    m_ID.at(i)->SetGram(false);
	  }
	}
      }      
    }
  } 
}

int Identify::ShapeID() {
  string response = "";
  bool answered = false;

  cout << "What is the shape of your bacteria? Rods or Cocci?" << endl;
  cin >> response;

  if (response == "rods" || response == "Rods") {
    for (int i = 0; i < int(m_ID.size() ); i++) {
      if (m_ID.at(i)->GetName() == "Unnamed") {
  	m_ID.at(i)->SetShape("Rods");
	return 0;
      }
    }
  }
  else if (response == "cocci" || response == "Cocci") {
    for (int i = 0; i < int(m_ID.size() ); i++) {
      if (m_ID.at(i)->GetName() == "Unnamed") {
        m_ID.at(i)->SetShape("Cocci");
	return 1;
      }
    }
  }
  else{
    while (answered == false) {
      cout << "That is not a valid shape." << endl
	   << "Does your bacteria resemble rods or cocci?" << endl;
      cin >> response;

      if (response == "rods" || response == "Rods") {
	for (int i = 0; i < int(m_ID.size() ); i++) {
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    m_ID.at(i)->SetShape("Rods");
	    return 0;
	  }
	}
      }
      else if (response == "cocci" || response == "Cocci") {
	for (int i = 0; i < int(m_ID.size() ); i++) {
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    m_ID.at(i)->SetShape("Cocci");
	    return 1;
	  }
	}
      }
    }
  }
  return 2; // Should never reach this
}

void Identify::AcidfastID() {
  string response = "";
  bool answered = false;

  cout << "Is the bacteria acidfast or non-acidfast?" << endl;
  cin >> response;

  if (response == "acidfast" ||response == "Acidfast") {
    for (int i = 0; i < int(m_ID.size()); i++) {// Find Unnamed               
      if (m_ID.at(i)->GetName() == "Unnamed") {
        // Update the gram bool to true                                  
        m_ID.at(i)->SetAcidfast(true);
      }
    }
  }
  else if (response == "non-acidfast" | response == "Acidfast" ||
	   response == "Non-acidfast") {
    for (int i = 0; i < int(m_ID.size()); i++) {// Find Unnamed                
      if (m_ID.at(i)->GetName() == "Unnamed") {
        // Keep bool as false                                           
        m_ID.at(i)->SetAcidfast(false);
      }
    }
  }
  else{
    while (answered == false) {
      cout << "That is not a valid type of acidfast." << endl
           << "Is the bacteria acidfast or non-acidfast?" << endl;
      cin >> response;
      
      if (response == "acidfast" ||response == "Acidfast") {
	for (int i = 0; i < int(m_ID.size()); i++) {// Find Unnamed    
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    // Update the gram bool to true                             
	    m_ID.at(i)->SetAcidfast(true);
	    answered = true;
	  }
	}
      }
      else if (response == "non-acidfast" | response == "Acidfast" ||
	       response == "Non-acidfast") {
	for (int i = 0; i < int(m_ID.size()); i++) {// Find Unnamed 
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    // Keep bool as false                              
	    m_ID.at(i)->SetAcidfast(false);
	    answered = true;
	  }
	}
      }
    }
  }
}

void Identify::CatalaseID() {
  string response = "";
  bool answered = false;

  cout << "Is the bacteria catalase positive or catalase negative?" << endl;
  cin >> response;

  if (response == "positive" || response == "Positive" || 
      response == "Catalase positive" || response == "Catalase Positive" ||
      response == "catalase positive") {
    for (int i = 0; i < int(m_ID.size() ); i++) {
      if (m_ID.at(i)->GetName() == "Unnamed") {
        m_ID.at(i)->SetCatalase(true);
      }
    }
  }
  else if (response == "negative" || response == "Negative" ||
      response == "Catalase negative" ||response == "Catalase Negative" ||
      response == "catalse negative") {
    for (int i = 0; i < int(m_ID.size() ); i++) {
      if (m_ID.at(i)->GetName() == "Unnamed") {
        m_ID.at(i)->SetCatalase(false);
      }
    }
  }
  
  else{
    while (answered == false) {
      cout << "That is not a valid catalase type." << endl
           << "Is your bacteria catalase positive or negative?" << endl;
      cin >> response;

      if (response == "positive" || response == "Positive" ||
	  response == "Catalase positive" || response == "Catalase Positive" ||
	  response == "catalase positive") {
	for (int i = 0; i < int(m_ID.size() ); i++) {
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    m_ID.at(i)->SetCatalase(true);
	    answered = true;
	  }
	}
      }
      else if (response == "negative" || response == "Negative" ||
	       response == "Catalase negative" ||
	       response == "Catalase Negative" ||
	       response == "catalse negative") {
	for (int i = 0; i < int(m_ID.size() ); i++) {
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    m_ID.at(i)->SetCatalase(false);
	    answered = true;
	  }
	}
      }
    }
  }
}

void Identify::MorphologyID() {
  string response = "";
  bool answered = false;
  
  cout << "Is the bacteria morphology regular or pleomorphic?" << endl;
  cin >> response;
  
  if (response == "regular" || response == "Regular") {
    for (int i = 0; i < int(m_ID.size() ); i++) {
      if (m_ID.at(i)->GetName() == "Unnamed") {
        m_ID.at(i)->SetMorphology("Regular");
      }
    }
  }
  else if (response == "pleomorphic" || response == "Pleomorphic") {
    for (int i = 0; i < int(m_ID.size() ); i++) {
      if (m_ID.at(i)->GetName() == "Unnamed") {
        m_ID.at(i)->SetMorphology("Pleomorphic");
      }
    }
  }
    
  else{
    while (answered == false) {
      cout << "That is not a valid morphology." << endl
           << "Is your bacteria regular or pleomorphic?" << endl;
      cin >> response;
      
      if (response == "regular" || response == "Regular") {
	for (int i = 0; i < int(m_ID.size() ); i++) {
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    m_ID.at(i)->SetMorphology("Regular");
	    answered = true;
	  }
	}
      }
      else if (response == "pleomorphic" || response == "Pleomorphic") {
	for (int i = 0; i < int(m_ID.size() ); i++) {
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    m_ID.at(i)->SetMorphology("Pleomorphic");
	    answered = true;
	  }
	}
      }
    }
  }
}

void Identify::ClusterID() {
  string response = "";
  bool answered = false;

  cout << "Are your clusters regular or irregular?" << endl;
  cin >> response;

  if (response == "regular" || response == "Regular") {
    for (int i = 0; i < int(m_ID.size() ); i++) {
      if (m_ID.at(i)->GetName() == "Unnamed") {
        m_ID.at(i)->SetClusters("Regular clusters");
      }
    }
  }
  else if (response == "irregular" || response == "Irregular") {
    for (int i = 0; i < int(m_ID.size() ); i++) {
      if (m_ID.at(i)->GetName() == "Unnamed") {
        m_ID.at(i)->SetClusters("Irregular clusters");
      }
    }
  }
  
  else{
    while (answered == false) {
      cout << "That is not a valid cluster." << endl
           << "Does your bacteria have regular or irregular clusters?" << endl;
      cin >> response;

      if (response == "regular" || response == "Regular") {
	for (int i = 0; i < int(m_ID.size() ); i++) {
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    m_ID.at(i)->SetClusters("Regular clusters");
	    answered = true;
	  }
	}
      }
      else if (response == "irregular" || response == "Irregular") {
	for (int i = 0; i < int(m_ID.size() ); i++) {
	  if (m_ID.at(i)->GetName() == "Unnamed") {
	    m_ID.at(i)->SetClusters("Irregular clusters");
	    answered = true;
	  }
	}
      }
    }
  }
}

void Identify::ID() {
  // Check unnamed against named bacteria and add each one up
  // Based on the database, there is a __% chance that it is ... 

  // Add up for accuracy
  int gram = 0;
  int shape= 0;
  int acidfast = 0;
  int catalase = 0;
  int morphology = 0;
  int clusters = 0;
  int unnamedIndex = 6; // The location of our to be IDd bacteria

 
  for (int i = 0; i < int(m_ID.size() - 1 ); i++) {
    if ( m_ID.at(i)->GetGram() == m_ID.at( unnamedIndex )->GetGram() ) {
      m_ID.at(i)->SetPercentage(int(m_ID.at(i)->GetPercentage()) + 25);
    }

    // rods
    if (m_ID.at(i)->GetShape() == m_ID.at( unnamedIndex )->GetShape() ) { //rods
      m_ID.at(i)->SetPercentage(int(m_ID.at(i)->GetPercentage()) + 25);
    }
    else if(m_ID.at(i)->GetShape() == m_ID.at( unnamedIndex )->GetShape() ){ //cocci
      m_ID.at(i)->SetPercentage(int(m_ID.at(i)->GetPercentage()) + 25);
    }
    
    // acidfast
    if (m_ID.at(i)->GetAcidfast() == m_ID.at( unnamedIndex )->GetAcidfast() ){
      m_ID.at(i)->SetPercentage(int(m_ID.at(i)->GetPercentage()) + 25);
    }
    
    // morphology
    if (m_ID.at(i)->GetMorphology() == m_ID.at( unnamedIndex )->GetMorphology() ) {
      m_ID.at(i)->SetPercentage(int(m_ID.at(i)->GetPercentage()) + 25);
    }
    
    // catalse
    if (m_ID.at(i)->GetCatalase() == m_ID.at( unnamedIndex )->GetCatalase() ) {
      m_ID.at(i)->SetPercentage(int(m_ID.at(i)->GetPercentage()) + 25);
    }
    // clusters
    if( m_ID.at(i)->GetClusters() == m_ID.at( unnamedIndex )->GetClusters() ) {
      m_ID.at(i)->SetPercentage(int(m_ID.at(i)->GetPercentage()) + 25);
    }
  }


  bool found = false;
  
  for (int i = 0; i < int(m_ID.size()); i++) {
    if (m_ID.at(i)->GetPercentage() == 150) {
      found = true;
      cout << "Your bacteria is " << m_ID.at(i)->GetName() << "!" << endl;
    }
  }
  if (found == false) {
    cout << "Your bacteria is not in the program." << endl;
  }
}



void Identify::Display() {
  // Display all things that have been loaded in
  
  for (int i = 0; i < (m_ID.size()); i++) {
    cout << "Name: " << m_ID.at(i)->GetName() << endl
	 << m_ID.at(i)->GetGram() << " | " << m_ID.at(i)->GetShape() << endl
	 << "Acidfast status: " << m_ID.at(i)->GetAcidfast() << endl
	 << "Catalase status: " << m_ID.at(i)->GetCatalase() << endl
	 << m_ID.at(i)->GetMorphology() << " morphology, " << m_ID.at(i)->GetClusters() << endl;
  }
}
