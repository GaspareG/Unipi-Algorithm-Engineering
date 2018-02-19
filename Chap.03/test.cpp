#include <bits/stdc++.h>
#include "dictionary_sampling.hpp"
#include "drawing_sampling.hpp"
#include "heap_sampling.hpp"
#include "reservoir_sampling.hpp"
#include "scanning_sampling.hpp"
#include "sorting_sampling.hpp"

#define NTEST 100000

using namespace std;

int main(){

  random_device rd;
  mt19937 rng(rd());

  vector<int> S;
  map<int, int> dictH;
  map<int, int> drawH;
  map<int, int> heapH;
  map<int, int> reservoirH;
  map<int, int> scanningH;
  map<int, int> sortingH;

  for(int i=0; i<100; i++) S.push_back(i);

  for(int i=0; i<NTEST; i++) {
    auto dict = dictionary_sampling<int>(S, 10, rng);
    auto draw = drawing_sampling<int>(S, 10, rng);
    auto heap = heap_sampling<int>(S, 10, rng);
    auto reservoir = reservoir_sampling<int>(S, 10, rng);
    auto scanning = scanning_sampling<int>(S, 10, rng);
    auto sorting = sorting_sampling<int>(S, 10, rng);

    for(int x: dict) dictH[x]++;
    for(int x: draw) drawH[x]++;
    for(int x: heap) heapH[x]++; 
    for(int x: reservoir) reservoirH[x]++;
    for(int x: scanning) scanningH[x]++;
    for(int x: sorting) sortingH[x]++;
  }

  for(int i=0; i<100; i++)
    printf("[%3d] %6d %6d %6d %6d %6d %6d\n", i, dictH[i],  drawH[i],  heapH[i],  reservoirH[i],  scanningH[i],  sortingH[i]);

}
