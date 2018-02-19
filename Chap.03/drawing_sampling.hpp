/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>

template <class T, class RandomNumberGenerator>
std::vector<T> drawing_sampling(const std::vector<T>& S, size_t m, RandomNumberGenerator& gen){
  std::vector<T> tmp(S.begin(), S.end());
  std::vector<T> out(m, T());
  for(size_t i=0; i<m; i++) {
    int p = gen() % (tmp.size()-i);
    out[i] = tmp[p];
    std::swap(tmp[p], tmp[tmp.size()-i-1]);
  }
  return out;
}
