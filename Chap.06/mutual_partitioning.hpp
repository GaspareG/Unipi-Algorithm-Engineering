/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>

// TODO: Improve memory usage in resurise call
template <class T>
std::vector<T> mutual_partitioning_intersection(const std::vector<T>& a, const std::vector<T>& b, 
  int as, int ae, int bs, int be) {
  if( as >= ae || bs >= be ) return std::vector<T>();
  int m = (bs+be)/2;
  auto jit = std::lower_bound(a.begin()+as, a.begin()+ae, b[m]);
  int j = std::distance(a.begin(), jit);
  auto r1 = mutual_partitioning_intersection(a, b, as, j, bs, m);
  auto r2 = mutual_partitioning_intersection(a, b, j, ae, m+1, be);
  if( *jit == b[m] ) r1.push_back(b[m]);
  r1.insert(r1.end(), r2.begin(), r2.end());
  return r1;
}

template <class T>
std::vector<T> mutual_partitioning_intersection(const std::vector<T>& a, const std::vector<T>& b) {
  std::vector<T> m = a;
  std::vector<T> n = b;
  if( m.size() > n.size() )
    std::swap(m, n);
  return mutual_partitioning_intersection(a, b, 0, a.size(), 0, b.size());
}


