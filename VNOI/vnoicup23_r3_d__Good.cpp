#include <bits/stdc++.h>

#define ll long long
#define int ll
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

struct Node {
	ll Max, Min, Ans;
} it[1800003];

ll n, k, t[300003], a[300003], lazy[1800003];

vector < int > pos[300003];

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node].Max += lazy[node];
		it[node].Min += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

Node merge(const Node &x, const Node &y) {
	Node res;
	res.Max = max(x.Max, y.Max);
	res.Min = min(x.Min, y.Min);
	res.Ans = max(x.Ans, y.Ans);
	res.Ans = max(res.Ans, y.Max - x.Min);
	return res;
}

void update(int node, int l, int r, int u, int v, ll val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		// if (val < 0) cout << val << " " << l << " " << r << " " << it[node].Max << '\n';
		lazy[node] = val;
		update(node, l, r);
		// if (val < 0) cout << val << " " << l << " " << r << " " << it[node].Max << '\n';
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
	//if (val < 0) cout << l << " " << r << " " << it[node].Max << " " << it[node].Min << " " << it[node].Ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x; pos[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, 0, n, i, n, a[i]);
	}
	ll res = 0;
	for (int i = 1; i <= k; i++) {
		for (auto x : pos[i]) update(1, 0, n, x, n, -k * a[x]);
		res = max(res, it[1].Ans);
		for (auto x : pos[i]) update(1, 0, n, x, n, k * a[x]);
	}
	cout << res;
}