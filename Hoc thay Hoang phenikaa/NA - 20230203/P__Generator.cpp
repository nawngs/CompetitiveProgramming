#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t rnd(int64_t l, int64_t r) {
   return rng() % (r - l + 1) + l;
}

int a[500][500];

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int n = rnd(1, 10);
  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    int l = rnd(1, 5), r = rnd(l, 10);
    cout << l << " " << r << '\n';
  }
  int q = 5;
  cout << q << '\n';
  while (q--) {
     int l = rnd(1, 10), r = rnd(l, 20);
     cout << l << " " << r << '\n';
  }
}