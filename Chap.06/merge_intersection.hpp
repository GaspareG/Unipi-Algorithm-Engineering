/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#pragma once

#include <vector>
#include <utility>
#include <iterator>

template <class T>
typename std::vector<T>::iterator merge_intersection(const std::vector<T>& a, const std::vector<T>& b, typename std::vector<T>::iterator result) {
  auto x = a.begin();
  auto y = b.begin();
  while( x != a.end() && y != b.end() ) {
    if( *x < *y ) ++x;
    else if( *y < *x ) ++y;
    else {
      *result = *x;
      ++result;
      ++x;
      ++y;
    }
  }
  return result;
}
