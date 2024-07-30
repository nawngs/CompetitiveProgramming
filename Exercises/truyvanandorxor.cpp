#include <bits/stdc++.h>

#define ll long long
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const int LG = 16;
const int NMAX = 1E5;

struct Node {
	int dem[LG + 3], f[LG + 3], sze = 0;
	ll total[LG + 3], total2[LG + 3];
	Node() {
		for (int i = 0; i <= LG; i++) {
			dem[i] = 0;
			f[i] = -1;
			total[i] = 0;
		}
		sze = 0;
	}
	void calc() {
		for (int i = 0; i <= LG; i++) if (f[i] != -1 && f[i] < 2) {
			if (f[i] == 0) {
				total[i] = (1ll << i) * dem[i];
				total2[i] = (1ll << i) * (sze - dem[i]);
			}
			else {
				total[i] = (1ll << i) * (sze - dem[i]);
				total2[i] = (1ll << i) * dem[i];
			}
		}
	}
	void update(int i, int val) {
		if (val == 2) {
			swap(total[i], total2[i]);
			if (f[i] != -1 && f[i] < 2) f[i] ^= 1;
			return ;
		}
		f[i] = val;
		if (f[i] == 0) {
				total[i] = (1ll << i) * dem[i];
				total2[i] = (1ll << i) * (sze - dem[i]);
			}
		else {
			total[i] = (1ll << i) * (sze - dem[i]);
			total2[i] = (1ll << i) * dem[i];
		}
	}
} it[4 * NMAX];

ll lazy[4 * NMAX][LG + 3], n, q, a[NMAX + 3];

Node merge(const Node &x, const Node &y) {
	Node res;
	res.sze = x.sze + y.sze;
	for (int i = 0; i <= LG; i++) {
		res.dem[i] = x.dem[i] + y.dem[i];
		res.f[i] = ((x.f[i] == y.f[i] || x.f[i] == -1 || y.f[i] == -1) ? x.f[i] : 2);
	 	res.total[i] = x.total[i] + y.total[i];
	 	res.total2[i] = x.total2[i] + y.total2[i];
	}
	return res;
}

void build(int node, int l, int r) {
	for (int i = 0; i <= LG; i++) lazy[node][i] = -1;
	if (l == r) {
		it[node].sze = 1;
		for (int i = 0; i <= LG; i++) {
			it[node].dem[i] = ((1ll * l) >> i & 1);
			it[node].f[i] = (a[l] >> i & 1);
		}
		it[node].calc();
		int ans = 0;
		for (int i = 0; i <= LG; i++) ans += it[node].total[i];
		return ;
	}
	build(lnode); build(rnode);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

void modify(int node, int i, int val) {
	it[node].update(i, val);
	if (val <= 1) {
		lazy[node][i] = val;
		return ;
	}
	if (lazy[node][i] == -1) {
		lazy[node][i] = 2;
		return ;
	}
	if (lazy[node][i] == 0) {
		lazy[node][i] = 1;
		return ;
	}
	if (lazy[node][i] == 1) {
		lazy[node][i] = 0;
		return ;
	}
	if (lazy[node][i] == 2) {
		lazy[node][i] = -1;
		return ;
	}
	
}

void push(int node, int bit) {
	if (lazy[node][bit] != -1) {
		modify(node * 2, bit, lazy[node][bit]);
		modify(node * 2 + 1, bit, lazy[node][bit]);
		lazy[node][bit] = -1;
	}
}

void update(int node, int l, int r, int u, int v, int val, int bit) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		modify(node, bit, val);
		return ;
	}
	push(node, bit);
	update(lnode, u, v, val, bit);
	update(rnode, u, v, val, bit);
	it[node].dem[bit] = it[node * 2].dem[bit] + it[node * 2 + 1].dem[bit];
	it[node].f[bit] = ((it[node * 2].f[bit] == it[node * 2 + 1].f[bit] || it[node * 2].f[bit] == -1 || it[node * 2 + 1].f[bit] == -1) ? it[node * 2].f[bit] : 2);
	it[node].total[bit] = it[node * 2].total[bit] + it[node * 2 + 1].total[bit];
	it[node].total2[bit] = it[node * 2].total2[bit] + it[node * 2 + 1].total2[bit];
}

Node query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) {
		Node res;
		return res;
	}
	if (u <= l && r <= v) return it[node];
	for (int i = 0; i <= LG; i++) push(node, i);
	Node vall = query(lnode, u, v), valr = query(rnode, u, v);
	// if (l == 1 && r == 4) {
		// cout << 1 << " " << 2 << '\n';
		// for (int i = 0; i <= LG; i++) cout << vall.total[i] << " ";
		// cout << '\n';
		// cout << 3 << " " << 3 << '\n'; 
		// for (int i = 0; i <= LG; i++) cout << valr.total[i] << " ";
		// cout << '\n';
 	// }
	return merge(vall, valr);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	while (q--) {
		int type, l, r; cin >> type >> l >> r;
		if (type == 1) {
			Node res = query(1, 1, n, l, r);
			ll ans = 0;
			for (int i = 0; i <= LG; i++) ans += res.total[i];
			cout << ans << '\n';
		}
		if (type == 2) {
			ll x; cin >> x;
			for (int i = 0; i <= LG; i++) update(1, 1, n, l, r, (x >> i & 1), i);
		}
		if (type == 3) {
			ll x; cin >> x;
			char c; cin >> c;
			if (c == '&')
				for (int i = 0; i <= LG; i++) 
					if (!(x >> i & 1)) update(1, 1, n, l, r, 0, i);
			if (c == '|') 
				for (int i = 0; i <= LG; i++)
					if (x >> i & 1) update(1, 1, n, l, r, 1, i);
			if (c == '^')
				for (int i = 0; i <= LG; i++)
					if (x >> i & 1) update(1, 1, n, l, r, 2, i);
		}
	}
}