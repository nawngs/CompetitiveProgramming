#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll l, r, k, f[20][20][20][11][2][2];

vector < ll > a;

ll dp(ll pos, ll maxk, ll cur, ll pre, ll less, ll has1) {
	if (pos < 0) return (maxk >= k);
	if (f[pos][maxk][cur][pre][less][has1] != -1) return f[pos][maxk][cur][pre][less][has1];
	f[pos][maxk][cur][pre][less][has1] = 0;
	for (int i = 0; i <= 9; i++) {
		if (less || i <= a[pos]) {
			ll new_has1 = (has1 || i != 0);
			ll new_cur = (pre == i ? cur + 1 : 1);
			ll new_maxk = new_has1 ? max(maxk, new_cur) : 0;
			f[pos][maxk][cur][pre][less][has1] += dp(pos - 1, new_maxk, new_cur, i, less || i < a[pos], new_has1);
		}
	}
	return f[pos][maxk][cur][pre][less][has1];
}

ll calc(ll x) {
	a.clear();
	ll tam = x, m = -1;
	while (tam > 0) {
		a.push_back(tam % 10);
		m ++;
		tam /= 10;
	}
	if (m == -1) return 0;
	memset(f, 255, sizeof(f));
	dp(m, 0, 0, 0, 0, 0);
	return f[m][0][0][0][0][0];
}

void sol() {
	cin >> l >> r >> k;
	cout << calc(r) - calc(l - 1);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
