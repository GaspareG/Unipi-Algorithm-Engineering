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

  vector<int> out(size, 0);
  for(int i=0; i<size; i++)
    out[i] = min+i;
  for(int i=size; i<max; i++)
  {
    int j = rng() % i;
    if( j < size )
      out[j] = i;
  }
  sort(out.begin(), out.end());
  return out;    
}

int main()
{

  vector<int> size = {100, 1000, 10000, 100000, 1000000, 10000000};

  vector<int> a = randomSet(size[4], 3*size[5]);
  vector<int> b = randomSet(size[5], 3*size[5]);

	for(int k=0; k<100; k++){
		clock_t doubling = 0;
		clock_t start = 0;

		vector<int> c(b.size());
		c.clear();
		start = clock();
		doubling_search_intersection<int>(a, b, c.begin());
		doubling += clock()-start;
		double doublingd = (double) doubling / CLOCKS_PER_SEC;

		printf("| %8d | %8d | %.3fs |\n", size[4], size[5], doublingd);
		fflush(stdout);  
	}	

  return 0;
}

