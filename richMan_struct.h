#ifndef RICHMAN_STRUCT_H
#define RICHMAN_STRUCT_H

struct Block{
  std::string name;
  double price;
  int Lv;
  int ownership;
};

struct Status{
  std::string name;
  double cash;
  int property;
  int position;
};

#endif
