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

int main()
{

  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> uni(1, 100);

  set<int> sa, sb;
  while( sa.size() < 50 ) sa.insert( uni(rng) );
  while( sb.size() < 20 ) sb.insert( uni(rng) );

  vector<int> a(sa.begin(), sa.end());
  vector<int> b(sb.begin(), sb.end());
  vector<int> c(20), d(20), e(20), f(20), g(20);

  auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
  c.resize(it-c.begin());
  printf("stl set_intersection:\n\t");
  for(auto x : c)
    printf("%d ", x);
  printf("\n");

  it = binary_search_intersection<int>(a, b, d.begin());
  d.resize(it-d.begin());
  printf("binary_search_intersection:\n\t");
  for(auto x : d)
    printf("%d ", x);
  printf("\n");

  it = merge_intersection<int>(a, b, e.begin());
  e.resize(it-e.begin());
  printf("merge_intersection:\n\t");
  for(auto x : e)
    printf("%d ", x);
  printf("\n");

  it = doubling_search_intersection<int>(a, b, f.begin());
  f.resize(it-f.begin());
  printf("doubling_search_intersection:\n\t");
  for(auto x : f)
    printf("%d ", x);
  printf("\n");

  it = mutual_partitioning_intersection<int>(a, b, g.begin());
  g.resize(it-g.begin());
  printf("mutual_partitioning:\n\t");
  for(auto x : g)
    printf("%d ", x);
  printf("\n");


  return 0;
}

