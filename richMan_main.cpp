#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
//#include <load_richman.h>
//#include <save_richman.h>
//#include <richMan_display.h>

using namespace std;

struct Status{
  string name;
  int cash;
  int property;
  int position;
};

struct Block{
  string name;
  double price;
  int Lv;
  int ownership;
};

int playerNo;
Status *players;
Block mapBlocks[36];

int menu();
void initial(Status *&players);
void createMap(string defaultMap, Block *mapBlocks);

int main(){
  int choice;
  bool endGame = false;

  //display the main menu of the game
  choice = menu();
  switch (choice)
  {
    case 1:
      //select single/multi game mode
      //create new Players and store in Players array
      initial(players);
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

    /*for (int i = 0; i < 36; i++)
    {
      cout << mapBlocks[i].name << ' ' << mapBlocks[i].price << ' ' << mapBlocks[i].Lv << ' ' << mapBlocks[i].ownership << endl;
    }*/
    cout << "Round " << round+1 << "   " << players[turn].name << "\'s turn" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
    << "player's crash, saving, etc" << endl
    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
    //<< displayMap(&mapBlock) << endl
    << "=====================================================" << endl
    <<"1. Roll dice  2. Load game 3. Save game 4. Quit" << endl
    << "=====================================================" << endl
    << "Your choice: ";
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

void initial(Status *&players){
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

      players = new Status[playerNo];
      for (int i = 0; i < playerNo; i++)
      {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Please enter the name of player " << i << ": ";
        cin >> players[i].name;
        players[i].cash = 100000;
        players[i].property = 0;
      }
      createMap("defaultMap.txt", mapBlocks);

      system("CLS");
      break;
  }

  return;
}

void createMap(string defaultMapFile, Block *mapBlocks)
{
  ifstream fin;

  fin.open(defaultMapFile);
  if (fin.fail())
  {
    cout << "error in opening file" << endl;
    exit(1);
  }
  else
  {
    string line;
    int i = 0;

    while (getline(fin, line))
    {
      istringstream iss(line);

      iss >> mapBlocks[i].name;
      iss >> mapBlocks[i].price;
      iss >> mapBlocks[i].Lv;
      iss >> mapBlocks[i].ownership;
      i++;
    }
  }

  return;
}
