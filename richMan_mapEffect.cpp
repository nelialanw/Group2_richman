#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "richMan_display.h"
#include "richMan_mapEffect.h"
#include "richMan_randomevent.h"

using namespace std;

void mapEffect(int dice, int turn, Block *mapBoard, Status *players, int playerNo, int *freeze){
  int choice = 1;
  int pos = players[turn].position;
  while (choice && (mode ==1 || (mode == 2 && turn ==0)))
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
    else if (mapBoard[pos].ownership == turn && players[turn].cash >= mapBoard[pos].price*0.1)
    {
      int invest;
      cout << "Invest " << mapBoard[pos].price*0.1 << " to upgrade " << mapBoard[pos].name << " ? (1:yes 0:No)";
      cin >> invest;
      if(invest)
      {
        mapBoard[pos].Lv += 1;
        players[turn].cash -= mapBoard[pos].price*0.1;
        mapBoard[pos].price *= 1.1;
        cout << "## Successfully upgrade " << mapBoard[pos].name << " to Lv: " << mapBoard[pos].Lv << " ##" << endl
        << "## Value of " << mapBoard[pos].name << " become $" << mapBoard[pos].price << " ##" << endl
        << "## Cash remaining: " << players[turn].cash << " ##" << endl;
      }
    }
    else if(mapBoard[pos].ownership >= 0 && mapBoard[pos].ownership < playerNo && mapBoard[pos].ownership != turn)
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
    {
      random_event("destiny", players, turn);
      if (players[turn].position == 9)
      {
        freeze[turn] = 3;
      }
      if (players[turn].position == 18)
      {
        freeze[turn] = 2;
      }
    }
    cout << endl << "Enter 0 to continue the game: ";
    cin >> choice;
  }
  
  while (choice && mode == 2 && turn !=0)
  {
    if (players[turn].cash > mapBoard[pos].price && mapBoard[pos].ownership == -1)
    {
      int buy;
      cout << "Buy " << mapBoard[pos].name << "(price: "<< mapBoard[pos].price << ')' << " ? (1:buy 0:not buy)";
      srand(time(NULL));
      buy = rand()%2;
      if (buy)
      {
        mapBoard[pos].ownership = turn;
        players[turn].cash -= mapBoard[pos].price;
        cout << "## " << players[mapBoard[pos].ownership].name << " become the owner of " << mapBoard[pos].name << " ##" << endl
        << "## Cash remaining: " << players[turn].cash << " ##" << endl;
        players[turn].property += 1;
      }
    }
    else if (mapBoard[pos].ownership == turn && players[turn].cash >= mapBoard[pos].price*0.1)
    {
      int invest = 1;
      if(invest)
      {
        mapBoard[pos].Lv += 1;
        players[turn].cash -= mapBoard[pos].price*0.1;
        mapBoard[pos].price *= 1.1;
      }
    }
    else if(mapBoard[pos].ownership >= 0 && mapBoard[pos].ownership < playerNo && mapBoard[pos].ownership != turn)
    {
      players[turn].cash -= mapBoard[pos].price*0.1;
      players[mapBoard[pos].ownership].cash += mapBoard[pos].price*0.1;
    }
    else if (mapBoard[pos].name.compare("Chance") == 0)
    {
      random_event("chance", players, turn);
    }
    else if (mapBoard[pos].name.compare("Destiny") == 0)
    {
      random_event("destiny", players, turn);
      if (players[turn].position == 9)
      {
        freeze[turn] = 3;
      }
      if (players[turn].position == 18)
      {
        freeze[turn] = 2;
      }
    }
    choice = 0;
  }
  
  return;
}
