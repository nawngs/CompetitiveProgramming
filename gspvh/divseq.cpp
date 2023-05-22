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

const string NAME = "divseq";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, s[1000003], maxl[1000003], minr[1000003], maxr[1000003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	for (int i = 1; i <= n; i++) maxl[i] = max(maxl[i - 1], s[i]);
	minr[n] = s[n];
	maxr[n] = 0;
	for (int i = n - 1; i >= 1; i--) {
		minr[i] = min(minr[i + 1], s[i]);
		maxr[i] = max(maxr[i + 1], s[i] - minr[i]);
	}
	ll res = -INF;
	for (int i = 1; i <= n; i++) res = max(res, 2 * (maxl[i] - s[i] + maxr[i]) + s[n]);
	cout << res;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
