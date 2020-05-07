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
      cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[i+j*(j*27-i*2)].name << '|';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      if (mapBlocks[0].price != 0)
        cout << "|price: " << setfill(' ') << setw(6) << left << mapBlocks[i+j*(j*27-i*2)].price << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      if (mapBlocks[0].Lv != 0)
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

    for (int i = 0; i < 8; i++)
    {
      cout << setfill('-') << setw(15) << '-' << setfill(' ') << setw(120) << ' ' << setfill('-') << setw(15) << '-' <<endl;
      cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[35-i].name << '|' << setfill(' ') << setw(120) << ' '
      << '|' << setfill(' ') << setw(13) << left << mapBlocks[10+i].name << '|' <<endl;

      if (mapBlocks[35-i].price != 0)
        cout << "|price: " << setfill(' ') << setw(6) << left << mapBlocks[35-i].price << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
      cout << setfill(' ') << setw(120) << ' ';
      if (mapBlocks[10+i].price != 0)
        cout << "|price: " << setfill(' ') << setw(6) << left << mapBlocks[10+i].price << '|' << endl;
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|' << endl;

      if (mapBlocks[35-i].Lv != 0)
        cout << "|Lv: " << setfill(' ') << setw(9) << left << mapBlocks[35-i].Lv << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
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
      cout << setfill(' ') << setw(120) << ' ';
      if (playerNo > 3 && players[3].position == 10+i)
        cout << '|' << setfill(' ') << setw(6) << left << players[4].name << ' ';
      else
        cout << "|       ";
      if (playerNo > 4 && players[4].position == 10+i)
        cout << setfill(' ') << setw(6) << left << players[4].name << '|' << endl;
      else
        cout << "      |" << endl;

      cout << setfill('-') << setw(15) << '-' << setfill(' ') << setw(120) << ' ' << setfill('-') << setw(15) << '-' << endl;
    }
  }

  return;
}
