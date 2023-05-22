#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t rnd(int64_t l, int64_t r) {
   return rng() % (r - l + 1) + l;
}

int a[500][500];

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int n = rnd(2, 5), m = rnd(2, 5);
  cout << n << " " << m << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) 
      cout << (rnd(0, 2) ? "." : "#");
    cout << '\n';
  }
  return 0;
}