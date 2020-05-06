// richMan_load.cpp
#include <iostream>
#include <fstream>
#include "richMan_load.h"
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include <dirent.h>

using namespace std;

void load_richman(struct Block *mapBlocks, struct Status *players){
  string slot_name;
  //const char save[10] = "save";
  DIR *dir= opendir(save);

  struct dirent *entry;
  struct stat info;

  if (!dir) {
    cout << "Directory was not found\n" << endl;
    return;
  }
  entry = readdir(dir);
//(entry = readdir(dir)) != NULL
  while ((entry = readdir(dir)) != NULL ){
    if ( entry->d_name[0] != '.'){
      string name = string(entry->d_name);
      name = name.erase(name.find(".txt"), 4);
      cout << name << endl;
      stat(name.c_str(), &info);
          /*if (S_ISDIR(info.st_mode)) {
            load_richman(save);
          }*/
    }
  }
  closedir(dir);

  cout << "Which slot do you want to load? (Name of file)";
  string slot_name;
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
  while (fin >> name)) {
    if (j < 36){
      name = mapBlocks[j].name;
      fin >> mapBlocks[j].price;
      fin >> mapBlocks[j].Lv;
      fin >> mapBlocks[j].ownership;
    }
    else {
      name = players[j-36].name;
      fin >> players[j-36].cash;
      fin >> players[j-36].property;
      fin >> players[j-36].position;
    }
    j++;
  }
  fin.close();
}
