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

ll n, l1, l2, a[100003], dp[100003], it[600003], trace[100003];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = l;
		return ;
	}
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	if (dp[it[node * 2]] > dp[it[node * 2 + 1]]) it[node] = it[node * 2];
	else it[node] = it[node * 2 + 1];
	return ;
}

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) return ; 
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
	if (dp[it[node * 2]] > dp[it[node * 2 + 1]]) it[node] = it[node * 2];
	else it[node] = it[node * 2 + 1];
	return ;
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return -1;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	int lnode = query(node * 2, l, mid, u, v);
	int rnode = query(node * 2 + 1, mid + 1, r, u, v);
	if (lnode == -1) return rnode;
	if (rnode == -1) return lnode;
	if (dp[lnode] > dp[rnode]) return lnode;
	else return rnode;
}

void sol() {
	cin >> n >> l1 >> l2;
	for (int i = 1; i <= n; i++) cin >> a[i];	
	for (int i = 1; i <= l1; i++) dp[i] = a[i];
	build_tree(1, 1, n);
	for (int i = l1 + 1; i <= n; i++) {
		ll pos = query(1, 1, n, max(1ll, i - l2), i - l1);
		dp[i] = dp[pos] + a[i];
		trace[i] = pos;
		update(1, 1, n, i);
	}
	ll ans = -INF, pos;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
			pos = i;
		} 	
	}
	cout << ans << ' ';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
 