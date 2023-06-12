#include <bits/stdc++.h>

#define ll long long
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ll LINF = 6e18;

struct Node {
	int x, w;
} a[300003];

int n, q, ql[300003], qr[300003];

ll it[1200003], res[300003];

vector < int > R[300003], Q[300003], S[300003];

void build(int node, int l, int r) {
	it[node] = LINF;
	if (l == r) return ;
	build(lnode); build(rnode);
}

void update(int node, int l, int r, int pos, ll val) {
	if (pos < l || pos > r) return ;
	it[node] = min(it[node], val);
	if (l == r) return ;
	update(lnode, pos, val); update(rnode, pos, val);
}

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return LINF;
	if (u <= l && r <= v) return it[node];
	return min(query(lnode, u, v), query(rnode, u, v));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	vector < int > vals;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].w;
		vals.push_back(a[i].x);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 1; i <= n; i++)
		a[i].x = lower_bound(vals.begin(), vals.end(), a[i].x) - vals.begin() + 1;
	for (int i = 1; i <= q; i++) {
		cin >> ql[i] >> qr[i];
		ql[i] = a[ql[i]].x; qr[i] = a[qr[i]].x;
		Q[qr[i]].push_back(i);
	}
	sort(a + 1, a + n + 1, [&](Node &x, Node &y) {
		return x.x < y.x;
	});
	for (int i = 1; i <= n; i++)
		S[a[i].x].push_back(i);
	stack < int > st;
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && a[st.top()].w > a[i].w) st.pop();
		if (!st.empty()) R[i].push_back(st.top());
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && a[st.top()].w > a[i].w) st.pop();
		if (!st.empty()) R[st.top()].push_back(i);
		st.push(i);
	}
	build(1, 1, n);
	for (int v = 1; v <= n; v++) {
		for (auto id : S[v]) 
		for (auto id2 : R[id]) {
			ll val = 1ll * (a[id].w + a[id2].w) * 1ll * (vals[a[id].x - 1] - vals[a[id2].x - 1]);
			update(1, 1, n, a[id2].x, val);  
		}
		for (auto id : Q[v]) 
			res[id] = query(1, 1, n, ql[id], qr[id]);
	}
	for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}