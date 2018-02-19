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
std::vector<T> dictionary_sampling(const std::vector<T>& S, size_t m, RandomNumberGenerator& gen) {
  std::set<T> D;
  while( D.size() < m )
    D.insert(S[gen() % S.size()]);
  return std::vector<T>(D.begin(), D.end());
}
