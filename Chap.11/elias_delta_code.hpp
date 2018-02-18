/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include "unary_code.hpp"
#include "binary_code.hpp"

std::vector<bool> delta_encode(int x) {
  auto b = binary_encode(x);
  auto u1 = binary_encode(b.size());
  auto u2 = unary_encode(u1.size());
  u2.pop_back();
  u2.insert(u2.end(), u1.begin(), u1.end());
  u2.insert(u2.end(), b.begin(), b.end());
  return u2;
}

int delta_decode(std::vector<bool> s) {
  int l = unary_decode(s);
  int y = binary_decode(s.begin()+l-1, s.begin()+2*l-1);
  int x = binary_decode(s.begin()+2*l-1, s.begin()+2*l+y-1);
  return x;
}


