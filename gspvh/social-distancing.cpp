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

const string NAME = "social-distancing";
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

int d, n, cntx[1003], cnty[1003], cnt[1003][1003];

int main() {
	fast;
	fre();
	cin >> d >> n;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		x = ((x % d) + d) % d;
		y = ((y % d) + d) % d;
		cntx[x] ++;
		cnty[y] ++;
		cnt[x][y] ++;
	}
	int res = INF;
	for (int i = 0; i < d; i++) 
		for (int j = 0; j < d; j++) 
			res = min(res, cntx[i] + cnty[j] - cnt[i][j]);
	cout << res << '\n';
}
