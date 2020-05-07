// richMan_load.cpp
#include <iostream>
#include <fstream>
#include "richMan_load.h"
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include <dirent.h>
#include "richMan_struct.h"

using namespace std;

void richMan_load(struct Block *mapBlocks, struct Status *&players, int &playerNo, int &round, int &turn){
  string slot_name;
  char save[10] = "save";
  DIR *dir= opendir(save);

  struct dirent *entry;
  struct stat info;

  if (!dir) {
    cout << "Directory was not found\n" << endl;
    return;
  }
  entry = readdir(dir);
  while ((entry = readdir(dir)) != NULL ){
    if ( entry->d_name[0] != '.'){
      string name = string(entry->d_name);
      name = name.erase(name.find(".txt"), 4);
      cout << name << endl;
      stat(name.c_str(), &info);
    }
  }
  closedir(dir);

  cout << "Which slot do you want to load? (Name of file)";
  string name;
  if (players[0].name != ""){
    cin >> slot_name;
  }
  else {slot_name = "default";}
  ifstream fin("save/"+slot_name+".txt"); //change the cmd when the name of directory changed
  if (fin.fail()) {
    //the error message to notify failed opening; (1) for importing text
    cout << "Error in the file opening!" << endl;
    exit(1);
  }
  int j = 0;
  while (fin >> name) {
    if (j < 36){
      mapBlocks[j].name = name;
      fin >> mapBlocks[j].price;
      fin >> mapBlocks[j].Lv;
      fin >> mapBlocks[j].ownership;
      if (j == 35) {
        fin >> playerNo;
        players = new Status[playerNo];
      }
    }
    else if (j > 35 && j < 36 + playerNo) {
      fin >> playerNo;
      players = new Status[playerNo];
      players[j-36].name = name;
      fin >> players[j-36].cash;
      fin >> players[j-36].property;
      fin >> players[j-36].position;
    }
    else {
      fin >> round;
      fin >> turn;
    }
    j++;
  }
  fin.close();
}
