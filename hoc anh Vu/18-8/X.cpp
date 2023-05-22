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

ll n, k, a[500003], b[500003], dp[500003], it[2][4000003], lazy[2][4000003];

void update_node(int id, int node, int l, int r) {
	if (lazy[id][node] != 0) {
		it[id][node] += lazy[id][node];
		if (l != r) {
			lazy[id][node * 2] += lazy[id][node];
			lazy[id][node * 2 + 1] += lazy[id][node];
		}
		lazy[id][node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, int id, int val) {
	update_node(id, node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[id][node] = val;
		update_node(id, node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, id, val);
	update(node * 2 + 1, mid + 1, r, u, v, id, val);
	it[id][node] = min(it[id][node * 2], it[id][node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v, int id) {
	update_node(id, node, l, r);
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[id][node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v, id), query(node * 2 + 1, mid + 1, r, u, v, id));
}

int main() {
	fast;
	cin >> n >> k;
	a[0] = b[0] = -1;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'B') a[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'B') b[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] != b[i - 1]) {
			int j = i;
			while (j < n && b[j + 1] == b[i]) j ++;
			update(1, 0, n, 0, j - 1, b[i], 1);
			//if (b[i] == 0) cout << 0 << " " << j - 1 << " " << 1 << '\n';
		}
		if (b[i] != a[i]) {
			int j = max(0ll, i - k);
			//if (i == 4) cout << query(1, 0, n, j, i - 1, 0) << '\n';
			dp[i] = min(query(1, 0, n, j, i - 1, 0), query(1, 0, n, j, i - 1, 1)) + 1;
		}
		else dp[i] = dp[i - 1];
		//cout <<i << " " << i << " " << dp[i] << '\n';
		update(1, 0, n, i, i, 0, dp[i]);
		update(1, 0, n, i, i, 1, dp[i]);
	}
	cout << dp[n] << '\n';
}
