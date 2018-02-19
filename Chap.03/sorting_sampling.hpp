/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <set>
#include <utility>
#include <iterator>

template <class T, class RandomNumberGenerator>
std::vector<T> sorting_sampling(const std::vector<T>& S, size_t m, RandomNumberGenerator& gen) {
  std::set<T> D;
  while( D.size() < m ){
    D.clear();
    for(size_t i=0; i<m; ++i) {
        T k = S[gen() % S.size()];
        if( D.find(k) != D.end() ) break;
    	D.insert(k);
    }
  }
  return std::vector<T>(D.begin(), D.end());
}
