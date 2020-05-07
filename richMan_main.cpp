#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <sys/stat.h>
#include <time.h>
//#include <load_richman.h>
//#include <save_richman.h>
#include "richMan_display.h"
#include "richMan_struct.h"

using namespace std;

int playerNo;

int menu();
void createCharacters(Status *&players);
void createMap(string defaultMap, Block *&mapBlocks);
int dice();

int main(){
  int choice;
  bool endGame = false;
  Block *mapBlocks = new Block[36];
  Status *players;

  //display the main menu of the game
  choice = menu();
  switch (choice)
  {
    case 1:
      createCharacters(players);
      createMap("save/default.txt", mapBlocks);//select single/multi game mode, create new Players and map
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
    displayMap(mapBlocks, players, playerNo);
    cout << "Round " << round+1 << "   " << players[turn].name << "\'s turn" << endl
    << "=====================================================" << endl
    <<"1. Roll dice  2. Load game 3. Save game 4. Quit" << endl
    << "=====================================================" << endl
    << "Your choice: ";
    cin >> choice;

    if (choice == 1)
    {
      players[turn].position += dice();
      //mapEffect(turn, players, mapBlocks);
      if (players[turn].position > 35)
        players[turn].position %= 36;
    }

    system("CLS");

    turn++;
    if (turn%playerNo == 0)
    {
      round++;
      turn = 0;
    }
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

void createCharacters(Status *&players){
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
        players[i].position = 0;
      }
      //createMap("save/default.txt", mapBlocks);

      system("CLS");
      break;
  }

  return;
}

void createMap(string defaultMapFile, Block *&mapBlocks)
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

int dice(){
  int dice;

  srand(time(NULL));
  dice = rand()%6+1;

  return dice;
}
