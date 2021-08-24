#include <iostream>
#include <string> 
#include <stdlib.h> 
#include <time.h>
using namespace std;
#pragma once
#ifndef _PLAYER_
#define _PLAYER_
class Player {
    private: 
      string name; 
      int mindStrength;

    public: 
      void initPlayer(string, int); //sets up values for player object
      void meditate();
      void takeBrainwash(); 
      string getName(); 
      int getMindStrength(); 
}; 
#endif