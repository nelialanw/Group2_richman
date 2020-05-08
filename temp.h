//richMan_load.h
#ifndef TEMP_H
#define TEMP_H
#include "richMan_struct.h"

void save_temp(Block *mapBlocks, Status *players, int n, int round, int turn, int mode);
void load_temp(Block *mapBlocks, Status *players, int n, int round, int turn, int mode);

#endif
