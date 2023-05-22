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

const string NAME = "invert";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[200003], dem = 1, it[1200003];

void roi_rac() {
	vector < pll > f;
	f.clear();
	for (int i = 1; i <= n; i++) f.push_back({a[i], i});
	sort(f.begin(), f.end());
	for (int i = 0; i < n; i++) {
		dem += (i > 0 && f[i].fi != f[i - 1].fi);
		a[f[i].se] = dem;
	}

}

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	it[node] ++;
	if (l == r) return ;
	update(node * 2, l, (l + r) / 2, pos);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	roi_rac();
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += query(1, 1, dem, a[i] + 1, dem);
		update(1, 1, dem, a[i]);
	}	
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
