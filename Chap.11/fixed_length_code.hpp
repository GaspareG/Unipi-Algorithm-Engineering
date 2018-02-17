/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include "binary_code.hpp"

int log2(int x) {
  int k=0;
  while( (1<<k) <= x ) k++;
  return k;
}

std::vector<bool> fixed_length_encode(int x, int length) {
  return binary_encode(x, length);
}


int fixed_length_decode(const std::vector<bool>& s, int length) {
  return binary_decode(s);
}
