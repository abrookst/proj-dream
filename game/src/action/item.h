#ifndef ITEM_H
#define ITEM_H

#include "action.h"
#include <string>

class Item : public Action{

public:
  virtual std::string GetName() const;
  virtual std::string GetDescription() const;

};
#endif
