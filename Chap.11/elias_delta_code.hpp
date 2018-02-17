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

// TODO: use binary_decode with iterator
int delta_decode(const std::vector<bool>& s) {
  size_t l = unary_decode(s);
  size_t y = 0;
  int x = 0;
  for(size_t i=l-1; i<2*l; i++)
    y = (y<<1) + s[i];
  for(size_t i=2*l-1; i<s.size(); i++)
    x = (x<<1) + s[i];
  return x;
}


