#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[200003];

namespace sub1 {
	ll res[200003];
	void solve() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
				if ((i | j) < n) res[(i | j)] = (res[(i | j)] + a[i] * a[j]) % MOD;
		for (int i = 0; i < n; i++) {
			res[i] += res[i - 1];
			res[i] %= MOD;
			cout << res[i] << ' ';
		}
	}
}

namespace ac {
	ll s[200003], dp[200003];
	void solve() {
		for (int i = 0; i < n; i++) s[i] = a[i];
		for (int i = 0; i < 20; i++)
			for (int mask = 0; mask < n; mask++) 
				if (mask & (1 << i)) s[mask] = (s[mask] + s[mask ^ (1 << i)]) % MOD;
		for (int i = 0; i < n; i++) s[i] = (s[i] * s[i]) % MOD;
		for (int i = 0; i < 20; i++)
			for (int mask = 0; mask < n; mask++) 
				if (mask & (1 << i)) s[mask] = (s[mask] - s[mask ^ (1 << i)] + MOD) % MOD;
		cout << s[0] << ' ';
		for (int i = 1; i < n; i++) {
			s[i] += s[i - 1];
			s[i] %= MOD;
			cout << s[i] << " ";
		}
	}
}


int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n <= 10000) sub1::solve();
	else ac::solve();
}
