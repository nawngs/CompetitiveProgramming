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

const string NAME = "REP";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e6 + 3;
const ll MOD = 1e9 + 7;
const int base = 1e6;


void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n;

vector < int > res;

pii a[100002];

int it[8000002];

bool check[2000002];

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = 1;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		a[i].fi += base;
		a[i].se += base;
	}
	sort(a + 1, a + n + 1, [](pii &x, pii &y) {
		return x.se < y.se;
	});
	res.clear();
	for (int i = 1; i <= n; i++) {
		int tam = query(1, 1, nmax, a[i].fi, a[i].se);
		if (tam >= 2) continue;
		int j = a[i].se;
		while (1) {
			if (check[j]) {
				j --;
				continue;
			}
			else {
				check[j] = true;
				res.push_back(j);
				update(1, 1, nmax, j);
				tam ++;
				if (tam >= 2) break;
				j --;
			}
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto x : res) cout << x - base << " ";
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
