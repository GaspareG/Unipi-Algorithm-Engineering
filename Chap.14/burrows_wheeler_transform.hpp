#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

namespace ae
{
  namespace btw
  {
    std::string bwt_encode(const std::string &S)
    {
      int N = int(S.size());
      std::string Sr(N+1, 0);
      std::iota(Sr.begin(), Sr.end(), 0);
      auto c = [&](const int i){
        if(i < N) return S[i];
        if(i == N) return '$';
        return S[i-N-1];
      };
      std::sort(Sr.begin(), Sr.end(), [&](int i, int j)
      {
        while(c(i) == c(j)) i++, j++;
        return c(i) < c(j);
      });
      for(int i=0; i<=N; i++) Sr[i] = c(Sr[i]+N);
      return std::move(Sr);
    }

    std::string bwt_decode(const std::string &S)
    {
      int N = int(S.size()), idx = 0;
      std::vector<std::string> V(N, "");
      for(int i=0; i<N; i++)
      {
        for(int j=0; j<N; j++) V[j] = S[j] + V[j];
        std::sort(V.begin(), V.end());
      }
      return V[0];
    }

    /*
    std::string bwt_encode(const std::string &S)
    {
      std::vector<int> SA = ae::sa::suffix_array(S+'$');
      std::string Sr(S.size()+1, '$');
      for(size_t i=0; i<SA.size(); i++)
        Sr[i] = (SA[i] > 0) ? S[SA[i]-1]  : '$';
      return std::move(Sr);
    }
    */
  }
}
