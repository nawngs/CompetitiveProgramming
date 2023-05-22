#include <bits/stdc++.h>

#define name ""
#define test "test"
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

ll dp[100003][23], n, k, a[100003], cnt[100003], L = 1, R = 0, val = 0; 

void calc(int l, int r) {
	while (L > l) {
		L --;
		val += cnt[a[L]];
		cnt[a[L]] ++;
	}
	while (R < r) {
		R ++;
		val += cnt[a[R]];
		cnt[a[R]] ++;
	}
	while (L < l) {
		cnt[a[L]] --;
		val -= cnt[a[L]];
		L ++;
	}
	while (R > r) {
		cnt[a[R]] --;
		val -= cnt[a[R]];
		R --;
	}
}

void calc(int id, int l, int r, int optl, int optr) {
	if (l > r) return ;
	int mid = (l + r) / 2, opt;
	dp[mid][id] = LINF;
	for (int i = optl; i <= min(optr, mid - 1); i++) {
		calc(i + 1, mid);
		if (dp[mid][id] > dp[i][id - 1] + val) {
			dp[mid][id] = dp[i][id - 1] + val;
			opt = i;
		}
	}
	calc(id, l, mid - 1, optl, opt);
	calc(id, mid + 1, r, opt, optr);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][0] = LINF;
	}
	for (int i = 1; i <= k; i++) 
		calc(i, 1, n, 0, n - 1);
	for (int i = 1; i <= n; i++)
	cout << dp[n][k];
}