/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include "binary_code.hpp"

std::vector<bool> binaryCode(int x, int a, int b)
{
  std::vector<bool> xb = binary_encode(x-a);
  std::vector<bool> r(log2(b-a+1)-xb.size(), 0);
  r.insert(r.end(), xb.begin(), xb.end());
  return r;
}

std::vector<bool> interpolativeCoding(std::vector<int> S, int l, int r, int low, int high)
{
  if( r < l ) return std::vector<bool>();
  if( l == r ) return binaryCode(S[l], low, high);
  int m = (l+r)>>1;
  std::vector<bool> A1 = binaryCode(S[m], low+m-l, high-r+m);
  std::vector<bool> A2 = interpolativeCoding(S, l, m-1, low, S[m]-1);
  std::vector<bool> A3 = interpolativeCoding(S, m+1, r, S[m]+1, high);
  A1.insert(A1.end(), A2.begin(), A2.end());
  A1.insert(A1.end(), A3.begin(), A3.end());
  return A1;
}

std::vector<bool> interpolativeCoding(std::vector<int> S) {
  return interpolativeCoding(S, 0, S.size()-1, S[0], S[S.size()-1]);
}

