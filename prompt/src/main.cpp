#include "Ccommand.h"
#include "Clauncher.h"
#include <iostream>

void template_function(string arg) {
  cout << __FUNCTION__ << " has been invoked." << endl;
  string dummy;
  cin >> dummy;
}

int main(int argc, char *argv[]) {

  Clauncher launcher;

  launcher.append(new Ccommand{"sample", "t",
                               new function<void(string)>{template_function}});

  launcher.exec();

  return 0;
}
