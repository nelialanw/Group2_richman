// save_richman.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include "save_richman.h"
#include <dirent.h>

using namespace std;

void save_richman(string player_status){
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
  string stringpath = "save";
  int status = mkdir(stringpath.c_str(),0777);
  ofstream fout("save/"+slot_name+".txt");
  if (fout.fail()) {
    //the error message to notify failed opening; (2) for exporting text
    cout << "Error in the file opening!" << endl;
    exit(1);
  }
  fout << player_status << endl;
  fout.close();
}

int main(){
  save_richman("save");
  return 0;
}
