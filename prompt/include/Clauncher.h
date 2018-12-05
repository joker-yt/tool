#ifndef __CLANUCHER_H__
#define __CLANUCHER_H__

#include "Ccommand.h"
#include <vector>
using namespace std;

class Clauncher {
private:
  vector<Ccommand *> _com;
  char _param[64];

  static const int QUIT = -1;
  static const int NONE = 0;

  void waiting_for_command() {
    memset(_param, 0, sizeof(_param));

    cin.getline(_param, sizeof(_param));
  }

  void usage() {
    for_each(_com.begin(), _com.end(), [](Ccommand *com) {
      cout << com->name() << " : " << com->key() << endl;
    });
  }

  Ccommand *search_command() {
    for (auto com : _com) {
      if (!strcmp(com->key().c_str(), _param))
        return com;
    }

    cout << "??" << endl;
    return nullptr;
  };
  int invoked(Ccommand *com) {
    if (com->name() == "quit")
      return QUIT;

    string str{_param};
    com->func(str);
  };

public:
  Clauncher() { _com.push_back(new Ccommand{"quit", "q", nullptr}); };
  virtual ~Clauncher(){};

  virtual void exec() {
    while (1) {
      system("clear");
      cout << "======================================" << endl;
      usage();
      cout << "======================================" << endl;

      waiting_for_command();

      Ccommand *com = search_command();

      if (com != nullptr && invoked(com) == Clauncher::QUIT)
        break;
    }
  }

  void append(Ccommand *com) { _com.push_back(com); };
};

#endif /* end of include guard: __CLANUCHER_H__ */
