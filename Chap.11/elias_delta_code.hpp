/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include "unary_code.hpp"
#include "binary_code.hpp"

std::vector<bool> delta_encode(int x) {
  auto b = binary(x);
  auto u1 = binary(b.size());
  auto u2 = unary(u1.size());
  u2.pop_back();
  u2.insert(u2.end(), u1.begin(), u1.end());
  u2.insert(u2.end(), b.begin(), b.end());
  return u;
}

// TODO: use binary_decode with iterator
int delta_decode(const std::vector<bool>& s) {

}


