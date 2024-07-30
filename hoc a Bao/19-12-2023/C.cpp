#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r
#define int ll

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 50;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

ll dp[N + 3][22][N + 3][22];

pair < string, int > a[N + 3];

ll calc(int i, int szi, int j, int szj) {
	if (dp[i][szi][j][szj] != -1) return dp[i][szi][j][szj];
	ll &res = dp[i][szi][j][szj]; res = LINF;
	if (szi < szj) {
		int li = a[i].fi.size() - szi;
		for (int p = 0; p < szi; p++) if (a[i].fi[li + p] != a[j].fi[szj - p - 1]) return res;
		szj -= szi;
		bool th = 1;
		for (int p = 0; p < szj; p++) th &= (a[j].fi[p] == a[j].fi[szj - p - 1]);
		if (th) return 0;
		for (int nxt = 1; nxt <= n; nxt++) res = min(res, a[nxt].se + calc(nxt, a[nxt].fi.size(), j, szj));
	}
	else {
		int li = a[i].fi.size() - szi, lj = 0;
			for (int p = 0; p < szj; p++) if (a[i].fi[li + p] != a[j].fi[szj - p - 1]) return res;
		szi -= szj;
		bool th = 1;
		li = a[i].fi.size() - szi;
		for (int p = 0; p < szi; p++) {
			th &= (a[i].fi[a[i].fi.size() - p - 1] == a[i].fi[li + p]);
		}
		if (th) return 0;
		for (int nxt = 1; nxt <= n; nxt++) res = min(res, a[nxt].se + calc(i, szi, nxt, a[nxt].fi.size()));
	}
	return res;
}

signed main() {
	
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	ll res = LINF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		bool th = 1;
		for (int j = 0; j < a[i].fi.size(); j++) if (a[i].fi[j] != a[i].fi[a[i].fi.size() - 1 - j]) th = 0;
		if (th) res = min(res, a[i].se);
	}
	//for (int i = 1; i <= n; i++) if (a[i].se < LINF) cerr << a[i].fi << " " << a[i].se << '\n';
	memset(dp, 255, sizeof(dp));
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) res = min(res, calc(i, a[i].fi.size(), j, a[j].fi.size()) + a[i].se + a[j].se);
	cout << (res == LINF ? -1 : res);
}