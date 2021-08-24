#include "myexception.h"
#include "readFiles.h" 

//function that reads files and handles error/expceptions
void readFile(string fileName){
  string line; 
  ifstream fin; 
  fin.open(fileName); 
  try {
    if (fin.good()) {
      while (getline(fin, line)) {
        cout << line << endl; 
      };
      fin.close(); 
    }
    else {
      throw myex; 
    }
  } catch(exception& e) {
    cout << "Error opening the file." << endl; 
  };
};