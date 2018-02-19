/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>

template <class T, class RandomNumberGenerator>
std::vector<T> reservoir_sampling(const std::vector<T>& S, size_t m, RandomNumberGenerator& gen) {
  std::vector<T> out(S.begin(), S.begin()+m);
  auto start = S.begin()+m;
  while( start != S.end() ) {
    size_t h = gen() % (start-S.begin());
    if( h < m )
      out[h] = *start;
    start++;
  }
  return out;
}
