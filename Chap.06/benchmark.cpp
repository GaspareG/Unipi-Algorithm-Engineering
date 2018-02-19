/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#include <bits/stdc++.h>
#include "binary_search_intersection.hpp"
#include "merge_intersection.hpp"
#include "doubling_search.hpp"
#include "mutual_partitioning.hpp"
#define NTEST 10

using namespace std;

vector<int> randomSet(int size, int max, int min=1) {

  if( max < min ) return randomSet(size, min, max);
  assert( max-min+1 > size );
  random_device rd;
  mt19937 rng(rd());
  vector<int> s(max-min+1);
  for(int i=min; i<max; i++) s.push_back(i);
  shuffle (s.begin(), s.end(), rng);
  vector<int> ret(s.begin(), s.begin()+size);    
  sort(ret.begin(), ret.end());
  return ret;
}

int main()
{

  vector<int> size = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

  for(size_t i=0; i<size.size(); ++i) {
    for(size_t j=0; j<=i; ++j) {

      clock_t stl = 0;
      clock_t binary = 0;
      clock_t merge = 0;
      clock_t doubling = 0;
      clock_t mutual = 0;  
      clock_t start = 0; 
 
      vector<int> a = randomSet(size[j], 2*size[i]);
      vector<int> b = randomSet(size[i], 2*size[i]);

      for(int k=0; k<NTEST; ++k) {
        vector<int> c(a.size()), d(a.size()), e(a.size()), f(a.size()), g(a.size());

        start = clock();
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
        stl += clock()-start;

        start = clock();
        merge_intersection<int>(a, b, d.begin());
        merge += clock()-start;

        start = clock();
        binary_search_intersection<int>(a, b, e.begin());
        binary += clock()-start;

        start = clock();
        doubling_search_intersection<int>(a, b, f.begin());
        doubling += clock()-start;

        start = clock();
        mutual_partitioning_intersection<int>(a, b, g.begin());
        mutual += clock()-start;
      }	

      double stld = (double) stl / CLOCKS_PER_SEC / NTEST;
      double merged = (double) merge / CLOCKS_PER_SEC / NTEST;
      double binaryd = (double) binary / CLOCKS_PER_SEC / NTEST;
      double mutuald = (double) mutual / CLOCKS_PER_SEC / NTEST;
      double doublingd = (double) doubling / CLOCKS_PER_SEC / NTEST;

      printf("| %9d | %9d | %.6fs | %.6fs | %.6fs | %.6fs | %.6fs |\n", size[j], size[i], stld, merged, binaryd, mutuald, doublingd);
      fflush(stdout);  
    }
  }


  return 0;
}

