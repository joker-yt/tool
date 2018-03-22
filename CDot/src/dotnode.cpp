#include "dotnode.h"

using namespace std;

const string None{""};

Cdotnode::Cdotnode(std::string fname) {

  _fname = fname;
  _ofs.open(fname);
  _ofs << "digraph {";
};

Cdotnode::~Cdotnode() {

  _ofs << "}";

  _ofs.close();
}

void Cdotnode::Node(string name) { _ofs << name << ";"; };

void Cdotnode::Edge(string src, string dest) {
  _ofs << src << " -> " << dest << ";";
  _mp.insert(make_pair(src, dest));
}

void Cdotnode::Output() {
  string f = _fname;
  string v = to_string(_version);

  string fname = [&f, &v]() -> string { return f + "_" + v; }();

  ofstream ofs{fname};
  ofs << "digraph {";
  for (auto n : _mp)
    ofs << n.first << " -> " << n.second << ";";

  ofs << "}";
  ofs.close();
}
