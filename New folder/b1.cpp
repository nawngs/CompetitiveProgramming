#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("b1.inp", "r", stdin);
	freopen("b2.out", "w", stdout);
	cin >> x;
	ll res = 1;
	for (int i = 2; i * i <= x; i++) {
		int cnt = 0;
		while (x % i == 0) {
			x /= i;
			cnt ^= 1;
		}
		if (cnt == 1) res *= i;
	}
	res *= x;
	cout << res;
}

