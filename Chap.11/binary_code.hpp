/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>

int log2(int x) {
  int k=0;
  while( (1<<k) <= x ) k++;
  return k;
}

std::vector<bool> binary_encode(int x, int fl=0) {
  int l=log2(x);
  std::vector<bool> r(std::max(fl, l), 0);
  int start=(fl<l)?0:(fl-l)-1;
  do
    r[++start] = x&1;
  while( (x>>=1) > 0 );
  return r;
}


int binary_decode(const std::vector<bool>& s) {
  int x=0;
  for(auto b : s)
    x = (x<<1)+b;
  return x;
}
