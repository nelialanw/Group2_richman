#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

/*struct Block{
  string name;
  double price;
  int Lv;
  string player[4];
  int ownership;
};*/

//Block mapBlocks[36];
//const int blockCols = 17;
//const int blockRows = 6;

void displayMap(Block *mapBlocks){
  for (int j = 0; j < 2; j++)
  {
    for (int i = 0; i < 10; i++)
    {
      cout << setfill('-') << setw(15) << '-';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[i+(j*27-i*2)].name << '|';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      if (mapBlocks[0].price != 0)
        cout << "|price: " << setfill(' ') << setw(6) << left << mapBlocks[i+(j*27-i*2)].price << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      if (mapBlocks[0].Lv != 0)
        cout << "|Lv: " << setfill(' ') << setw(9) << left << mapBlocks[i+(j*27-i*2)].Lv << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[i+(j*27-i*2)].player[0] + ' ' + mapBlocks[i+(j*27-i*2)].player[1] << '|';
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
      cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[i+(j*27-i*2)].player[2] + ' ' + mapBlocks[i+(j*27-i*2)].player[3] << '|';
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

      if (mapBlocks[0].price != 0)
        cout << "|price: " << setfill(' ') << setw(6) << left << mapBlocks[35-i].price << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
      cout << setfill(' ') << setw(120) << ' ';
      if (mapBlocks[0].price != 0)
        cout << "|price: " << setfill(' ') << setw(6) << left << mapBlocks[10+i].price << '|' << endl;
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|' << endl;

      if (mapBlocks[0].Lv != 0)
        cout << "|Lv: " << setfill(' ') << setw(9) << left << mapBlocks[35-i].Lv << '|';
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|';
      cout << setfill(' ') << setw(120) << ' ';
      if (mapBlocks[0].Lv != 0)
        cout << "|Lv: " << setfill(' ') << setw(9) << left << mapBlocks[10+i].Lv << '|' <<endl;
      else
        cout << '|' << setfill(' ') << setw(13) << ' ' << '|' << endl;

      cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[35-i].player[0] + ' ' + mapBlocks[35-i].player[1] << '|' << setfill(' ') << setw(120) << ' '
      << '|' << setfill(' ') << setw(13) << left << mapBlocks[10+i].player[0] + ' ' + mapBlocks[10+i].player[1] << '|' << endl;
      cout << '|' << setfill(' ') << setw(13) << left << mapBlocks[35-i].player[2] + ' ' + mapBlocks[35-i].player[3] << '|' << setfill(' ') << setw(120) << ' '
      << '|' << setfill(' ') << setw(13) << left << mapBlocks[10+i].player[2] + ' ' + mapBlocks[10+i].player[3] << '|' << endl;
      cout << setfill('-') << setw(15) << '-' << setfill(' ') << setw(120) << ' ' << setfill('-') << setw(15) << '-' << endl;
    }
  }

  return;
}
