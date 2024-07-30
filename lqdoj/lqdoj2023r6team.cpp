#include <bits/stdc++.h>

#define name "team"
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
const ll MOD = 918052004;
const ll BASE = 2309;

int n, m, l, r, a[NMAX + 3], pre[NMAX + 3], ql[NMAX + 3], qr[NMAX + 3];

ll dp[NMAX + 3], s[NMAX + 3];

int get(int l, int r) {
	// cout << l << " " << r << '\n';
	if (l == 0) return s[r];
	else return (s[r] - s[l - 1] + MOD) % MOD;
}

void sol() {
	cin >> n >> m >> l >> r;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 0;
	}/*
	if (n <= 15) {
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) pre[j] = -1;
			int dem = 0;
			for (int j = i; j >= 1; j--) {
				if (pre[a[j]] == -1) dem ++;
				pre[a[j]] = j;
				if (l <= dem && dem <= r) dp[i] += dp[j - 1];
			}
		}
		cout << dp[n] << '\n';
	}*/
	for (int j = 1; j <= m; j++) pre[j] = -1;
	int cur = 1, dem = 0;
	for (int i = 1; i <= n; i++) {
		if (pre[a[i]] == -1) dem ++;
		pre[a[i]] = i;
		while (dem > r) {
			if (pre[a[cur]] == cur) dem --, pre[a[cur]] = -1;
			cur ++;
		}
		ql[i] = cur;
	}
	for (int j = 1; j <= m; j++) pre[j] = -1;
	cur = 1, dem = 0;
	for (int i = 1; i <= n; i++) {
		if (pre[a[i]] == -1) dem ++;
		pre[a[i]] = i;
		while (dem > l) {
			if (pre[a[cur]] == cur) dem --, pre[a[cur]] = -1;
			cur ++;
		}
		while (dem == l) {
			if (pre[a[cur]] != cur) cur ++;
			else break;
		}
		if (dem >= l) qr[i] = cur;
		else qr[i] = 0;
	}
	s[0] = 1;
	for (int i = 1; i <= n; i++) {
		// cout << i << " " << ql[i] << " " << qr[i] << ' ';
		if (qr[i] < ql[i]) dp[i] = 0;
		else dp[i] = get(ql[i] - 1, qr[i] - 1);
		s[i] = (s[i - 1] + dp[i]) % MOD;
		// cout << dp[i] << '\n';
	}
	cout << dp[n] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}