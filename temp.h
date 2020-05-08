//richMan_load.h
#ifndef RICHMAN_LOAD_H
#define RICHMAN_LOAD_H
#include "richMan_struct.h"

void save_temp(Block *mapBlocks, Status *players, int n, int round, int turn, int mode);
void load_temp(Block *mapBlocks, Status *players, int n, int round, int turn, int mode);

#endif