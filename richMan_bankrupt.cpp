// richMan_bankrupt.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "richMan_struct.h"
#include "richMan_bankrupt.h"

using namespace std;

void richMan_bankrupt(struct Status *&players, Block *mapBlocks, int *&freeze, int &playerNo, int player_bankrupt){
  int i = 0;
  for (int i = 0; i < 36; i++)
  {
    if (mapBlocks[i].ownership == player_bankrupt)
    {
      mapBlocks[i].ownership = -1;
    }
  }
  while (i<player_bankrupt)
  {
    i++;
  }
  cout << players[player_bankrupt].name << " is bankrupted!!" << endl;
  while (i<playerNo-1)
  {
    players[i] = players[i+1];
    freeze[i] = freeze[i+1];
    i++;
  }
  players[i] = {};
  freeze[i] = {};
  playerNo-=1;
}
