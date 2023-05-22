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

struct Update {
	int l, r, a;
} Upd[100003];

int n, m, q, low[100003], high[100003], ans[100003];

ll it[600003], lazy[600003], Val[100003];

vector < int > pos[100003], id[100003];

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

void update(int node, int l, int r, int u, int v, int val) {
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

ll query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x; cin >> x;
		pos[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> Val[i];
		ans[i] = -1;
	}
	cin >> q;
	for (int i = 1; i <= q; i++) 
		cin >> Upd[i].l >> Upd[i].r >> Upd[i].a;
	for (int i = 1; i <= n; i++)
		low[i] = 1, high[i] = q;
	while(1) {
		bool th = false;
		for (int i = 1; i <= n; i++) {
			if (low[i] > high[i]) continue;
			id[(low[i] + high[i]) / 2].push_back(i);
		}
		memset(it, 0, sizeof(it));
		memset(lazy, 0, sizeof(lazy));
		for (int i = 1; i <= q; i++) {
			if (Upd[i].l <= Upd[i].r) update(1, 1, m, Upd[i].l, Upd[i].r, Upd[i].a);
			else {
				update(1, 1, m, 1, Upd[i].r, Upd[i].a);
				update(1, 1, m, Upd[i].l, m, Upd[i].a);
			}
			while (id[i].size()) {
				int x = id[i].back(); id[i].pop_back();
				th = 1;
				ll res = 0;
				for (auto p : pos[x]) 
					res += query(1, 1, m, p, p);
				if (res >= Val[x]) {
					high[x] = i - 1;
					ans[x] = i;
				}
				else low[x] = i + 1;
			}
		}
		if (!th) break;
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == -1) cout << "NOPE" << '\n';
		else cout << ans[i] << '\n';
	}
}
