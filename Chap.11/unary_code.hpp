/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>

std::vector<bool> unary_encode(int x, bool delimiter=true){
  std::vector<bool> ret(x, !delimiter);
  ret[x-1] = delimiter;
  return ret;
}

int unary_decode(const std::vector<bool>& s, bool delimiter=true){
  auto it = s.begin();
  while( it != s.end() && *it != delimiter )
    ++it;
  return distance(s.begin(), it)+1;
}
