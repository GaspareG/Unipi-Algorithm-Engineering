/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>

template <class T>
std::vector<T> merge_intersection(const std::vector<T>& a, const std::vector<T>& b) {
  std::vector<T> intersection;
  intersection.reserve(std::min(a.size(), b.size()));
  auto x = a.begin();
  auto y = b.begin();
  while( x != a.end() && y != b.end() ) {
    if( *x == *y )
    {
      intersection.push_back(*x);
      ++x;
      ++y;
    }
    else if( *x < *y )
      ++x;  
    else
      ++y;
  }
  return intersection;
}
