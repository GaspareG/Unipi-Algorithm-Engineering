/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <stdio.h>
#include <vector>
#include "unary_code.hpp"
#include "binary_code.hpp"

std::vector<bool> gamma_encode(int x) {
  auto b = binary_encode(x);
  auto u = unary_encode(b.size());
  u.pop_back();
  u.insert(u.end(), b.begin(), b.end());
  return u;
}

int gamma_decode(const std::vector<bool>& s) {
  return binary_decode(s);
}

