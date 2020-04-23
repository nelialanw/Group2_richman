#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

string random_event(string event)
{
  string temp, result;
  int random_number, i=0;
  srand(time(NULL));
  random_number = rand() %5;
  ifstream fin(event + ".txt");
  if (fin.fail()) {
    //the error message to notify failed opening; (1) for importing text
    cout << "Error in the file opening!(1)" << endl;
    exit(1);
  }
  while (fin >> temp)
  {
    i++;
    if (i == random_number)
    {
      result = temp;
    }
  }
  return result;
}
