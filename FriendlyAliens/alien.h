#include <iostream>
#include <string>  //use strings 
#include <stdlib.h> //random functionality
#include <time.h> //random functionality
#include <fstream> //need a special implementation for reading files to allocate each line
#include <sstream> //to getline separated by ,
#include "player.h"
using namespace std;
#pragma once
#ifndef _ALIEN_
#define _ALIEN_

class Alien {
    private: 
      int assigningAlien; 
      int decision;
      string alienTypes[6];
      string alienSpec; 
      bool isInGoodMood;
      string *binaryCodes = new string[7]; 
      string *winningLetters = new string[7];
    
    public: 
      void setValues(int, int); 
      string getSpecie(); 
      bool getMood();  
      string getBinaryCode(int codePosition); 
      string getWinningLetter(int codePosition); 
};
#endif