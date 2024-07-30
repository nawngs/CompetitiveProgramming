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

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Device {
	int p, c, l, r;
	Device() {
		p = c = l = r = 0;
	}
} a[NMAX + 3];

int mn[NMAX + 3][NMAX + 3], mx[NMAX + 3][NMAX + 3], dp[NMAX + 3][NMAX + 3];

int n, m, h[NMAX + 3];

int getmn(int i, int j) {
	if (i > j) swap(i, j);
	return mn[i][j];
}

int getmx(int i, int j) {
	if (i > j) swap(i, j);
	return mx[i][j];
}

int calc(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (a[i].l == 1 && a[j].r == n) return dp[i][j] = 0;
	int &res = dp[i][j]; res = INF;
	if (a[j].l < a[i].l) return res = calc(j, j);
	if (a[i].r > a[j].r) return res = calc(i, i);
	for (int k = 1; k <= m; k++) 
	if (a[i].l <= getmn(a[i].p, a[k].p) && getmn(a[i].p, a[k].p) <= a[j].r && a[i].l <= getmx(a[i].p, a[k].p) && getmx(a[i].p, a[k].p) <= a[j].r) {
		if (a[k].l < a[i].l && a[k].r >= a[i].l) res = min(res, calc(k, j) + a[k].c);
		if (a[k].r > a[j].r && a[k].l <= a[j].r) res = min(res, calc(i, k) + a[k].c);
	}
	return res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= m; i++) 
		cin >> a[i].p >> a[i].c >> a[i].l >> a[i].r;
	
	for (int i = 1; i <= n; i++) {
		mn[i][i] = mx[i][i] = h[i];
		for (int j = i + 1; j <= n; j++) {
			mn[i][j] = min(mn[i][j - 1], h[j]);
			mx[i][j] = max(mx[i][j - 1], h[j]);
		}
	}
	memset(dp, 255, sizeof(dp));
	for (int i = 1; i <= m; i++) 
		cout << (calc(i, i) == INF ? -1 : dp[i][i] + a[i].c) << '\n';
}