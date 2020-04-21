// save_richman.h
#ifndef SAVE_RICHMAN_H
#define SAVE_RICHMAN_H
//#include <boost/filesystem.hpp>
//using namespace boost::filesystem;

int save_richman(string players_status, string game_status)
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
  cout << "Which slot do you want to overwrite? (Name of file)";
  cin >> slot_name;
  string stringpath = "save";
  int status = mkdir(stringpath.c_str(),0777);
  ofstream fout("save/"+slot_name;
  if (fout.fail()) {
    //the error message to notify failed opening; (2) for exporting text
    cout << "Error in the file opening!" << endl;
    exit(1);
  }
  fout << player_status << endl;
  fout << game_status << endl;
  fout.close();
  return 1;
#endif
