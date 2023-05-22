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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll l, r, f[1000003], cnt[1000003];

void sieve() {
	for (int i = 1; i <= nmax; i++) f[i] = i;
	for (int i = 2; i * i <= nmax; i++)
		if (f[i] == i) for (int j = i * i; j <= nmax; j+= i) f[j] = i;
}

void sol() {
	cin >> l >> r;
	memset(cnt, 0, sizeof(cnt));
	for (int i = l; i <= r; i++) {
		ll x = i;
		while (x > 1) {
			cnt[f[x]] ++;
			x /= f[x];
		}
	}	
	ll ans = 1;
	for (int i = 2; i <= nmax; i++) {
		if (cnt[i] != 0) ans *= (cnt[i] * 2 + 1);
		ans %= MOD;
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	sieve();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
