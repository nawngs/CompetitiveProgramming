#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll get(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r) (rng);
}

int32_t main() {
	int t = get(1, 10);
	cout << t << '\n';
	while (t--) {
		int n = get(1, 100); cout << n << '\n';
		for (int i = 1; i <= n; i++) {
			if (get(0, 1)) cout << get(1, 10000) << ' ';
			else cout << get(-10000, -1) << ' ';
		}
		cout << '\n';
	}
}