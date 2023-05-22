#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < ll, int >
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

int n, m, zb[500003], z[1500003];

pii za[500003], it[2000003];

vector < int > Pos[500003];

string a, b, s;

pii operator+(const pii &x, const pii &y) {
	return mp(x.fi + y.fi, x.se + y.se);
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = {zb[l], 1};
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid); build(node * 2 + 1, mid + 1, r);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void update(int node, int l, int r, int pos, pii val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val); update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

pii query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return mp(0, 0);
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> a >> b >> s;
	string str = " " + s + "#" + a;
	int l, r; l = r = 0;
	z[1] = 0;
	for (int i = 2; i < sz(str); i++) {
		int &x = z[i];
		if (i <= r) x = min(r - i + 1, z[i - l + 1]);
		while (i + x < sz(str) && str[x + 1] == str[i + x]) {
			x ++;
			l = i;
			r = i + x - 1;
		}
		if (i > sz(s) + 1) za[i - sz(s) - 1].fi = x; 
	}
	for (int i = 1; i <= n; i++) {
		if (za[i].fi == m) za[i].fi --;
		za[i].fi = m - za[i].fi;
		za[i].se = i;
	}
	reverse(s.begin(), s.end()); reverse(b.begin(), b.end());
	str = " " + s + "#" + b;
	l = r = 0; memset(z, 0, sizeof(z));
	z[1] = 0;
	for (int i = 2; i < sz(str); i++) {
		int &x = z[i];
		if (i <= r) x = min(r - i + 1, z[i - l + 1]);
		while (i + x < sz(str) && str[x + 1] == str[i + x]) {
			x ++;
			l = i;
			r = i + x - 1;
		}
		if (i > sz(s) + 1) 
			zb[n - (i - sz(s) - 1) + 1] = x; 
	}
	for (int i = 1; i <= n; i++) {
		if (zb[i] == m) zb[i] --;
		Pos[zb[i]].push_back(i);
	}
	build(1, 1, n);
	sort(za + 1, za + n + 1);
	for (int i = 0; i < za[1].fi; i++) {
		while (!Pos[i].empty()) {
			update(1, 1, n, Pos[i].back(), mp(0, 0));
			Pos[i].pop_back();
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		// cout << za[i].fi << '\n';
		// for (int j = 1; j <= n; j++) cout << query(1, 1, n, j, j).fi << " " << query(1, 1, n, j, j).se << ' ';
		// cout << '\n' << "//##############################################################################" << '\n';
		pii temp = query(1, 1, n, za[i].se, min(n, za[i].se + m - 2));
		res += temp.se + temp.fi - za[i].fi * temp.se;
		if (za[i + 1].fi != za[i].fi) {
			for (int j = za[i].fi; j <= za[i + 1].fi - 1; j++) {
				while (!Pos[j].empty()) {
					update(1, 1, n, Pos[j].back(), mp(0, 0));
					Pos[j].pop_back();
				}
			}
		}
	}
	cout << res;
}