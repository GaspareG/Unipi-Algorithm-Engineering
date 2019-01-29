#include <string>
#include <vector>
#include <utility>
#include <algorithm>

namespace ae
{
  namespace compressors
  {
    typedef std::tuple<int,int,char> lz77_t;  // <distance, length, char>

    std::vector<lz77_t> lz77_encode(const std::string &S)
    {
      int N = int(S.size());
      std::vector<lz77_t> ret;
      for(int i=0; i<N; i++)
      {
        int d=0, L=0;
        for(int j=0; j<i; j++)
        {
          int Lt=0;
          while(j+Lt < N && i+Lt < N && S[j+Lt] == S[i+Lt]) Lt++;
          if(Lt >= L)
          {
            L = Lt;
            d = i-j;
          }
        }
        char c = (i+L == N) ? '$' : S[i+L];
        ret.emplace_back(d, L, c);
        i += L;
      }
      return std::move(ret);
    }

    std::string lz77_decode(const std::vector<lz77_t> lz77)
    {
      std::string S;
      int l=0;
      for(auto &[d, L, c] : lz77)
      {
        for(int i=0; i<L; i++) S.push_back(S[l-d+i]);
        S.push_back(c);
        l += L+1;
      }
      return std::move(S);
    }

  }
}
