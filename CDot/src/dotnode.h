#ifndef __DOTNODE_H__
#define __DOTNODE_H__

#include <string>
#include <unordered_map>
#include <fstream>
#include "IDot.h"

class Cdotnode : public IDot {

public:
  Cdotnode(std::string fname);
  virtual ~Cdotnode();

  void Node(std::string name);
  void Edge(std::string src, std::string dest);
  void Output();

private:
  int _version = 0;
  std::string _fname;
  std::ofstream _ofs;
  // src -> dest
  std::unordered_map<std::string, std::string> _mp;
};

#endif /* end of include guard: __DOTNODE_H__ */
