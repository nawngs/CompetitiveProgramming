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

const string NAME = "pair";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, d, a[2002], dp[2003][2002][2];

map < int, vector < int > > f[2];

map < int, vector < int > > cnt;

int bs(int val, int x) {
	int l = 0, r = cnt[val].size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (cnt[val][mid] < x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int query(int node, int l, int r, int u, int v, int s, int lev) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return f[lev][s][node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v, s, lev), query(node * 2 + 1, mid + 1, r, u, v, s, lev));
}

void update(int node, int l, int r, int pos, int val, int s, int lev) {
	if (pos < l || pos > r) return;
	if (l == r) {
		f[lev][s][node] = max(f[lev][s][node], val);
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val, s, lev);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val, s, lev);
	f[lev][s][node] = max(f[lev][s][node * 2], f[lev][s][node * 2 + 1]);
}

void solve0() {
	for (int i = 1; i <= n; ++i) 
		for (int j = i + 1; j <= n; ++j) dp[i][j][0] = 1;
	int ans = 1;
	for (int i = n - 1; i >= 1; --i) {
		for (int j = n; j > i; --j) {
			int s = a[i] + a[j];
			int tam = bs(s, j);
			dp[i][j][0] = max(dp[i][j][0], query(1, 0, cnt[s].size() - 1, 0, tam, s, 0) + 1);
			update(1, 0, cnt[s].size() - 1, tam + 1, dp[i][j][0], s, 0);
			ans = max(ans, dp[i][j][0]);
		}
	}
	cout << ans;
}

void solve1() {
	for (int i = 1; i <= n; ++i) 
		for (int j = i + 1; j <= n; ++j) {
			dp[i][j][0] = 1;
			dp[i][j][1] = 1;
		}
	int ans = 1;
	for (int i = n - 1; i >= 1; --i) {
		for (int j = n; j > i; --j) {
			int s = a[i] + a[j];
			int tam = bs(s, j);
			int tam2;
			dp[i][j][0] = max(dp[i][j][0], query(1, 0, cnt[s].size() - 1, 0, tam, s, 0) + 1);
			dp[i][j][1] = max(dp[i][j][1], query(1, 0, cnt[s].size() - 1, 0, tam, s, 1) + 1);
			tam2 = bs(s - 1, j);
			if (tam2 != -1) dp[i][j][0] = max(dp[i][j][0], query(1, 0, cnt[s - 1].size() - 1, 0, tam2, s - 1, 1) + 1);
			tam2 = bs(s + 1, j);
			if (tam2 != -1) dp[i][j][1] = max(dp[i][j][1], query(1, 0, cnt[s + 1].size() - 1, 0, tam2, s + 1, 0) + 1);
			update(1, 0, cnt[s].size() - 1, tam + 1, dp[i][j][0], s, 0);
			update(1, 0, cnt[s].size() - 1, tam + 1, dp[i][j][1], s, 1);
			ans = max(ans, max(dp[i][j][0], dp[i][j][1]));
		}
	}
	cout << ans;
}

void sol() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	a[0] = -1;
	sort(a + 1, a + n + 1);
	// for (int i = 1; i <= n; ++i) cout << a[i] << " ";
	// cout << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (a[j] != a[j - 1]) cnt[a[j] + a[i]].push_back(i);
		}
	}
	for (auto x : cnt) {
		f[0][x.fi].resize(6 * x.se.size());
		f[1][x.fi].resize(6 * x.se.size());
	}
	if (d == 0) solve0();
	else solve1();
	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
