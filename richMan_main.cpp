#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include <load_richman.h>
//#include <save_richman.h>

using namespace std;

struct Players{
  int id;
  string name;
  int crash;
  int property;
  int saving;
};
int playerNo;

int menu();
void createCharacters(Players *&players);

int main(){
  int choice;
  Players * players;
  bool endGame = false;

  //display the main menu of the game
  choice = menu();
  switch (choice)
  {
    case 1:
      //select single/multi game mode
      //create new Players and store in Players array
      createCharacters(players);
      break;
    case 2:
      //load();
      break;
    case 3:
      //display the game rules
      //rules();
      break;
    default:
      cout << "Please enter 1-3 only!" << endl;
      choice = menu();
  }

  while (!endGame)
  {
    static int round = 0, turn = 0, choice;
    cout << "Round " << round+1 << "   " << players[turn].name << "\'s turn" << endl;
    //display the data of the current players
    //playerData(turn);
    //display the current map
    //map();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "player's crash, saving, etc" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "I am the map" << endl;
    cout << "=====================================================" << endl;
    cout <<"1. Roll dice  2. Use tools 3. Save game 4. Rage quit" << endl;
    cout << "=====================================================" << endl;
    cout << "Your choice: ";
    cin >> choice;

    system("CLS");

    turn++;
    if (turn%playerNo == 0)
    {
      round++;
      turn = 0;
    }
    if(round == 5)
      endGame = true;
  }
  return 0;
}

int menu(){
  int choice;

  cout << "============================" << endl;
  cout << "*****     RichMan      *****" << endl;
  cout << "============================" << endl;
  cout << "1. Start a new game" << endl;
  cout << "2. Load previous game (Not Finish)" << endl;
  cout << "3. Game rules (Not Finish)" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Your choice: ";
  cin >> choice;

  system("CLS");

  return choice;
}

void createCharacters(Players *&players){
  int mode;

  cout << "1. Single Mode (Not Finish)" << endl;
  cout << "2. MultiPlayer Mode" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Your choice: ";
  cin >> mode;

  system("CLS");

  switch (mode)
  {
    case 1:
      //1 player + 3 AIs
      break;
    case 2:
      cout << "Please enter no. of player (2-4): ";
      cin >> playerNo;

      players = new Players[playerNo];
      for (int i = 0; i < playerNo; i++)
      {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        players[i].id = i;
        cout << "Please enter the name of player " << i << ": ";
        cin >> players[i].name;
        players[i].crash = 100000;
        players[i].saving = 100000;
        players[i].property = 0;
      }

      system("CLS");
      break;
  }

  return;
}
