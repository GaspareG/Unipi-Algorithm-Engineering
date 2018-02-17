/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include "unary_code.hpp"
#include "binary_code.hpp"

std::vector<bool> gamma_encode(int x) {
  auto b = binary(x);
  auto u = unary(b.size());
  u.pop_back();
  u.insert(u.end(), b.begin(), b.end());
  return u;
}

// TODO: use binary_decode with iterator
int gamma_decode(const std::vector<bool>& s) {
  int length = unary_decode(s);
  int x=0;
  while( length < s.size() )
    x = (x<<1) + s[x];
  return x;
}

