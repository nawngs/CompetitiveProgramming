#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll get(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r) (rng);
}

map < pair < int, int >, bool > f;

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
	int n = get(8, 10), m = get(1, 25);
	cout << n << " " << m << '\n';
	for (int i = 1; i <= m; i++) {
		int l = get(1, n - 1), r = get(l + 1, n);
		while (f.find({l, r}) != f.end()) l = get(1, n - 1), r = get(l + 1, n);
		f[{l, r}] = 1;
		cout << l << " " << r << '\n';
	}
}