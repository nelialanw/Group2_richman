// richMan_load.cpp
#include <iostream>
#include <fstream>
#include "richMan_load.h"
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include <dirent.h>

using namespace std;

void load_richman(char *save){
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
  cin >> slot_name;
  string stringpath = "save";
  //int status = mkdir(stringpath.c_str(),0777);
  string status;
  ifstream fin("save/"+slot_name+".txt"); //change the cmd when the name of directory changed
  if (fin.fail()) {
    //the error message to notify failed opening; (1) for importing text
    cout << "Error in the file opening!" << endl;
    exit(1);
  }
  while (getline(fin, status)) {
    cout << status << endl;
  }
  fin.close();
}

int main(){
  char save[10] = "save";
  load_richman(save);
  return 0;
}
