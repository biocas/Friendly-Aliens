#include "alien.h"

//setup alien objects
void Alien::setValues(int alienType, int boolNum){
  this->decision = boolNum; //random to decide if alien isInGoodMood
  //assigning a random alienType from alienTypes array
  this->assigningAlien = alienType;
  string alienTypes[7] = {"Grey", "Reptilian", "Pleiadean", "Sentient", "Yoda", "Asgardian", "Lightbeam"}; 
  this->alienSpec = alienTypes[assigningAlien];
  //read file with binary codes and corresponding letters
  string line, codePair, tempLetter, tempBinary;
  int codePosition = 0; 
  ifstream fin; 
  fin.open("codes.txt"); 
    if (fin.good()) {
      while (getline(fin, line)) { 
        stringstream codePair(line); 
        //get comma separated attributes for paralel arrays
        getline(codePair, tempLetter, ',' );
        getline(codePair, tempBinary, ',' );
        //populate parallel arrays 
        this->winningLetters[codePosition] = tempLetter;
        this->binaryCodes[codePosition] = tempBinary;
        //clear temporary variables for array values
        tempLetter.clear();
        tempBinary.clear(); 
        codePosition++; // go to next array element
      }; 
    };
  if (decision == 1) {
    this->isInGoodMood = false;
  } else {
    this->isInGoodMood = true; 
  };
}; 

//returns type of alien
string Alien::getSpecie(){
  return alienSpec; 
}; 

bool Alien::getMood(){
  return isInGoodMood; 
};

//gets values from paralel arrays depending on which codes the player already has
string Alien::getBinaryCode(int codePosition) {
  return this->binaryCodes[codePosition]; 
};

string Alien::getWinningLetter(int codePosition) {
  return this->winningLetters[codePosition]; 
};