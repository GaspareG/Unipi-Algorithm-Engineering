/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include "binary_code.hpp"

std::vector<bool> fixed_length_encode(int x, int length) {
  return binary_encode(x, length);
}


int fixed_length_decode(std::vector<bool>& s, int length) {
  return binary_decode(s);
}
