/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#include <bits/stdc++.h>
#include "binary_search_intersection.hpp"
#include "merge_intersection.hpp"
#include "doubling_search.hpp"
#include "mutual_partitioning.hpp"

using namespace std;

vector<int> randomSet(int size, int max, int min=1) {

  if( max < min ) return randomSet(size, min, max);
  assert( max-min+1 > size );

  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> uni(min, max);

  set<int> s;
  while( s.size() < size ) s.insert( uni(rng) );
  return vector<int>(s.begin(), s.end());    
}

int main()
{

  vector<int> size = {100, 1000, 10000, 100000, 1000000, 10000000};



  for(size_t i=0; i<size.size(); ++i) {
    for(size_t j=0; j<=i; ++j) {
      clock_t stl = 0;
      clock_t binary = 0;
      clock_t merge = 0;
      clock_t doubling = 0;
      clock_t mutual = 0;  
      clock_t start = 0;  

      for(int k=0; k<2; ++k) {
        vector<int> a = randomSet(size[i], 5*size[i]);
        vector<int> b = randomSet(size[j], 5*size[i]);
        vector<int> c(b.size());

        c.clear();
        start = clock();
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
        stl += clock()-start;

        c.clear();
        start = clock();
        binary_search_intersection<int>(a, b, c.begin());
        binary += clock()-start;

        c.clear();
        start = clock();
        merge_intersection<int>(a, b, c.begin());
        merge += clock()-start;

        c.clear();
        start = clock();
        doubling_search_intersection<int>(a, b, c.begin());
        doubling += clock()-start;

        c.clear();
        start = clock();
        mutual_partitioning_intersection<int>(a, b, c.begin());
        mutual += clock()-start;
      }	

      double stld = (double) stl / CLOCKS_PER_SEC;
      double merged = (double) merge / CLOCKS_PER_SEC;
      double binaryd = (double) binary / CLOCKS_PER_SEC;
      double mutuald = (double) mutual / CLOCKS_PER_SEC;
      double doublingd = (double) doubling / CLOCKS_PER_SEC;

      printf("| %8d | %8d | %.3fs | %.3fs | %.3fs | %.3fs | %.3fs |\n", size[j], size[i], stld, merged, binaryd, mutuald, doublingd);
      fflush(stdout);  
    }
  }


  return 0;
}

