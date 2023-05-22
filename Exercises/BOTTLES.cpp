#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "BOTTLES";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, a[400003], dp[400003], trace[400003], it[2400003];

bool check[400003];

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = pos;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos);
	it[node] = (dp[it[node * 2]] < dp[it[node * 2 + 1]] ? it[node * 2] : it[node * 2 + 1]);
} 

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	ll lnode = query(node * 2, l, (l + r) / 2, u, v);
	ll rnode = query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
	return (dp[lnode] < dp[rnode] ? lnode : rnode);
}

void sol() {
	cin >> n >> k;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	a[++ n] = 0;
	dp[0] = INF;
	for (int i = 1; i <= k; i++) {
		dp[i] = a[i];
		trace[i] = 0;
		update(1, 1, n, i);
	}
	for (int i = k + 1; i <= n; i++) {
		int tam = query(1, 1, n, i - k, i);
		dp[i] = dp[query(1, 1, n, i - k, i)] + a[i];
		trace[i] = tam;
		update(1, 1, n, i);
	}
	int pos = n;
	int cnt = 0;
	while (pos != 0) {
		cnt ++;
		pos = trace[pos];
		check[pos] = true;
	} 
	cout << n - cnt << " " << sum - dp[n] << '\n';
	for (int i = 1; i < n; i++) if (!check[i]) cout << i << ' ';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
