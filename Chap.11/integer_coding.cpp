#include <algorithm>
#include <vector>
#include <bitset>
#include <iostream>
#include <iterator> 

// TODO Refactor in separate files
using namespace std;

int log2(int x){
  int i=0;
  while( (1<<i) <= x ) i++;
  return i;
}

int toDecimal(vector<bool> s)
{
  int r=0;
  for(bool b : s)
    r = (r<<1) + b;
  return r;
}

vector<bool> binary(int x) {
  if( x == 0 ) return vector<bool>();
  int s = log2(x);
  vector<bool> b(s, 0);
  do {
    b[--s] = x & 1;
  } while( (x>>=1) > 0 );
  return b;
}

vector<bool> unary(int x, bool z=false, int def=0) {
  vector<bool> u(x + z, def);
  u[x-1+z] = 1-def;
  return u;
}


vector<bool> gamma(int x) {
  vector<bool> g;
  vector<bool> u = unary(log2(x));
  vector<bool> b = binary(x);
  g.insert(g.end(), u.begin(), u.end());
  g.pop_back();
  g.insert(g.end(), b.begin(), b.end());
  return g;
}

vector<bool> delta(int x) {
  vector<bool> d;
  vector<bool> b = binary(x);
  vector<bool> l = binary(log2(x));
  vector<bool> u = unary(log2(log2(x)));
  d.insert(d.end(), u.begin(), u.end());
  d.pop_back();
  d.insert(d.end(), l.begin(), l.end());
  d.insert(d.end(), b.begin(), b.end());
  return d;
}

// TODO check
vector<bool> rice(int k, int x)
{
  int q = (x-1)>>k;
  int r = x & ((1<<k)-1);
  vector<bool> rice;
  vector<bool> u = unary(q);
  vector<bool> b = binary(r);
  rice.insert(rice.end(), u.begin(), u.end());
  rice.insert(rice.end(), b.begin(), b.end());
  return rice;
}

vector<bool> binaryCode(int x, int a, int b)
{
  vector<bool> xb = binary(x-a);
  vector<bool> r(log2(b-a+1)-xb.size(), 0);
  r.insert(r.end(), xb.begin(), xb.end());
  return r;
}

vector<bool> interpolativeCoding(vector<int> S, int l, int r, int low, int high)
{
  if( r < l ) return vector<bool>();
  if( l == r ) return binaryCode(S[l], low, high);
  int m = (l+r)>>1;
  vector<bool> A1 = binaryCode(S[m], low+m-l, high-r+m);
  vector<bool> A2 = interpolativeCoding(S, l, m-1, low, S[m]-1);
  vector<bool> A3 = interpolativeCoding(S, m+1, r, S[m]+1, high);
  A1.insert(A1.end(), A2.begin(), A2.end());
  A1.insert(A1.end(), A3.begin(), A3.end());
  return A1;
}

vector<bool> interpolativeCoding(vector<int> S) {
  return interpolativeCoding(S, 0, S.size()-1, S[0], S[S.size()-1]);
}

pair<vector<bool>, vector<bool>> eliasFano(vector<int> S)
{
  int u = (1<<log2(S[S.size()-1])); // TODO CHECK
  int l = (log2((double) u / S.size()));
  int h = log2(u)-l;
  vector<bool> H, L;
  vector<int> freq(1<<h, 0);
//  printf("U[%d] L[%d] H[%d]\n", u, l, h);
  for(int s : S)
  {
//    printf("S = %d\n", s);
    int f = 0;
    int i = (l+h)-binary(s).size();
    for(auto b : binary(s))
    {
      if( i < h )
        f = (f<<1) + b;
      else
        L.push_back(b);
      i++;
    }
    freq[f]++;
  }
//  printf("Ok\n");
  for(int f : freq)
  {
    vector<bool> uf = unary(f, true);
    H.insert(H.end(), uf.begin(), uf.end());
  }
  return make_pair(H, L);
}


void printb(vector<bool> b)
{
  for(auto v : b)
    cout << (v ? "1" : "0");
  cout << endl;
}
int main()
{

  vector<int> path;
  path.push_back(1);
  path.push_back(2);
  path.push_back(3);
  path.push_back(5);
  path.push_back(7);
  path.push_back(9);
  path.push_back(11);
  path.push_back(15);
  path.push_back(18);
  path.push_back(19);
  path.push_back(20);
  path.push_back(21);
  printb(interpolativeCoding(path));


  for(int i=1; i<16; i++)
  {
    printf("unary(%2d) = ", i);
    printb(unary(i));
  }
 
  for(int i=1; i<16; i++)
  {
    printf("binary(%2d) = ", i);
    printb(binary(i));
  }

  for(int i=1; i<16; i++)
  {
    printf("gamma(%2d) = ", i);
    printb(gamma(i));
  }
 
  for(int i=1; i<16; i++)
  {
    printf("delta(%2d) = ", i);
    printb(delta(i));
  }
 
    printf("rice[4](%2d) = ", 83);
    printb(rice(4, 83));

  path.clear();
  path.push_back(1);
  path.push_back(4);
  path.push_back(7);
  path.push_back(18);
  path.push_back(24);
  path.push_back(26);
  path.push_back(30);
  path.push_back(31);

  printf("H = ");
  printb(eliasFano(path).first);
  printf("L = ");
  printb(eliasFano(path).second);

  // L = 0100111000101011
  //      100111000101011
  // H = 1011000100110110
  //     0100111011001001
}
