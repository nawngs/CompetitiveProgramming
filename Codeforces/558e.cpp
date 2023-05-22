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

int n, q, it[29][800003], lazy[29][800003], cnt[29];

string s;

void build(int node, int l, int r) {
	if (l == r) {
		it[s[l] - 'a'][node] = 1;
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	for (int i = 0; i <= 'z' - 'a'; i++) it[i][node] = it[i][node * 2] + it[i][node * 2 + 1];
} 

void update_node(int node, int l, int r, int id) {
	if (lazy[id][node] != -1) {
		it[id][node] = lazy[id][node] * (r - l + 1);
		if (l != r) 
			lazy[id][node * 2] = lazy[id][node * 2 + 1] = lazy[id][node];
		lazy[id][node] = -1;
	}
}

int query(int node, int l, int r, int u, int v, int id) {
	update_node(node, l, r, id);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[id][node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v, id) + query(node * 2 + 1, mid + 1, r, u, v, id);
}

void update(int node, int l, int r, int u, int v, int val, int id) {
	update_node(node, l, r, id);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[id][node] = val;
		update_node(node, l, r, id);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val, id);
	update(node * 2 + 1, mid + 1, r, u, v, val, id);
	it[id][node] = it[id][node * 2] + it[id][node * 2 + 1];
}

void get_ans(int node, int l, int r, int id) {
	update_node(node, l, r, id);
	if (!it[id][node]) return ;
	if (l == r) {
		s[l] = (char) ('a' + id);
		return ;
	}
	int mid = (l + r) / 2;
	get_ans(node * 2, l, mid, id);
	get_ans(node * 2 + 1, mid + 1, r, id);
}

int main() {
	fast;
	cin >> n >> q >> s;
	s = ' ' + s;
	build(1, 1, n);
	memset(lazy, 255, sizeof(lazy));
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		for (int i = 0; i <= 'z' - 'a'; i++) cnt[i] = query(1, 1, n, l, r, i);
		int cur = (k == 0 ? r : l);
		for (int i = 0; i <= 'z' - 'a'; i++) {
			if (!cnt[i]) continue;
			update(1, 1, n, l, r, 0, i);
			if (k) {
				update(1, 1, n, cur, cur + cnt[i] - 1, 1, i);
				cur += cnt[i];
			}
			else {
				update(1, 1, n, cur - cnt[i] + 1, cur, 1, i);
				cur -= cnt[i];
			}
		}
	}
	for (int i = 0; i <= 'z' - 'a'; i++)
		get_ans(1, 1, n, i);
	for (auto x : s) if (x != ' ') cout << x;
}
