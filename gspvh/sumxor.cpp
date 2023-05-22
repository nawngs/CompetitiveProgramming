//xor is ez for x0rzzz
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

const string NAME = "sumxor";
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

struct Query {
	int l, r, id;
} Q[1000003];

int n, a[1000003], res[1000003], s[1000003];

struct Segment_Tree {
	int it[4000003];
	void build(int node, int l, int r) {
		if (l == r) {
			it[node] = a[l];
			return ;
		}
		build((node << 1), l, (l + r) >> 1);
		build((node << 1) + 1, ((l + r) >> 1) + 1, r);
		it[node] = (it[(node << 1)] ^ it[(node << 1) + 1]);
	}
	void update(int node, int l, int r, int pos, int val) {
		if (pos < l || r < pos) return ;
		if (l == r) {
			it[node] = val;
			return ;
		}
		int mid = (l + r) >> 1;
		update((node << 1), l, mid, pos, val);
		update((node << 1) + 1, mid + 1, r, pos, val);
		it[node] = (it[(node << 1)] ^ it[(node << 1) + 1]);
	}
	int query(int node, int l, int r, int u, int v) {
		if (v < l || r < u) return 0;
		if (u <= l && r <= v) return it[node];
		int mid = (l + r) >> 1;
		return (query((node << 1), l, mid, u, v) ^ query((node << 1) + 1, mid + 1, r, u, v));
	}
} Current_Tree;

map < int, int > pre;

int main() {
	fast;
	//fre();
	int O; cin >> O;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = (s[i - 1] ^ a[i]);
	}
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> Q[i].l >> Q[i].r;
		Q[i].id = i;
	}
	sort(Q + 1, Q + q + 1, [&](Query &x, Query &y) {
		return x.r < y.r;
	});
	Q[0].r = 0;
	for (int i = 1; i <= q; i++) {
		for (int j = Q[i - 1].r + 1; j <= Q[i].r; j++) {
			if (pre.find(a[j]) != pre.end()) 
				Current_Tree.update(1, 1, n, pre[a[j]], 0);
			pre[a[j]] = j;
			Current_Tree.update(1, 1, n, j, a[j]);
		}
		int temp = s[Q[i].r] ^ s[Q[i].l - 1];
		res[Q[i].id] = (temp ^ Current_Tree.query(1, 1, n, Q[i].l, Q[i].r));
	}
	for (int i = 1; i <= q; i++)
		cout << res[i] << " ";
}
