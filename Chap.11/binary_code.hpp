/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>

int log2(int x) {
  int k=0;
  while( (1<<k) <= x ) k++;
  return k;
}

std::vector<bool> binary_encode(int x, int fl=0) {
  int l=log2(x);
  std::vector<bool> r(std::max(fl, l), 0);
  int start=r.size();
  do
    r[--start] = x&1;
  while( (x>>=1) > 0 );
  return r;
}

int binary_decode(std::vector<bool>::iterator first, std::vector<bool>::iterator last) {
  int x=0;
  while( first != last ) {
    x = (x<<1) + *first;
    ++first;
  }
  return x;
}

int binary_decode(std::vector<bool> s) {
  return binary_decode(s.begin(), s.end());
}

