#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll get(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r) (rng);
}

int32_t main() {
	int n = get(5, 10), k = get(1, n);
	cout << n << " " << k << '\n';
	for (int i = 1; i <= n; i++) 
		cout << get(1, 10) << ' ';
	cout << '\n';
	for (int i = 2; i <= n; i++) cout << get(1, i - 1) << " " << i << '\n';
}