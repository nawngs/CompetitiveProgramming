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

ll n, k, unlucky = 0, frac[100003], dp[100003];

map < int, int > f;

bool check(int x) {
	while (x > 0) {
		if (x % 10 != 4 && x % 10 != 7) return false;
		x /= 10;
	}
	return true;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % MOD, MOD - 2)) % MOD;
}

int main() {
	fast;
	//fre();
	cin >> n >> k;
	frac[0] = 1;
	for (int i = 1; i <= n; i++) frac[i] = (frac[i - 1] * i) % MOD;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if(check(x)) f[x] ++;
		else unlucky ++;
	}
	dp[0] = 1;
	for (auto x : f) {
		for (int i = k; i >= 1; i--)
			dp[i] = (dp[i] + dp[i - 1] * x.se) % MOD;
	}
	ll res = 0;
	for (int i = 0; i <= k; i++) 		
		res = (res + dp[i] * C(k - i, unlucky)) % MOD;
	cout << res;
}
