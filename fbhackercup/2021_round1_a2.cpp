#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1000000007;

ll t, n;
string s;

ll sol(string s) {
	ll tamo = -1;
	ll tamx = -1;
	ll res = 0;
	s = ' ' + s;
	ll pre = -1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'O') {
			tamo = i;
			if (tamx != -1 && pre != 1) {
				res += min(tamo, tamx) * (n - max(tamo, tamx) + 1);
			}
			pre = 1;

		}
		if (s[i] == 'X') {
			tamx = i;
			if (tamo != -1 && pre != 2) {
				res += min(tamo, tamx) * (n - max(tamo, tamx) + 1);
			}
			pre = 2;
		}
		res %= MOD;
	}
	return res;
}

int main() {
	freopen("2021_round1_a2.inp", "r", stdin);
	freopen("2021_round1_a2.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> s;
		cout << "Case #" << i << ": " << sol(s) << '\n';
	}
}