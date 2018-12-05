#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <algorithm>
#include <functional>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

/*! @class Ccommand
    @brief  the object of command to be invoked by Clauncher
*/
class Ccommand {
private:
  string _name;
  string _key;
  function<void(string)> *_f;

public:
  Ccommand(string name, string key, function<void(string)> *f)
      : _name(name), _key(key), _f(f){};
  virtual ~Ccommand(){};
  const string &name() { return _name; }
  const string &key() { return _key; }
  void func(string param) { (*_f)(param); }
};

#endif /* end of include guard: __COMMAND_H__ */
