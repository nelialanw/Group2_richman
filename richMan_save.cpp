// richMan_save.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include "richMan_save.h"
#include <dirent.h>
#include "richMan_struct.h"

using namespace std;

void richMan_save(Block *mapBlocks, Status *players, int n, int round, int turn, int mode, int *freeze){
  string slot_name;
  DIR *dir = opendir("save");

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

  cout << "Which slot do you want to overwrite? (Name of file)";
  cin >> slot_name;
  ofstream fout("save/"+slot_name+".txt");
  if (fout.fail()) {
    //the error message to notify failed opening; (2) for exporting text
    cout << "Error in the file opening!" << endl;
    exit(1);
  }

  int j = 0;
  while (j < 36+n+1) {
    if (j <36) {
      fout << mapBlocks[j].name << " "
        << mapBlocks[j].price << " "
        << mapBlocks[j].Lv << " "
        << mapBlocks[j].ownership;
      if (j == 35) {
        fout << " " << n;
      }
      fout << endl;
    }
    else if (j > 35 && j < 36+n) {
      fout << players[j-36].name << " "
        << players[j-36].cash << " "
        << players[j-36].property << " "
        << players[j-36].position << endl;
    }
    else {
      fout << round << " " << turn << " " << mode << ' ';
      for (int i = 0; i < n; i++)
      {
        if (i != n-1)
        {
          cout << freeze[i] << ' ';
        }
        else
        {
          cout << freeze[i] << endl;
        }
      }
    }
    j++;
  }
  fout.close();
}
