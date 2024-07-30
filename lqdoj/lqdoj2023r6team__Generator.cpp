#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll get(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r) (rng);
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
	int t = get(1, 5); cout << t << '\n';
	for (int test = 1; test <= t; test++) {
		int n = get(100, 500), m = get(n / 2, n), l = get(1, m), r = get(l, m);
		cout << n << " " << m << " " << l << " " << r << '\n';
		for (int i = 1; i <= n; i++) cout << get(1, m) << " ";
		cout << '\n';
	}
}