/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>
#include <queue>
#include <climits>

template <class T, class RandomNumberGenerator>
std::vector<T> heap_sampling(const std::vector<T>& S, size_t m, RandomNumberGenerator& gen) {
  std::priority_queue< std::pair<double, T> > Q;
  std::vector<T> out;
  for(size_t i=0; i<m; i++) Q.push(std::pair<double, T>(1., S[0]));
  for(T s : S) {
    double r = (double) (gen() % INT_MAX)/INT_MAX;
    if( r < Q.top().first ) {
      Q.pop();
      Q.push(std::make_pair(r, s));
    } 
  }
  while( !Q.empty() ) {
    out.push_back(Q.top().second);
    Q.pop();
  }
  return out;
}
