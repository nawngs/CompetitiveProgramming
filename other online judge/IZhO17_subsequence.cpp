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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const int BASE = 10;

int n, a[NMAX + 3], b[NMAX + 3], f[(1 << BASE)][(1 << BASE)][BASE + 2];

pii dp[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	for (int i = 0; i < (1 << BASE); i++)
	for (int j = 0; j < (1 << BASE); j++)
	for (int d = 0; d <= BASE; d++) f[i][j][d] = -1;
	pii res = {0, -1};
	for (int i = 1; i <= n; i++) {
		int left = a[i] & ((1 << BASE) - 1), right = a[i] >> BASE;
		dp[i] = {1, -1};
		for (int prel = 0; prel < (1 << BASE); prel++) {
			int diffl = __builtin_popcount(prel & left);
			if (diffl > b[i]) continue;
			int diffr = b[i] - diffl;
			if (diffr > BASE) continue;
			int trace = f[prel][right][diffr];
			if (trace == -1) continue;
			dp[i] = max(dp[i], mp(dp[trace].fi + 1, trace));
		}
		res = max(res, {dp[i].fi, i});
		for (int prer = 0; prer < (1 << BASE); prer++) {
			int diffr = __builtin_popcount(right & prer);
			int &trace = f[left][prer][diffr];
			if (trace != -1 && dp[trace] > dp[i]) continue;
		 	trace = i;
		}
	}
	cout << res.fi << '\n';
	vector < int > ans;
	while (res.se != -1) {
		ans.pb(res.se);
		res.se = dp[res.se].se;
	}
	reverse(ans.begin(), ans.end());
	for (auto x : ans) cout << x << " ";
}