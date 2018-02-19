/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>

template <class T>
typename std::vector<T>::iterator binary_search_intersection(const std::vector<T>& a, const std::vector<T>& b, typename std::vector<T>::iterator result) {
  std::vector<T> m = a;
  std::vector<T> n = b;
  if( m.size() > n.size() )
    std::swap(m, n);
  for(T x : m) {
    auto it = std::lower_bound(n.begin(), n.end(), x);
    if( it != n.end() && *it == x ){
      *result = *it;
      ++result;
    }  
  }
  return result;
}
