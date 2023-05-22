#include <bits/stdc++.h>

#define name "test"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 2e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, a[200003], it[33][800003];

ll s[33][200003];

void build(int lv, int node, int l, int r) {
	it[lv][node] = INF;
	if (l == r) return ;
	int mid = (l + r) / 2;
	build(lv, node * 2, l, mid), build(lv, node * 2 + 1, mid + 1, r);
}

void update(int lv, int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[lv][node] = min(it[lv][node], val);
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(lv, node * 2, l, mid, pos, val), update(lv, node * 2 + 1, mid + 1, r, pos, val);
}

ll query(int lv, int node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[lv][node];
	int mid = (l + r) / 2;
	return min(query(lv, node * 2, l, mid, u, v), query(lv, node * 2 + 1, mid + 1, r, u, v));
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 0; i < 30; i++) build(i, 1, 1, n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int k = log2(a[i]);
		s[k][i] = 1ll * a[i];
		update(k, 1, 1, n, i, a[i]);
	}
	for (int i = 0; i < 30; i++)
		for (int j = 1; j <= n; j++) s[i][j] += 1ll * s[i][j - 1];
	while (q--) {
		int l, r; cin >> l >> r;
		ll cur = 0;
		for (int i = 0; i < 30; i++) {
			if (cur + 1 < (1ll << (i + 1)) && query(i, 1, 1, n, l, r) > cur + 1) break;
			cur += s[i][r] - s[i][l - 1];
		}
		cout << cur + 1 << '\n';
	}
}