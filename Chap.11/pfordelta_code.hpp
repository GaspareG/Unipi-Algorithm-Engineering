/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include "binary_code.hpp"

std::vector<bool> delta_encode(std::vector<int> s, int base, int b, int w) {
  std::vector<bool> exception = binary_encode((1<<b)-1);
  std::vector<bool> ret;
  std::vector<bool> retW;
  for(int x : s) {
    if( x >= base || x < base+(1<<b)-1 ) {
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

std::vector<int> delta_decode(std::vector<bool> s, int base, int b, int w) {
  std::vector<int> ret;
  std::vector<int> exception;
  int escape = (1<<b)-1;
  size_t length = s.size();
  size_t start = 0;
  while( start < length ) {
    int xb = binary_decode(s.begin()+start,s.begin()+start+b);
    if( xb == escape ) {
      length -= w;
    } else {
      ret.push_back(xb);
    }
    start += b;
  }
  while( length < s.size() ) {
    int xw = binary_decode(s.begin()+length, s.begin()+length+w);
    exception.push_back(xw);
    length += w;
  }
  ret.insert(ret.end(), exception.begin(), exception.end());
  return ret;
}
