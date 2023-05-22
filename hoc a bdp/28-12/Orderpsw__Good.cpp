#include <bits/stdc++.h>

#define name ""
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
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, k, frac[100003], a[100003], it[400003];

void build(int node, int l, int r) {
	it[node] = (r - l + 1);
	if (l == r) return ;
	int mid = (l + r) / 2;
	build(node * 2, l, mid); build(node * 2 + 1, mid + 1, r);
}	

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || r < pos) return ;
	it[node] += val;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val); update(node * 2 + 1, mid + 1, r, pos, val);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	frac[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		frac[i] = (frac[i - 1] * i) % MOD;
	}
	while (k--) {
		int l, r; cin >> l >> r;
		swap(a[l], a[r]);
		build(1, 1, n);
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			res = (res + 1ll * query(1, 1, n, 1, a[i] - 1) * frac[n - i]) % MOD;
			update(1, 1, n, a[i], -1);
		}
		cout << res + 1 << '\n';
		swap(a[l], a[r]);
	}
}