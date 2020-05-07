#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "richMan_display.h"
#include "richMan_mapEffect.h"
#include "richMan_randomevent.h"

using namespace std;

void mapEffect(int dice, int turn, Block *mapBoard, Status *players, int playerNo){
  int choice = 1;
  int pos = players[turn].position;
  while (choice)
  {
    //system("CLS");
    displayMap(mapBoard, players, playerNo);
    cout << "========================================================" << endl
    << "The dice number is " << dice << "  "
    << players[turn].name << " go to " << mapBoard[pos].name << endl
    << "========================================================" << endl
    << "Cash: " << players[turn].cash << ' ' << "Property owned: " << players[turn].property << endl
    <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    //cout << mapBoard[pos].ownership << endl;
    if (players[turn].cash > mapBoard[pos].price && mapBoard[pos].ownership == -1)
    {
      int buy;
      cout << "Buy " << mapBoard[pos].name << "(price: "<< mapBoard[pos].price << ')' << " ? (1:buy 0:not buy)";
      cin >> buy;
      if (buy)
      {
        mapBoard[pos].ownership = turn;
        players[turn].cash -= mapBoard[pos].price;
        cout << "## " << players[mapBoard[pos].ownership].name << " become the owner of " << mapBoard[pos].name << " ##" << endl
        << "## Cash remaining: " << players[turn].cash << " ##" << endl;
        players[turn].property += 1;
      }
    }
    else if(mapBoard[pos].ownership >= 0 && mapBoard[pos].ownership < playerNo)
    {
      cout << "## " << mapBoard[pos].name << " is owned by " << players[mapBoard[pos].ownership].name << " ##" << endl
      << "## You have to pay $" << mapBoard[pos].price*0.1 << " to " << players[mapBoard[pos].ownership].name << " ##" << endl;
      players[turn].cash -= mapBoard[pos].price*0.1;
      players[mapBoard[pos].ownership].cash += mapBoard[pos].price*0.1;
      cout << "## Cash remaining: " << players[turn].cash << " ##" << endl;
    }
    else if (mapBoard[pos].name.compare("Chance") == 0)
      random_event("chance", players, turn);
    else if (mapBoard[pos].name.compare("Destiny") == 0)
      random_event("destiny", players, turn);
    cout << endl << "Enter 0 to continue the game: ";
    cin >> choice;
  }
  return;
}
