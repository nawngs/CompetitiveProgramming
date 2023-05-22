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

int n, it[600003], lazy[600003], Val[600003];

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

int walk(int node, int l, int r) {
	if (it[node] <= 0) return n + 1;
	if (l == r) return r;
	int mid = (l + r) / 2;
	update(node * 2, l, mid);
	update(node * 2 + 1, mid + 1, r);
	if (it[node * 2 + 1] > 0) return walk(node * 2 + 1, mid + 1, r);
	return walk(node * 2, l, mid);
}

int main() {
	fast;
	//fre();
	cin >> n;
	Val[n + 1] = -1;
	for (int i = 1; i <= n; i++) {
		int id, t;
		cin >> id >> t;
		if (t == 0) 
			update(1, 1, n, 1, id, -1);
		else {
			int v; cin >> v;
			Val[id] = v;
			update(1, 1, n, 1, id, 1);
		}
		cout << Val[walk(1, 1, n)] << '\n';
	}
}
