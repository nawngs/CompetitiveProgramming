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
const ll nmax = 1e6;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[nmax + 3], cnt[nmax + 3];

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j < i; j++) cnt[__gcd(a[i], a[j])] = (cnt[__gcd(a[i], a[j])] + a[i] * a[j]) % MOD;
	}
	for (int i = nmax; i >= 1; i--) {
		if (cnt[i] != 0) cout << i << " " << cnt[i] << '\n';
	}
}
