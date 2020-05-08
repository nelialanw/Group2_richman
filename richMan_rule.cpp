// richMan_rule.cpp
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void rule()
{
  ifstream fin("readme.txt"); //change the cmd when the name of directory changed
  if (fin.fail())
  {
    //the error message to notify failed opening; (1) for importing text
    cout << "Error in the file opening!" << endl;
    exit(1);
  }

  string line;
  while (getline(fin, line))
  {
    cout << line << endl;
  }
  fin.close();

  return;
}
