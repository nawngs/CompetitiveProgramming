#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll get(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r) (rng);
}

int32_t main() {
	int n = get(100, 200); cout << n << ' ';
	for (int i = 1; i <= n; i++) {
		char c = 'a' + get(0, 20); cout << c;
	}
	cout << ' ';
	int q = get(1, 200); cout << q << '\n';
	while (q--) {
		int l = get(1, n), r = get(l, n);
		cout << l << " " << r << '\n';
	}
}