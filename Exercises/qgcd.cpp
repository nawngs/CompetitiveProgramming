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

const string NAME = "qgcd";
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

int n, a[200003], st[200003][20];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i][0] = a[i];
	}
	for (int t = 1; t <= 18; t++) {
		for (int i = 1; i <= n; i++) {
			if (i + (1 << t) - 1 > n) break;
			st[i][t] = __gcd(st[i][t - 1], st[i + (1 << (t - 1))][t - 1]);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int t = log2(r - l + 1);
		cout << __gcd(st[l][t], st[r - (1 << t) + 1][t]) << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
