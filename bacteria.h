// File: bacteria.h
// Author: Abigail Kennedy
// Date: 11/13/2020
// Description: The header file for the bacteria class

#ifndef BACTERIA_H
#define BACTERIA_H
#include <iostream>
#include <string>
using namespace std;

class Bacteria {
public:
  // Name: Bacteria (Default constructor)
  // Desc: Stores an item                                              
  // Precon: None                                                        
  // Postcon: An item is stored in the object                             
  Bacteria();
  
  // Name: Bacteria (Overloaded constructor)                                  
  // Desc: Stores an item                                                 
  // Precon: The details of an item is passed to this constructor         
  // Postcon: An item, with the passed details, is stored in the objxsect 
  Bacteria(string, bool, string, bool, bool, string, string);
  
  // Name: ~Bacteria (Destructor)                                             
  // Desc: Destructor                                             
  // Precon: Bacteria exists
  // Postcon: Bacteria is destroyed
  ~Bacteria();
  
  // Name: GetName                                                        
  // Desc: Returns the item's name                                        
  // Precon: The item has a name                                          
  // Postcon: The name is returned                                        
  string GetName();

  // Name: GetShape                                                       
  // Desc: Returns the shape                                              
  // Precon: The item has a shape                                         
  // Postcon: Returns the shape                                           
  string GetShape();
  
  // Name: GetMorphology                                                  
  // Desc: Returns the morphology                                         
  // Precon: The item has a morphology                                    
  // Postcon: Returns the morphology                                      
  string GetMorphology();
  
  // Name: GetClusters                                                    
  // Desc: Returns the cluster type                                       
  // Precon: The item has a cluster type                                  
  // Postcon: Returns the cluster type                                    
  string GetClusters();
  
  // Name: GetGram                                                        
  // Desc: Returns the gram type                                          
  // Precon: The item has a gram type                                     
  // Postcon: Returns the gram type                                       
  bool GetGram();
  
  // Name: GetCatalase                                                    
  // Desc: Returns catalase status                                        
  // Precon: The item has a catalase status                               
  // Postcon: Returns the catalase status                                 
  bool GetCatalase();
  
  // Name: GetAcidfast                                                    
  // Desc: Returns acidfast status                                        
  // Precon: The item has an acidfast status                              
  // Postcon: Returns the acidfast status                                 
  bool GetAcidfast();
  
  // Name: SetShape                                                       
  // Desc: Renames the shape                                              
  // Precon: The item exists                                              
  // Postcon: The item shape is updated                                   
  void SetShape(string);
  
  // Name: SetMorphology                                                  
  // Desc: Renames the morphology                                         
  // Precon:The item exists                                               
  // Postcon: The item morphology is updated                              
  void SetMorphology(string);
  
  // Name: SetClusters                                                    
  // Desc: Renames the cluster type                                       
  // Precon:The item exists                                               
  // Postcon: The item cluster type is updated                            
  void SetClusters(string);
  
  // Name: SetGram                                                        
  // Desc: Renames the gram type                                          
  // Precon: The item exists                                              
  // Postcon: The item gram type is updated                               
  void SetGram(bool);
  
  // Name: SetCatalase                                                    
  // Desc: Renames the catalase status                                    
  // Precon: The item exists                                              
  // Postcon: The item catalase status is updated                         
  void SetCatalase(bool);
  
  // Name: SetAcidfast                                                    
  // Desc: Renames the acidfast status                                    
  // Precon: The item exists                                              
  // Postcon: The item acidfast status is updated                         
  void SetAcidfast(bool);
 
  // Name: SetName                                                        
  // Desc: Updates the name of the item                                   
  // Precon: The item exists                                              
  // Postcon: The item has a name                                         
  void SetName(string);

  int GetPercentage();

  void SetPercentage(int);
  
private:
  string m_name; // The name of the item    
  string m_shape; // rods or cocci?                                       
  string m_morphology; // regular or pleomorphic?                         
  string m_clusters; // regular or irregular clusters?                    
  bool m_gram; // postitive or negative?                                  
  bool m_catalase; // catalase positive or negative?                      
  bool m_acidfast; // are they acid fast?      
  int m_percentage; // the percentage to the unknown
};

#endif
