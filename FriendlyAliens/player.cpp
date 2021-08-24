#include "player.h" 
#include "alien.h"
#include "society.h"

//prompts user too set player name and sets up Player object
void Player::initPlayer(string username, int randomStrength){
  this->name = username; 
  this->mindStrength = randomStrength; 
  cout << "Congratulations, " << name << ", in trying to step up and reach new dimensions of being." << endl << "Your mind strength is " << mindStrength << "." << endl;
}; 

//method to increase player mindStrength
void Player::meditate() { 
  if (this->mindStrength >= 100) {
    cout << "You have reached your meditation levels. You need to go live a little!" << endl;
  } else {
    this->mindStrength += 5; 
    cout << "You are meditating!" << endl; 
    cout << "   _" << endl; 
    cout << "  (\")" << endl; 
    cout << " (-\"-)" << endl; 
    cout << "(_`/._)" << endl; 
    cout << "Through meditation, your mind strength is now " << this->mindStrength << "." << endl; 
  };
};

//method to decrease player mindStrength
void Player::takeBrainwash() { 
  this->mindStrength -= 5; 
  cout << "               __,aaPPPPPPPPaa,__" << endl;
  cout << "         ,adP\"\"\"\'          `""Yb,_" << endl;
  cout << "      ,ad\"\'                     `\"Yb," << endl;
  cout << "    ,dP'     _,adPP\"\"\"\"\"YYba,_     `\"Y," << endl;
  cout << "   aP'     ,d""'           `\"\"Ya,     \"Y," << endl;
  cout << " ,d\"     ,P\"     _________     `\"b,    `Yb," << endl;
  cout << ",d'     d\"    ,adP""""""""Yba,    \"b,    \"Y," << endl;
  cout << "d'    ,P'   ,dP\"            `Yb,   `Y,    `Y," << endl;
  cout << "8    ,P'   ,d'    ,dP""Yb,    `Y,   `Y,    `b" << endl;
  cout << "8    d'    d'   ,d"      "b,   `Y,   `8,    Y," << endl;
  cout << "8    8     8    d'    _   `Y,   `8    `8    `b" << endl;
  cout << "8    8     8    8     8    `b    8     8     8" << endl;
  cout << "8    Y,    Y,   `b, ,aP     P    8    ,P     8" << endl;
  cout << "I,   `Y,   `8,    """"     d'   ,P    d\"    ,P" << endl;
  cout << "`b,   `8,    \"b,         ,P\"   ,P'   ,P'    d'" << endl;
  cout << " `b,   `Ya,    \"Ya,,__,aP\"    ,P'   ,P\"    ,P" << endl;
  cout << "  `Y,    `Ya,     `\"\"\"\'\'     ,P'   ,d\"    ,P'" << endl;
  cout << "   `Yb,    `\"Ya,_         _,d\"    ,P'    ,P'" << endl;
  cout << "     `Yb,      \"\"YbaaaaadP\"'     ,P'    ,P'   " << endl;
  cout << "       `Yba,                   ,d'    ,dP'    " << endl;
  cout << "          `\"Yba,__       __,adP\"     dP\"" << endl;
  cout << "              `\"\"\"\"\"\"\"\"\"\"\"\"\"\'" << endl;
  cout << "YOU JUST GOT BRAINWASHED." << endl << endl << "Your mind strength is now down to " << mindStrength << "." << endl << endl << "****************************************************************" << endl << endl; 
};
//methods that return player attributes
string Player::getName(){
  return name; 
}; 

int Player::getMindStrength(){
  return mindStrength; 
}; 