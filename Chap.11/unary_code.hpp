/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>

std::vector<bool> unary_encode(int x, bool delimiter=true){
  std::vector<bool> ret(x, !delimiter);
  ret[x-1] = delimiter;
  return ret;
}

int unary_decode(std::vector<bool>::iterator first, std::vector<bool>::iterator last, bool delimiter=true) {
  int x=0;
  while( first != last && *first != delimiter)
    ++first, ++x;
  return x+1;
}

int unary_decode(std::vector<bool> s, bool delimiter=true){
  return unary_decode(s.begin(), s.end());
}
