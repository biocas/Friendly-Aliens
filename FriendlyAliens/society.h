#pragma once //header guard
#include <iostream>
#include <string> 
#include <cctype> // to capitalise words
#include <unistd.h> //for time delay between features
#include "alien.h"
#include "player.h"
#include "readFiles.h"
#include "menu.h"
using namespace std;
#ifndef _SOCIETY_
#define _SOCIETY_

class Society { 
  private: 
  string correctWord; //stores winning word
  int lettersCounter; //counts letters the player has guessed
  bool playing; //sets to false to quit game on winning or loosing
  Player player; 
  Alien alien; 

  public: 
    Society(); //constructor
    void launchGame(); // games develop here
    void checkWord(); //checks word that wins the game 
    void establishContact(); //conects class Player and class Alien
}; 
#endif