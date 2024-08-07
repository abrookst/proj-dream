#ifndef ITEM_H
#define ITEM_H

#include "action.h"
#include <string>

class Item : public Action{

protected:
  const static std::string name;

public:
  std::string GetName() const { return name; };

};
#endif
