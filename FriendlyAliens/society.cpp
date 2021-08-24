#include "society.h" 
#include "player.h" 

//constructor 
Society::Society() {
  correctWord = "EMPATHY"; 
  srand(time(NULL)); //time seed for random functionality
  lettersCounter = 0;  
  bool playing = true; 
};

void Society::launchGame(){
  string username; 
  cout << "What is your name? "; 
  cin.ignore();
  getline(cin, username);  //gets name of player from user
  player.initPlayer(username, (rand() % 60)); //set mindStrength to random and counter to 0
  alien.setValues((rand() % 6), (rand() % 2 + 1)); //set assigningAlien to rand up to 6 and then decision to boolean style random
  char playerAction; 
  Society::playing =  true; 
  //while game is unfolding handles player's actions
  while (playing && player.getMindStrength() >= 0) {
    cout << "Press M to medidate and get strong, C to attempt contact or R if you are ready to break out of the matrix." << endl;
    cin >> playerAction;
    switch (playerAction) {
      case 'm': case 'M': 
        player.meditate(); 
        break;
      case 'c': case 'C': 
        Society::establishContact(); 
        break;
      case 'r': case 'R': 
        Society::checkWord(); 
        break;
      default:
        cout << "Invalid option. Please enter a valid option" << endl;
        break; 
      };
  };
  //player loses 
  if (player.getMindStrength() <= 0) {
    readFile("lost.txt");
    sleep(1);// delay 
  };
};

//conects Class Player and Class Alien and checks if content is successful and if guesses are correct 
void Society::establishContact(){
  cout << "   .       *             .         ." << endl;
  cout << "               .                      ." << endl;
  cout << "   .       .                   ." << endl;
  cout << "                                *        ." << endl;
  cout << "      .   '               .              ." << endl;
  cout << "              _.---._   .            .     *" << endl;
  cout << "    *       .'       '." << endl;
  cout << "        _.-~===========~-._" << endl;
  cout << "       (___________________)       .   *" << endl;
  cout << "  __  .'     \\_______/   .'  ______        __" << endl;
  cout << "    |              .'  .'   |      |      |  |" << endl;
  cout << "    |             '         |      |      |  |" << endl;
  cout << "    |                       |      |   ___|  |_" << endl;
  cout << "  __|_______________________|__..--~~~~ jro    ~--." << endl;
  cout << "                    /|\\" << endl;
  cout << "                   /   \\" << endl;
  cout << "                  /  |  \\" << endl;
  cout << "                 /       \\" << endl;
  cout << "    \\|/         /    |    \\" << endl;
  cout << "               /           \\" << endl;
  cout << "              /      |      \\" << endl;
  cout << "             /     Hey " << alien.getSpecie() << "," << endl;
  cout << "            /      I am " << player.getName() << endl;
  cout << "           /      Can you help me" << endl;
  cout << "          /    __  getting to the 5th dimension?" << endl;
  cout << "         /    /  \\ /" << endl;
  cout << "        /    (\\__/)  |            \\" << endl;
  cout << "       /     _\\__/_                \\" << endl;
  cout << "      /     /      \\ |              \\" << endl;
  cout << "     /     / /   / /                 \\" << endl;
  cout << "           \\ |   \\_\\                  \\" << endl;
  cout << "            \\|____\\_)                  \\    \\|/" << endl;
  cout << "             |    \\" << endl;
  cout << "             | |\\  \\" << endl;
  cout << "             | |/  /" << endl;
  cout << "             |_/__/" << endl;
  cout << "            (__[__)" << endl << endl; 
  cout << "  8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8" << endl;
  cout << "   8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8" << endl << endl;
  //sucessful contact
  if (alien.getMood() && (player.getMindStrength()) > 40) {
    if (lettersCounter < 7) {
      cout << "Contact was accepted" << endl; 
      cout << alien.getBinaryCode(lettersCounter) << " is your code. Translate it to the Roman alphabet." << endl;
      cout << "Your answer: " << endl; 
      string playerConversion; 
      cin >> playerConversion; 
      for (int i = 0; i < playerConversion.length(); i++) {
        playerConversion[i] = tolower(playerConversion[i]); 
      };
      //check if player guess is correct
      if (playerConversion == alien.getWinningLetter(lettersCounter)) {
        cout << "Your answer is correct." << endl;
        lettersCounter++; //used to handle next code given to Player
        sleep(2);// delay 
        player.takeBrainwash();
      } else {
        cout << "Your answer is wrong." << endl  << "****************************************************************" << endl;  
        sleep(1);// delay 
        player.takeBrainwash();
      }
    //handles case when player already has all letters 
    } else {
      cout << "You have all the letters to get to the fifth dimension." << endl << endl;
      cout << " ad8888888888ba" << endl;
      cout << "dP'         `\"8b," << endl;
      cout << "8  ,aaa,       \"Y888a     ,aaaa,     ,aaa,  ,aa," << endl;
      cout << "8  8' `8           \"8baaaad\"\"\"\"baaaad\"\"\"\"baad\"\"8b" << endl;
      cout << "8  8   8              \"\"\"\"      \"\"\"\"      \"\"    8b" << endl;
      cout << "8  8, ,8         ,aaaaaaaaaaaaaaaaaaaaaaaaddddd88P" << endl;
      cout << "8  `\"\"\"'       ,d8\"\"" << endl;
      cout << "Yb,         ,ad8\"" << endl;
      cout << " \"Y8888888888P\"" << endl << endl;

      cout << "Combine them into the word that will get you there." << endl << endl;
    };
  //contact unsuccessful because alien is not in a good mood!
  } else if (!alien.getMood()) {
      cout << "Oh no. The alien was not in a good mood! Unlucky!" << endl << endl << "****************************************************************" << endl; 
      sleep(2);// delay 
      player.takeBrainwash();
  //handles other cases of unsuccessful contacts
  } else {
      cout << "Contact was denied. You need to get stronger so you can make contact." << endl << endl << "****************************************************************" << endl; 
      sleep(2);// delay 
      player.takeBrainwash();
  }
};

//checks word to win the game
void Society::checkWord(){
  //player has to be given all the words to try guessing it
  if (lettersCounter < 7) {
    cout << "Oops! It seems you have not found all the letters you need. You need to do the work!" << endl;
  } else {
    string guessedWord; 
    cout << "You have come this far. The universe is proud of you. Please enter the word that takes you into a new dimension: ";
    cin >> guessedWord; 
    //get guessed word to all capitals here to match with correctWord
    for (int i = 0; i < guessedWord.length(); i++) {
      guessedWord[i] = toupper(guessedWord[i]); 
    };
    //checks if guess is correct - if yes, game is won; 
    if (correctWord == guessedWord) {
      readFile("win.txt");
      sleep(1);// delay 
      Society::playing = false;
    } else {
      cout << "That word is not right." << endl;
      sleep(1);// delay  
      player.takeBrainwash(); 
    };
  };
};
