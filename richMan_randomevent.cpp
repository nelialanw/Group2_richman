//richMan_randomevent.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include "richMan_struct.h"
#include "richMan_randomevent.h"


using namespace std;

void random_event(string event, struct Status *players, int player_code)
{
  string result;
  int random_number, i=0;
  random_number = rand() %10;
  ifstream fin("event/" + event + ".txt");
  if (fin.fail()) {
    //the error message to notify failed opening; (1) for importing text
    cout << "Error in the file opening!(1)" << endl;
    exit(1);
  }
  int j = 0;
  while (j != random_number)
  {
    string temp;
    getline(fin, temp);
    getline(fin, temp);
    j++;
  }
  if (j == random_number){
    string temp;
    int read_num;
    fin >> temp;
    fin >> read_num;
    if (temp == "a") {
      for (int i = 0; i<4 ;i++){
        players[i].cash += read_num;
      }
    }
    else {
      players[player_code].cash += read_num;
    }
    fin >> read_num;
    if (j < 2) {
      players[player_code].position = read_num;
    }
    else {
      players[player_code].position += read_num;
    }
    getline(fin,temp);
    cout << temp << endl;
    getline(fin,temp);
    cout << temp << endl;
  }
  fin.close();
}
