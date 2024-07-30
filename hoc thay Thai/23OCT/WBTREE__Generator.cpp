#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll get(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r) (rng);
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
	int n = get(5, 15), q = get(20, 50);
	cout << n << " " << q << '\n';
	for (int i = 1; i <= n; i++) cout << get(0, 1);
	cout << '\n';
	for (int i = 2; i <= n; i++) cout << get(1, i - 1) << " ";
	cout << '\n';
	while (q--) 
		cout << get(1, 2) << " " << get(1, n) << '\n';
}