/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>

template <class T>
std::vector<T> binary_search_intersection(const std::vector<T>& a, const std::vector<T>& b) {
  std::vector<T> intersection;
  intersection.reserve(std::min(a.size(), b.size()));
  std::vector<T> m = a;
  std::vector<T> n = b;
  if( m.size() > n.size() )
    std::swap(m, n);
  for(T x : m) {
    auto it = std::lower_bound(n.begin(), n.end(), x);
    if( it != n.end() && *it == x )
      intersection.push_back(x);  
  }
  return intersection;
}
