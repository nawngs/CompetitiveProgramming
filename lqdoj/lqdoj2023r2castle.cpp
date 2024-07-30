#include <bits/stdc++.h>

#define name "castle"
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

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, a[NMAX + 3][NMAX + 3], cnt[NMAX + 3][NMAX + 3], up[NMAX + 3][NMAX + 3], down[NMAX + 3][NMAX + 3];


int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> a[i][j];

	for (int i = 1; i <= n; i++) a[i][m + 1] = a[i][0] = INF;
	for (int i = 1; i <= m; i++) a[n + 1][i] = a[0][i] = INF;

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j --) {
			if (a[i][j] == a[i][j + 1]) cnt[i][j] = cnt[i][j + 1] + 1;
			else cnt[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int k = i - 1;
			while (a[i][j] == a[k][j] && cnt[i][j] <= cnt[k][j]) k = up[k][j];
			up[i][j] = k;
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			int k = i + 1;
			while (a[i][j] == a[k][j] && cnt[i][j] < cnt[k][j]) k = down[k][j];
			down[i][j] = k;
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
		res += 1ll * cnt[i][j] * 1ll * (i - up[i][j]) * (down[i][j] - i);
	cout << res;

}