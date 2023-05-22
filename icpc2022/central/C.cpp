#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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

ll n, k, it[12][400003];

pll a[100003];

void update(int id, int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[id][node] += 1ll * val;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(id, node * 2, l, mid, pos, val);
	update(id, node * 2 + 1, mid + 1, r, pos, val); 
}

ll query(int id, int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0; 
	if (u <= l && r <= v) return it[id][node];
	int mid = (l + r) / 2;
	return query(id, node * 2, l, mid, u, v) + query(id, node * 2 + 1, mid + 1, r, u, v);
}

main() {
	fast;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	update(1, 1, 1, n, a[1].se, 1);
	//cout << 123 << '\n';
	for (int i = 2; i <= n; i++) {
		for (int j = k; j >= 2; j--) 
			update(j, 1, 1, n, a[i].se, query(j - 1, 1, 1, n, 1, a[i].se - 1));
		
		update(1, 1, 1, n, a[i].se, 1);
	}
	cout << it[k][1] << '\n';
}
