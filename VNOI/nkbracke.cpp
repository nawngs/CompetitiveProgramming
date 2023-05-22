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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[100005], s[100005], it[600005], lazy[600005];

string str;

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = s[l];
		return ;
	}
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r, int u, int v, int val) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (r < u || v < l) return ;
	if (u <= l && r <= v) {
		it[node] += val;
		if (l != r) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}


void sol() {
	cin >> n >> m >> str;
	str = ' ' + str;
	for (int i = 1; i <= n; i++) {
		if (str[i] == '(') a[i] = 1;
		else a[i] = -1;
		s[i] = s[i - 1] + a[i];
	}
	build_tree(1, 0, n);
	while (m --) {
		int x;
		cin >> x;
		if (x == 0) {
			int pos, val;
			char c;
			cin >> pos >> c;
			if (c == '(') val = 1;
			else val = -1;
			int gt = val - a[pos];
			a[pos] = val;
			update(1, 0, n, pos, n, gt);
		}
		else {
			int y, z;
			cin >> y >> z;
			int l = query(1, 0, n, y - 1, y - 1);
			int min_val = query(1, 1, n, y, z);
			if (min_val - l < 0) cout << 0;
			else {
				int r = query(1, 0, n, z, z);
				if (r - l == 0) cout << 1;
				else cout << 0;
			}
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}