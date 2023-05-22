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

const string NAME = "H";
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
	//freopen(fout.c_str(), "w", stdout);
}

int n, q, d[200003][32];

int main() {
	fast;
	fre();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		d[i][0] = x;
	}
	for (int i = 1; i <= 30; i++)
		for (int j = 1; j <= n; j++) d[j][i] = d[d[j][i - 1]][i - 1];
	while (q--) {
		int u, x;
		cin >> u >> x;
		for (int i = 30; i >= 0; i--) if (x >= (1 << i)) {
			u = d[u][i];
			x -= (1 << i);
		}
		cout << u << '\n';
	}
}
