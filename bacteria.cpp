// Name: bacteria.cpp
// Author: Abigail Kennedy
// Date: 11/13/2020
// Desc: The cpp file for the bacteria class

#include "bacteria.h"

Bacteria::Bacteria() { // Default constructor
  m_name = "Unnamed";
  m_gram = false;
  m_shape = "Rods";
  m_acidfast = false;
  m_catalase = false;
  m_morphology = "Regular";
  m_clusters = "Regular clusters";
  m_percentage = 0;
}

Bacteria::Bacteria(string name, bool gram, string shape, bool acidfast,
		   bool catalase, string morphology, string clusters)
{ // Overloaded constructor
  m_name = name;
  m_gram = gram;
  m_shape = shape;
  m_acidfast = acidfast;
  m_catalase = catalase;
  m_morphology = morphology;
  m_clusters = clusters;
  m_percentage = 0;
}

Bacteria::~Bacteria(){ // Destructor

}

// Functions                                                                   

string Bacteria::GetName() {
  // Returns the item's name                                              
  return m_name;
}

string Bacteria::GetShape() {
  // Desc: Returns the shape                                              
  return m_shape;
}

string Bacteria::GetMorphology() {
  // Desc: Returns the morphology                                         
  return m_morphology;
}
string Bacteria::GetClusters() {
  // Desc: Returns the cluster type                                       
  return m_clusters;
}

bool Bacteria::GetGram(){
  // Desc: Returns the gram type                                          
  return m_gram;
}

bool Bacteria::GetCatalase() {
  // Desc: Returns catalase status                                        
  return m_catalase;
}

bool Bacteria::GetAcidfast() {
  // Desc: Returns acidfast status                                        
  return m_acidfast;
}

void Bacteria::SetName(string name) {
  // Updates the name of the item                                           
  m_name = name;
}

void Bacteria::SetShape(string shape) {
  // Updates the shape                                                    
  m_shape = shape;
}

void Bacteria::SetMorphology(string morphology) {
  // Updates the morphology                                               
  m_morphology = morphology;
}

void Bacteria::SetClusters(string clusters) {
  // Updates the clusters                                                 
  m_clusters = clusters;
}

void Bacteria::SetGram(bool gram) {
  // Updates the gram status                                              
  m_gram = gram;
}

void Bacteria::SetCatalase(bool catalase) {
  // Updates the catalase status                                          
  m_catalase = catalase;
}

void Bacteria::SetAcidfast(bool acidfast) {
  // Updates the acidfast status                                          
  m_acidfast = acidfast;
}

int Bacteria::GetPercentage() {
  return m_percentage;
}

void Bacteria::SetPercentage(int percentage) {
  m_percentage = percentage;
}

