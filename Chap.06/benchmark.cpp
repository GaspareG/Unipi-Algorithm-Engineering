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

  set  
    
}

int main()
{


  set<int> sa, sb;
  while( sa.size() < 50 ) sa.insert( uni(rng) );
  while( sb.size() < 20 ) sb.insert( uni(rng) );

  vector<int> a(sa.begin(), sa.end());
  vector<int> b(sb.begin(), sb.end());
  vector<int> c(20);

  auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
  c.resize(it-c.begin());

  auto d = binary_search_intersection<int>(a, b);
  auto e = merge_intersection<int>(a, b);
  auto f = doubling_search_intersection<int>(a, b);
  auto g = mutual_partitioning_intersection<int>(a, b);

  printf("stl set_intersection:\n\t");
  for(auto x : c)
    printf("%d ", x);
  printf("\n");

  printf("binary_search_intersection:\n\t");
  for(auto x : d)
    printf("%d ", x);
  printf("\n");

  printf("merge_intersection:\n\t");
  for(auto x : e)
    printf("%d ", x);
  printf("\n");

  printf("doubling_search_intersection:\n\t");
  for(auto x : f)
    printf("%d ", x);
  printf("\n");

  printf("mutual_partitioning:\n\t");
  for(auto x : g)
    printf("%d ", x);
  printf("\n");

  return 0;
}

