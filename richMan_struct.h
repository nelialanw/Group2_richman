#ifndef RICHMAN_STRUCT_H
#define RICHMAN_STRUCT_H

struct Block{
  std::string name;
  double price;
  int Lv;
  std::string ownership;
};

struct Status{
  std::string name;
  int cash;
  int property;
  int position;
};

#endif
