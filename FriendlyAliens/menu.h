#include <string> 
#include <iostream> 
#include <fstream> 
#include <string> 
#include "society.h"
#include "readFiles.h" 
//header guard
#pragma once
#ifndef _MENU_
#define _MENU_
using namespace std; 

class Menu { 
    private: 
      char userKey; 
      bool quitGame = false; 

    public: 
      void welcome(); 
      void showHowTo(); 
      void playGame(); 
      void playAgain(); 
}; 
#endif
