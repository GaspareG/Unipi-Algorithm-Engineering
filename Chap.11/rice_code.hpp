/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include "binary_code.hpp"
#include "unary_code.hpp"

std::vector<bool> rice_encode(int k, int x) {
  int q = (x-1)>>k;
  int r = x-1-(1<<k)*q;
  auto ret = unary_encode(q+1);
  auto rem = binary_encode(r, k);
  ret.insert(ret.end(), rem.begin(), rem.end());
  return ret;
}

int rice_decode(int k, std::vector<bool> s) {
  int q = unary_decode(s);
  int r = binary_decode(s.begin()+q, s.end());
  int x = ((q-1)<<k)+r+1;
  return x;
}
