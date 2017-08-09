#include "binary.h"

namespace MyTool {
unsigned char CharToBin(char ch) {
  if ('0' <= ch && ch <= '9')
    return static_cast<unsigned char>(ch - '0');
  else if ('A' <= ch && ch <= 'F')
    return static_cast<unsigned char>(ch - 'A' + 0x0AU);
  else if ('a' <= ch && ch <= 'f')
    return static_cast<unsigned char>(ch - 'a' + 0x0AU);
  else
    ; // do nothing

  return 0x00U;
}

/*! \fn char BinToChar(unsigned char dt)
 * @brief Hex binary to character
 * @detail if you need upper case, you can use "upper(BinToChar(bin))"
 */
char BinToChar(unsigned char dt) {
  if (0x00U <= dt && dt <= 0x09U)
    return static_cast<char>(dt + '0');
  else if (0x0AU <= dt && dt <= 0x0FU)
    return static_cast<char>(dt - 0x0AU + 'a');
  else
    ; // do nothing
  return 0x00;
}
}
