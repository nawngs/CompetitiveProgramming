#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t rnd(int64_t l, int64_t r) {
   return rng() % (r - l + 1) + l;
}

int a[500][500];

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int n = rnd(2, 100);
  cout << n << '\n';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cout << (a[i][j] = rnd(-1, 1)) << " \n"[j == n];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cout << (rnd(0, 1) ? -a[i][j] : a[i][j]) << " \n"[j == n];
  return 0;
}