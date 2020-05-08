#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <sys/stat.h>
#include <time.h>
//#include <load_richman.h>
#include "richMan_save.h"
#include "richMan_load.h"
#include "richMan_display.h"
//#include "richMan_struct.h"
#include "richMan_mapEffect.h"
#include "richMan_randomevent.h"
#include "richMan_bankrupt.h"

using namespace std;

int playerNo = 0;
int mode = 2;

int menu();
void createCharacters(Status *&players);
void createMap(string defaultMap, Block *&mapBlocks);
int dice();

int main(){
  int choice;
  bool endGame = false;
  int n = 36, round = 0, turn = 0;
  Block *mapBlocks = new Block[n];
  Status *players;

  //display the main menu of the game
  choice = menu();
  switch (choice)
  {
    case 1:
    {
      createCharacters(players);
      createMap("save/default.txt", mapBlocks);//select single/multi game mode, create new Players and map
      break;
    }
    case 2:
    {
      richMan_load(mapBlocks, players, playerNo, round, turn);
      break;
    }
    case 3:
      //display the game rules
      //rules();
      break;
    default:
    {
      cout << "Please enter 1-3 only!" << endl;
      choice = menu();
    }
  }

  int *freeze = new int[playerNo]();
  
  while (!endGame && mode == 1)
  {
    static int choice;

    displayMap(mapBlocks, players, playerNo);
    cout << "Round " << round+1 << "   " << players[turn].name << "\'s turn" << endl
    << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
    << "Cash: " << players[turn].cash << "  Property owned: " << players[turn].property
    << "  Position: " << mapBlocks[players[turn].position].name << endl
    << "=====================================================" << endl
    <<"1. Roll dice  2. Load game 3. Save game 4. Quit" << endl
    << "=====================================================" << endl
    << "Your choice: ";
    if (turn == 0){
      cin >> choice;

      if (choice == 1)
      {
        int diceNo = dice();
        players[turn].position += diceNo;
        if (players[turn].position > 35)
          {
            players[turn].position %= 36;
            players[turn].cash += 100000;
          }
        mapEffect(diceNo, mode, turn, mapBlocks, players, playerNo, freeze);
      }
      if (choice == 3)
      {
        cout << "save round: " << round << ' ' << turn << endl;
        richMan_save(mapBlocks, players, playerNo, round, turn);
      }
    }
    if (turn!=0){
      choice = 1;
      int diceNo = rand()%6+1;
      players[turn].position += diceNo;
      if (players[turn].position > 35)
      {
        players[turn].position %= 36;
        players[turn].cash += 100000;
      }
      mapEffect(diceNo, mode, turn, mapBlocks, players, playerNo, freeze);
    }

    int i = 0;
    while (i < playerNo)
    {
      if (players[i].cash <= 0)
      {
        cout << "## " << players[i].name << " bankrupted! ##" << endl;
        richMan_bankrupt(players, playerNo, i);
      }
      i++;
    }
    if (playerNo == 1)
    {
      endGame = true;
      cout << "## Congratulate " << players[0].name << " wins the game ##" << endl;
      int end = 1;
      while (end != 0)
      {
        cout << "Enter 0 to end ";
        cin >> end;
      }
    }
    turn++;
    if (turn%playerNo == 0)
    {
      round++;
      turn = 0;
    }
  }
  
  while (!endGame && mode == 2)
  {
    static int choice;
    //cout << "freeze: " << freeze[turn] << endl;

    displayMap(mapBlocks, players, playerNo);
    cout << "Round " << round+1 << "   " << players[turn].name << "\'s turn" << endl
    << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    if (freeze[turn] != 0)
    {
      cout << "## You have to stay in " << mapBlocks[players[turn].position].name << " for " << freeze[turn]-1 << " more turn ##" << endl;
      freeze[turn] -= 1;
      int end = 1;
      while (end != 0)
      {
        cout << "Enter 0 to end ";
        cin >> end;
      }
    }
    else
    {
      cout << "Cash: " << players[turn].cash << "  Property owned: " << players[turn].property
      << "  Position: " << mapBlocks[players[turn].position].name << endl
      << "=====================================================" << endl
      <<"1. Roll dice  2. Load game 3. Save game 4. Quit" << endl
      << "=====================================================" << endl
      << "Your choice: ";
      cin >> choice;
      if (choice == 1)
      {
        int diceNo = dice();
        //int diceNo = 4;
        players[turn].position += diceNo;
        if (players[turn].position > 35)
        {
          players[turn].position %= 36;
          players[turn].cash += 10000;
        }
        mapEffect(diceNo, mode, turn, mapBlocks, players, playerNo, freeze);
      }
      if (choice == 3)
      {
        cout << "save round: " << round << ' ' << turn << endl;
        richMan_save(mapBlocks, players, playerNo, round, turn);
      }
      /*if (choice == 5)
      {
        random_event("chance", players, 0);
      }*/
      //system("CLS");
      int i = 0;
      while (i < playerNo)
      {
        if (players[i].cash <= 0)
        {
          cout << "## " << players[i].name << " bankrupted! ##" << endl;
          richMan_bankrupt(players, playerNo, i);
        }
        i++;
      }
      if (playerNo == 1)
      {
        endGame = true;
        cout << "## Congratulate " << players[0].name << " wins the game ##" << endl;
        int end = 1;
        while (end != 0)
        {
          cout << "Enter 0 to end ";
          cin >> end;
        }
      }
    }
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

  cout << "==================================" << endl
  << "*****     RichMan      *****" << endl
  << "==================================" << endl
  << "Please Use Full Screen to Play" << endl
  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
  << "1. Start a new game" << endl
  << "2. Load previous game (Not Finish)" << endl
  << "3. Game rules (Not Finish)" << endl
  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Your choice: ";
  cin >> choice;

  //system("CLS");

  return choice;
}

void createCharacters(Status *&players){

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
    {
      playerNo = 4;
      players = new Status[playerNo];
      int * num = new int[3];
      string namelist[10] = {"SM", "SP", "Th", "Pa", "Ir", "Dk", "Me", "Ah", "CB", "BC"};
      srand(time(NULL));
      num[0] = rand()%10;
      num[1] = rand()%10;
      while (num[1] == num[0])
        {num[0] = rand()%10;}
      num[2] = rand()%10;
      while (num[2] == num[1] || num[3] == num[1])
        {num[2] = rand()%10;}
      for (int i = 0; i < playerNo; i++)
      {
        if (i == 0){
          cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cout << "Please enter your name: ";
          cin >> players[i].name;
        }
        else {
          players[i].name = namelist[num[i-1]]+"_AI";
        }
        players[i].cash = 100000;
        players[i].property = 0;
        players[i].position = 0;
      }
      for (int i = 0; i<4; i++){
        cout << players[i].name << endl;
      }
      delete [] num;
      break;
    }
    case 2:
    {
      cout << "Please enter no. of player (2-4): ";
      cin >> playerNo;

      players = new Status[playerNo];
      for (int i = 0; i < playerNo; i++)
      {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Please enter the name of player " << i+1 << ": ";
        cin >> players[i].name;
        players[i].cash = 100000;
        players[i].property = 0;
        players[i].position = 0;
      }
      //createMap("save/default.txt", mapBlocks);

      //system("CLS");
      break;
    }
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
