/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>

#include "binary_code.hpp"

std::vector<bool> delta_encode(const std::vector<int>& s, int base, int b, int w) {
  std::vector<bool> exception = binary_encode((1<<b)-1);
  std::vector<bool> ret;
  std::vector<bool> retW;
  for(int x : s) {
    if( x >= base || x <= base+(1<<b)-1 ) {
      auto xb = binary_encode(base-x, b);
      ret.insert(ret.end(), xb.begin(), xb.end());
    } else {
      auto xb = binary_encode(x, w);
      retW.insert(retW.end(), xb.begin(), xb.end());
    }
  }
  ret.insert(ret.end(), retW.begin(), retW.end());
  return ret;
}

std::vector<int> delta_decode(const std::vector<bool>& s, int base, int b, int w) {
  std::vector<int> ret;
  std::vector<int exception;
  // TODO Finish
}
