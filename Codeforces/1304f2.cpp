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

const string NAME = "";
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

ll n, m, k, it[160003], lazy[160003], s[53][20003], dp[53][20003], a[53][20003];

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, ll val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

int main() {
	fast;
	//fre();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			s[i][j] = s[i][j - 1] + a[i][j];
		}
	for (int i = 1; i <= m - k + 1; i++) 
		dp[1][i] = s[1][i + k - 1] - s[1][i - 1] + s[2][i + k - 1] - s[2][i - 1];
	ll res = -INF;
	for (int i = 2; i <= n; i++) {
		memset(it, 0, sizeof(it));
		memset(lazy, 0, sizeof(lazy));
		for (int j = 1; j <= m - k + 1; j++)
			update(1, 1, m, j, j, dp[i - 1][j]);
		for (int j = 1; j <= k; j++) 
			update(1, 1, m, 1, j, -a[i][j]);
		for (int j = 1; j <= m - k + 1; j++) {
			dp[i][j] = it[1] + s[i][j + k - 1] - s[i][j - 1] + s[i + 1][j + k - 1] - s[i + 1][j - 1];
			update(1, 1, m, max(1ll, j - k + 1), j, a[i][j]);
			update(1, 1, m, j + 1, j + k, -a[i][j + k]);
		}
	}
	for (int i = 1; i <= m - k + 1; i++)
		res = max(res, dp[n][i]);
	cout << res;
}
