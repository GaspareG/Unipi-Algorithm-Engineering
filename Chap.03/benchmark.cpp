/*
  License: GPL-3.0
  Author: Gaspare Ferraro <ferraro@gaspa.re>
*/

#include <bits/stdc++.h>
#include "dictionary_sampling.hpp"
#include "drawing_sampling.hpp"
#include "heap_sampling.hpp"
#include "reservoir_sampling.hpp"
#include "scanning_sampling.hpp"
#include "sorting_sampling.hpp"

#define NTEST 5

using namespace std;


int main()
{

  vector<int> size = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

  random_device rd;
  mt19937 rng(rd());

  for(size_t i=0; i<size.size(); ++i) {

    vector<int> S;
    for(int k=0; k<size[i]; ++k) S.push_back(k);

    for(size_t j=0; j<i; ++j) {

      clock_t drawing=0;
      clock_t dictionary=0;
      clock_t sorting=0;
      clock_t scanning=0;
      clock_t heap=0;
      clock_t reservoir=0;
      clock_t start=0;

      for(int k=0; k<NTEST; ++k) {

        start = clock();
        dictionary_sampling<int>(S, size[j], rng);
        dictionary += clock()-start;

        start = clock();
        drawing_sampling<int>(S, size[j], rng);
        drawing += clock()-start;

        start = clock();
        heap_sampling<int>(S, size[j], rng);
        heap += clock()-start;

        start = clock();
        reservoir_sampling<int>(S, size[j], rng);
        reservoir += clock()-start;

        start = clock();
        scanning_sampling<int>(S, size[j], rng);
        scanning += clock()-start;

      start = clock();
        sorting_sampling<int>(S, size[j], rng);
        sorting += clock()-start;

      }	

      double drawingd = (double) drawing / CLOCKS_PER_SEC / NTEST;
      double dictionaryd = (double) dictionary / CLOCKS_PER_SEC / NTEST;
      double sortingd = (double) sorting / CLOCKS_PER_SEC / NTEST;
      double scanningd = (double) scanning / CLOCKS_PER_SEC / NTEST;
      double heapd = (double) heap / CLOCKS_PER_SEC / NTEST;
      double reservoird = (double) reservoir / CLOCKS_PER_SEC / NTEST;

      printf("| %9d | %9d | %.6fs | %.6fs | %.6fs | %.6fs | %.6fs | %.6fs |\n", size[j], size[i], 
        drawingd, dictionaryd, sortingd, scanningd, heapd, reservoird);
      fflush(stdout);  
    }
  }


  return 0;
}

