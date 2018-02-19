/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>

template <class T, class RandomNumberGenerator>
std::vector<T> scanning_sampling(const std::vector<T>& S, size_t m, RandomNumberGenerator& gen) {
  std::vector<T> out(m, 0);
  size_t s=0;
  for(size_t i=0; i<S.size(); ++i) {
    size_t p = gen() % (S.size()-i+1) ;
    if( p < m-s )
      out[s++] = S[i];
  }
  return out;
}
