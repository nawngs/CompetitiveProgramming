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
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[1003], p[1003], dp[1003][1003], it[6003];

void update(ll node, ll l, ll r, ll pos, ll val) {
	if (pos < l || pos > r) return ;
	it[node] += val;
	if (l == r) return ;
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(node * 2, l, (l + r) / 2, u, v) + query(node * 2 + 1, (l + r) / 2 + 1, r, u, v); 
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dp[i][j] = INF;
		dp[i][i] = p[i];			
	}
	for (int k = 1; k < n; k++) {
		for (int i = 1; i <= 6 * n; i++) it[i] = 0;
		for (int i = 1; i < k; i++) update(1, 1, n, p[i], 1);
		for (int i = 1; i <= n - k + 1; i++) {
			ll j = i + k - 1;
			update(1, 1, n, p[i - 1], -1);
			update(1, 1, n, p[j], 1);
			if (i > 1) {
				ll tam = query(1, 1, n, 1, p[i - 1] - 1);
				tam = p[i - 1] - tam;
				dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + tam * (k + 1));
			}
			if (j < n) {
				ll tam = query(1, 1, n, 1, p[j + 1] - 1);
				tam = p[j + 1] - tam;
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + tam * (k + 1));
			}
		}
	}
	cout << dp[1][n] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
