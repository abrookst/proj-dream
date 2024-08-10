#ifndef ITEM_H
#define ITEM_H

#include "../action.h"
#include <string>

class Item : public Action{

public:
  virtual std::string GetName() const = 0;
  virtual std::string GetDescription() const = 0;

};
#endif
