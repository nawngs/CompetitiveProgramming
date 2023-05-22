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

const string NAME = "amn";
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

int n, m, ii, jj, a[503][503];

pii maxa[503], maxj[503], maxi[503];

int main() {
	fast;
	fre();
	cin >> n >> m >> ii >> jj;
	for (int i = 1; i <= n; i++) {
		maxa[i].se = i;
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			maxa[i].fi = max(maxa[i].fi, a[i][j]);
		}
	}
	sort(maxa + 1, maxa + n + 1, greater < pii >());
	for (int j = 1; j <= m; j++) {
		maxj[j] = {a[maxa[1].se][j], j};
	}
	sort(maxj + 1, maxj + m + 1, greater < pii > ());
	for (int i = 1; i <= n; i++)
		maxi[i] = {a[i][maxj[1].se], i};
	sort(maxi + 1, maxi + n + 1, greater < pii > ());
	cout << a[maxi[ii].se][maxj[jj].se] << '\n';
}