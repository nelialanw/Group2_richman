// load_richman.h
#ifndef LOAD_RICHMAN_H
#define LOAD_RICHMAN_H
//#include <boost/filesystem.hpp>
//using namespace boost::filesystem;

void load_richman()
  string slot_name;
  path p("/save/");
  int j = 1;
  for (auto i = directory_iterator(p); i != directory_iterator(); i++)
  {
    if (!is_directory(i->path()))
    {
      cout << i->path().filename.string() << endl;
      j++;
    }
    else
      continue;
  }
  cout << "Which slot do you want to load? (Name of file)";
  cin >> slot_name;
  string stringpath = "save";
  int status = mkdir(stringpath.c_str(),0777);
  ifstream fin("save/"+slot_name); //change the cmd when the name of directory changed
  if (fin.fail()) {
    //the error message to notify failed opening; (1) for importing text
    cout << "Error in the file opening!" << endl;
    exit(1);
  }
  while (fin >> status) {
    //use linked_list, depends on main()'s format
  }
  fin.close();
#endif
