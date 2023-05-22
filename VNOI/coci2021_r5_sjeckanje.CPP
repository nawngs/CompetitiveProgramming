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

struct Node {
	ll dp[2][2];
} it[1200003];

ll n, m, a[200003];

Node merge (Node x, Node y, int r) {
	Node res;
	res.dp[0][0] = res.dp[1][1] = res.dp[1][0] = res.dp[0][1] = -INF;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int p = 0; p < 2; p++) {
				for (int q = 0; q < 2; q++) {
					if (p == 1 && q == 1 && a[r] * a[r + 1] < 0) continue;
					res.dp[i][j] = max(res.dp[i][j], x.dp[i][p] + y.dp[q][j]);
				}
			}
		}	
	}
	return res;
}

void build_tree(int node, int l, int r) {
	//cout << node << " " << l << " " << r << '\n';
	if (l == r) {
		it[node].dp[0][1] = it[node].dp[1][0] = -INF;
		it[node].dp[1][1] = abs(a[l]);
		it[node].dp[0][0] = 0;
		//cout << l << " " << r << " " << max(it[node].dp[0][0], max(it[node].dp[0][1], max(it[node].dp[1][0], it[node].dp[1][1]))) << '\n';
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = merge(it[node * 2], it[node * 2 + 1], (l + r) / 2);
	//cout << l << " " << r << " " << max(it[node].dp[0][0], max(it[node].dp[0][1], max(it[node].dp[1][0], it[node].dp[1][1]))) << '\n';

}

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].dp[0][1] = it[node].dp[1][0] = -INF;
		it[node].dp[1][1] = abs(a[l]);
		it[node].dp[0][0] = 0;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos);
	it[node] = merge(it[node * 2], it[node * 2 + 1], (l + r) / 2);
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) a[i] = a[i] - a[i + 1];
	n--;
	build_tree(1, 1, n);
	//cout << max(it[1].dp[0][0], max(it[1].dp[0][1], max(it[1].dp[1][0], it[1].dp[1][1]))) << '\n';
	while (m--) {
		ll l, r, x;
		cin >> l >> r >> x;
		if (l != 1) a[l - 1] -= x;
		a[r] += x;
		update(1, 1, n, l - 1);
		update(1, 1, n, r);
		cout << max(it[1].dp[0][0], max(it[1].dp[0][1], max(it[1].dp[1][0], it[1].dp[1][1]))) << '\n';

	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
