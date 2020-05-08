#include <iostream>
#include <string>
#include <iomanip>
#include "richMan_display.h"
#include "richMan_struct.h"

using namespace std;

void displayMap(Block *mapBlocks, Status *players, int playerNo){
  for (int j = 0; j < 2; j++)
  {
    for (int i = 0; i < 10; i++)
    {
      cout << setfill('-') << setw(15) << '-';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      if (i+j*(j*27-i*2) == 27)
        cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[i+j*(j*27-i*2)].name.substr(0,9) << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[i+j*(j*27-i*2)].name << '|';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      if (mapBlocks[i+j*(j*27-i*2)].price != 0)
        cout << "|price: " << setfill(' ') << setw(6) << left << mapBlocks[i+j*(j*27-i*2)].price << '|';
      else if (i+j*(j*27-i*2) == 27)
        cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[i+j*(j*27-i*2)].name.substr(9,8) << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      if (mapBlocks[i+j*(j*27-i*2)].Lv != 0)
        cout << "|Lv: " << setfill(' ') << setw(9) << left << mapBlocks[i+j*(j*27-i*2)].Lv << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      if (players[0].position == i+j*(j*27-i*2))
        cout << '|' << setfill(' ') << setw(6) << left << players[0].name << ' ';
      else
        cout << "|       ";
      if (players[1].position == i+j*(j*27-i*2))
        cout << setfill(' ') << setw(6) << left << players[1].name << '|';
      else
        cout << "      |";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      if (playerNo > 2 && players[2].position == i+j*(j*27-i*2))
        cout << '|' << setfill(' ') << setw(6) << left << players[2].name << ' ';
      else
        cout << "|       ";
      if (playerNo > 3 && players[3].position == i+j*(j*27-i*2))
        cout << setfill(' ') << setw(6) << left << players[3].name << '|';
      else
        cout << "      |";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      cout << setfill('-') << setw(15) << '-';
    }
    cout << endl;

    if (j == 1)
      break;
    int temp = playerNo;
    for (int i = 0; i < 8; i++)
    {
      cout << setfill('-') << setw(15) << '-' << setfill(' ') << setw(120) << ' ' << setfill('-') << setw(15) << '-' <<endl;
      cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[35-i].name << '|' << setfill(' ') << setw(120) << ' '
      << '|' << setfill(' ') << setw(13) << left << mapBlocks[10+i].name << '|' <<endl;

      if (mapBlocks[35-i].price != 0)
        cout << "|price: " << setfill(' ') << setw(6) << left << mapBlocks[35-i].price << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
      if ( i>0 && playerNo-i > -1)
        cout << setfill(' ') << setw(40) << ' ' << setw(30) << players[i-1].name << setfill(' ') << setw(50) << ' ' ;
      else
        cout << setfill(' ') << setw(120) << ' ';
      if (mapBlocks[10+i].price != 0)
        cout << "|price: " << setfill(' ') << setw(6) << left << mapBlocks[10+i].price << '|' << endl;
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|' << endl;

      if (mapBlocks[35-i].Lv != 0)
        cout << "|Lv: " << setfill(' ') << setw(9) << left << mapBlocks[35-i].Lv << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
      if ( i>0 && playerNo-i > -1)
        cout << setfill(' ') << setw(40) << ' ' << setw(20) << "Cash on hand: "<< setw(10) << players[i-1].cash << setfill(' ') << setw(50) << ' ' ;
      else
        cout << setfill(' ') << setw(120) << ' ';
      if (mapBlocks[10+i].Lv != 0)
        cout << "|Lv: " << setfill(' ') << setw(9) << left << mapBlocks[10+i].Lv << '|' <<endl;
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|' << endl;

      if (players[0].position == 35-i)
        cout << '|' << setfill(' ') << setw(6) << left << players[0].name << ' ';
      else
        cout << "|       ";
      if (players[1].position == 35-i)
        cout << setfill(' ') << setw(6) << left << players[1].name << '|';
      else
        cout << "      |";
      if ( i>0 && playerNo-i > -1)
        cout << setfill(' ') << setw(40) << ' ' << setw(20) << "Property Owned: " << setw(10) << players[i-1].property << setfill(' ') << setw(50) << ' ' ;
      else
        cout << setfill(' ') << setw(120) << ' ';
      if (players[0].position == 10+i)
        cout << '|' << setfill(' ') << setw(6) << left << players[0].name << ' ';
      else
        cout << "|       ";
      if (players[1].position == 10+i)
        cout << setfill(' ') << setw(6) << left << players[1].name << '|' << endl;
      else
        cout << "      |" << endl;

      if (playerNo > 2 && players[2].position == 35-i)
        cout << '|' << setfill(' ') << setw(6) << left << players[2].name << ' ';
      else
        cout << "|       ";
      if (playerNo > 3 && players[3].position == 35-i)
        cout << setfill(' ') << setw(6) << left << players[3].name << '|';
      else
        cout << "      |";
      if ( i>0 && playerNo-i > -1)
        cout << setfill(' ') << setw(40) << ' ' << setw(20) << "Position: " << setw(10) << mapBlocks[players[i-1].position].name << setfill(' ') << setw(50) << ' ' ;
      else
        cout << setfill(' ') << setw(120) << ' ';
      if (playerNo > 2 && players[2].position == 10+i)
        cout << '|' << setfill(' ') << setw(6) << left << players[2].name << ' ';
      else
        cout << "|       ";
      if (playerNo > 3 && players[3].position == 10+i)
        cout << setfill(' ') << setw(6) << left << players[3].name << '|' << endl;
      else
        cout << "      |" << endl;

      cout << setfill('-') << setw(15) << '-' << setfill(' ') << setw(120) << ' ' << setfill('-') << setw(15) << '-' << endl;
    }
  }

  return;
}
