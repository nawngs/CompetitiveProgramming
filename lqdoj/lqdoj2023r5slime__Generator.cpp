#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll rnd(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r) (rng);
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  const int MAXN = 10, MAXS = 16;
  int n = rnd(1, MAXN), s = rnd(1, MAXS);
  cout << n << ' ' << s << '\n';
  for (int i = 1; i <= n; i++)
  	cout << rnd(1, s) << ' ';
  return 0;
}