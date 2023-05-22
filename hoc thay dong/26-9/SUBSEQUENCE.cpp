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

const string NAME = "SUBSEQUENCE";
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

int n, a[1000003], pre[1000003], t, it[4000003];

int add(int x, int y) {
	int res = x + y;
	if (res >= MOD) res -= MOD;
	if (res < 0) res += MOD;
	return res;
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = add(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return add(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main() {
	fast;
	fre();
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	update(1, 0, n, 0, 1);
	for (int i = 1; i <= n; i++) {
		if (t == 1) {
			int val = query(1, 0, n, 0, i);
			if (pre[a[i]] != 0) update(1, 0, n, pre[a[i]], 0);
			update(1, 0, n, i, val);
		}
		else {
			int val = query(1, 0, n, pre[a[i]], i - 1);
			if (pre[a[i]] != 0) update(1, 0, n, pre[a[i]], 0);
			update(1, 0, n, i, val);
		}
		pre[a[i]] = i;
	}
	cout << it[1] - 1;
}
