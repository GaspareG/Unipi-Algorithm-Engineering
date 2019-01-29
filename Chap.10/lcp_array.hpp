#include <vector>
#include <string>
#include "suffix_array.hpp"

namespace ae
{
  namespace substring
  {
    std::vector<int> lcp_array_naive(const std::string &S)
    {
      int N = int(S.size()), h=0;
      std::vector<int> Sa = ae::substring:suffix_array_naive(S);
      std::vector<int> Sar(N, 0);
      std::vector<int> lcp(N, 0);
      for(int i=0; i<N; i++) Sar[Sa[i]] = i;
      for(int i=0; i<N; i++)
      {
        int q = Sar[i];
        if(q > 0)
        {
          int k = Sa[q-1];
          if(h > 0) h--;
          while(S[k+h] == S[i+h]) h++;
          lcp[q-1] = h;
        }
      }
      return std::move(lcp);
    }
  }
}

