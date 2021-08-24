#include "menu.h"

//shows menu and handles user input
void Menu::welcome(){
  readFile("welcome.txt"); 
  do {
    cin >> userKey;
    switch (userKey) {
      case 'p': case 'P': 
        Menu::playGame();  
        break;
      case 'h': case 'H': 
        Menu::showHowTo();
        break;
      case 'q': case 'Q': 
        cout << "The game will now exit." << endl;
        quitGame = true;
        break;
      default:
        cout << "Invalid option. Please enter a valid option" << endl;  
        break; 
    };
  } while (!quitGame); 
}; 

//shows help panel and handles user input
void Menu::showHowTo(){
  readFile("help.txt");
  cin >> userKey; 
  while (userKey != 'B' || userKey != 'b') {
    switch (userKey) {
      case 'B': case 'b': 
        Menu::welcome(); 
        break;
      default:
        cout << "Invalid option. Please enter a valid option" << endl; 
        cin >> userKey; 
        break; 
    };
  };
}; 

//creates dynamic object of Society
void Menu::playGame(){
  Society* society = new Society(); 
  society->launchGame(); 
  delete society; //deletes object that has all dynamic memory allocation, releasing the whole game back to the Heap
  Menu::playAgain(); 
}; 

//relaunches menu or quits game upon losing or winning
void Menu::playAgain(){
  char playAgain;
  cout << "Play again? Y/N: ";  
  cin >> playAgain; 
  if (playAgain == 'y' ||playAgain == 'Y') {
    Menu* menu = new Menu(); 
    menu->welcome(); 
  } else {
    Menu::quitGame = true; 
  }
}; 