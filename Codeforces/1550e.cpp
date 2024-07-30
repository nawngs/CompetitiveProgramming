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
const ll BASE = 2309;

int n, k, lst[20], nxt[NMAX + 3][20], dp[1 << 17];

string s;

bool check(int x) {
	for (int i = 0; i < k; i++) lst[i] = n + 1;
	for (int i = 1; i <= n + 2; i++)
	for (int j = 0; j < k; j++) nxt[i][j] = n + 2;
	for (int i = n; i >= 1; i--) {
		if (s[i] != '?') lst[s[i] - 'a'] = i;
		int r = n + 1;
		for (int j = 0; j < k; j++) {
			nxt[i][j] = (i + x <= r ? i + x : nxt[i + 1][j]);
			r = min(r, lst[j]);
		}
		r = n + 1;
		for (int j = k - 1; j >= 0; j--) {
			if (i + x > r) nxt[i][j] = nxt[i + 1][j];
			r = min(r, lst[j]);
		}
		// cout << i << '\n';
		// for (int j = 0; j < k; j++) cout << j << " " << nxt[i][j] << '\n';
	}
	for (int i = 0; i < (1 << k); i++) dp[i] = n + 2;
	dp[0] = 1;
	for (int msk = 0; msk < (1 << k); msk++) {
		for (int bit = 0; bit < k; bit++) if (!(msk >> bit & 1))
			dp[msk ^ (1 << bit)] = min(dp[msk ^ (1 << bit)], nxt[dp[msk]][bit]);
	}
	return (dp[(1 << k) - 1] <= n + 1);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> s; s = ' ' + s;
	int l = 1, r = n, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}