#include "mytime.h"
#include <time.h>
#include <string.h>

const int BUF_SIZ = 32; 
char *strtime() {
  static char *buf = new char[BUF_SIZ];

  time_t t = time(NULL);
  struct tm *ptm = localtime(&t);
  strftime(buf, sizeof(char) * BUF_SIZ, "%A %Y-%m-%d %H:%M:%S", ptm);

  return buf;
}
