#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, r[7], c[7], cntr[13], cntc[13];

pii a[60];

map < ll, int > dp;

pii get(int x) {
	pii res;
	res.se = x % n;
	if (res.se == 0) res.se = n;
	res.fi = x / n + (res.se != n);
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
	for (int i = 1; i <= 5; i++) cin >> r[i];
	for (int i = 1; i <= 5; i++) cin >> c[i];
	for (int i = 0; i < 5; i++) {
		int x; cin >> x;
		a[i] = get(x);
	}
	dp[31] = 0;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		a[i + 5] = get(x);
	}
	int res = 0;
	for (auto x : dp) {
		int t = 63 - __builtin_clzll(x.fi);
		if (t == m + 4) {
			res = max(res, x.se);
			continue;
		}
		t ++;
		for (int i = 1; i <= n; i++) cntr[i] = cntc[i] = 0;
		for (int i = 0; i < t; i++) {
			if (!(x.fi >> i & 1)) continue;
			cntr[a[i].fi] ++;
			cntc[a[i].se] ++;
		}
		for (int i = 0; i < t; i++) {
			if (!(x.fi >> i & 1)) continue;
			cntr[a[i].fi] --; cntc[a[i].se] --;
			cntr[a[t].fi] ++; cntc[a[t].se] ++;
			int resr = 0, resc = 0;
			for (int j = 1; j <= n; j++) {
				resr = max(resr, cntr[j]);
				resc = max(resc, cntc[j]);
			}
			ll nmsk = x.fi ^ (1ll << i); nmsk ^= (1ll << t);
			dp[nmsk] = max(dp[nmsk], x.se + r[resr] + c[resc]);
			cntr[a[i].fi] ++; cntc[a[i].se] ++;
			cntr[a[t].fi] --; cntc[a[t].se] --;
		}
	}
	cout << res;
}
