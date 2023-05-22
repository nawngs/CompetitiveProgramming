#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, f[100003], pw[200003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	pw[0] = 1;
	for (int i = 1; i <= 2 * n; i++)
		pw[i] = (pw[i - 1] * 26) % MOD;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) 
			f[i] = (f[i] + pw[i / 2 + 1] * i) % MOD;
		else {
			f[i] = (f[i] + pw[i / 2] * i / 2) % MOD;
			f[i] = (f[i] + pw[i / 2 + 1] * i / 2) % MOD;
		}
		for (int k = 2; k * k <= i; k++) {
			if (i % k == 0) {
				f[i] = (f[i] - k * f[i / k] + MOD * MOD) % MOD;
				if (k != i / k) f[i] = (f[i] - (i / k) * f[k] + MOD * MOD) % MOD;
			} 
		}
		if (i > 1) f[i] = (f[i] - f[1] * i + MOD * MOD) % MOD;
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j+=i) res = (res + f[i]) % MOD;
	}
	cout << res;
}