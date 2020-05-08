// richMan_bankrupt.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "richMan_struct.h"
#include "richMan_bankrupt.h"

using namespace std;

void richMan_bankrupt(struct Status *&players, int &playerNo, int player_bankrupt){
  int i = 0;
  while (i<player_bankrupt)
  {
    i++;
  }
  while (i<playerNo-1)
  {
    players[i] = players[i+1];
    i++;
  }
  players[i] = {};
  playerNo-=1;

}
