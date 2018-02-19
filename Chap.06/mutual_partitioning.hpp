/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>

template <class T>
typename std::vector<T>::iterator mutual_partitioning_intersection(const std::vector<T>& a, const std::vector<T>& b, typename std::vector<T>::iterator result, 
  int as, int ae, int bs, int be) {
  if( as >= ae || bs >= be ) return result;
  int m = (bs+be)/2;
  auto jit = std::lower_bound(a.begin()+as, a.begin()+ae, b[m]);
  int j = std::distance(a.begin(), jit);
  result = mutual_partitioning_intersection(a, b, result, as, j, bs, m);
  if( *jit == b[m] ) {
    *result = b[m];
    ++result;
  }
  result = mutual_partitioning_intersection(a, b, result, j, ae, m+1, be);
  return result;
}

template <class T>
typename std::vector<T>::iterator mutual_partitioning_intersection(const std::vector<T>& a, const std::vector<T>& b, typename std::vector<T>::iterator result) {
  std::vector<T> m = a;
  std::vector<T> n = b;
  if( m.size() > n.size() )
    std::swap(m, n);
  return mutual_partitioning_intersection(a, b, result, 0, a.size(), 0, b.size());
}


