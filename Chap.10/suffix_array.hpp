#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

namespace ae
{
  namespace substring
  {
    std::vector<int> suffix_array_naive(const std::string &S)
    {
      int N = int(S.size());
      std::vector<int> V(N+1, 0);
      std::iota(V.begin(), V.end(), 0);
      auto c = [&](const int i){ return (i == N) ? '$' : S[i]; );
      std::sort(V.begin(), V.end(), [&](int i, int j)
      {
        while(i < N && j < N && c[i] == c[j]) i++, j++;
        return c[i] < c[j];
      });
      return std::move(V);
    }
  }
}
