#ifndef __IDOT_H__
#define __IDOT_H__

#include <string>

class IDot {
public:
  IDot(){};
  IDot(std::string fname){};
  virtual ~IDot(){};
  virtual void Node(std::string name) = 0;
  virtual void Edge(std::string src, std::string dest) = 0;
  virtual void Output() = 0;
};

#endif /* end of include guard: __IDOT_H__ */
