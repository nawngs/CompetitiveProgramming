#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t rnd(int64_t l, int64_t r) {
   return rng() % (r - l + 1) + l;
}

const int INF = 1E9 + 7;

int a[500];

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int n = rnd(10, 15);
  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    a[i] = rnd(5, INF);
    cout << a[i] << " ";
  } 
  cout << '\n';
  for (int i = 1; i <= n; i++) {
    cout << rnd(1, a[i]) << " ";
  }
}