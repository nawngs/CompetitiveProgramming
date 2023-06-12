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

const string NAME = "incmat";
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

struct Query {
	int t, l, b, r, w;
} Q[1000003];

int n, m, q, x, y, u, v, c;

vector < vector < int > > a, s, max_above, max_below;

int main() {
	fast;
	//fre();
	cin >> n >> m;
	a.resize(n + 3);
	s.resize(n + 3);
	max_above.resize(n + 3);
	max_below.resize(n + 3);
	for (int i = 1; i <= n; ++i) {
		a[i].resize(m + 3);
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	}
	for (int i = 0; i <= n + 1; ++i) {
		s[i].resize(m + 3);
		max_above[i].resize(m + 3);
		max_below[i].resize(m + 3);
	}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> x >> y >> u >> v >> c;
		s[x][y] += c;
		s[u + 1][v + 1] += c;
		s[x][v + 1] -= c;
		s[u + 1][y] -= c;
		Q[i].t = x; Q[i].l = y; Q[i].b = u; Q[i].r = v; Q[i].w = c;
	}
	int max_v = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			a[i][j] += s[i][j];
			max_v = max(max_v, a[i][j]);
		}
	}
	for (int i = 1; i <= m; ++i) 
		max_above[1][i] = max(max_above[1][i - 1], a[1][i]);
	for (int i = m; i >= 1; --i)
		max_below[n][i] = max(max_below[n][i + 1], a[n][i]);
	
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			max_above[i][j] = max(max_above[i - 1][j], max(max_above[i][j - 1], a[i][j]));
		}
	for (int i = n - 1; i >= 1; --i) 
		for (int j = m; j >= 1; --j) {
			max_below[i][j] = max(max_below[i + 1][j], max(max_below[i][j + 1], a[i][j]));
		}
	int res = max_v;
	for (int i = 1; i <= q; ++i) {
		res = min(res, max(max_v - Q[i].w, max(max_above[Q[i].t - 1][n], max(max(max_above[n][Q[i].l - 1], max_below[1][Q[i].r + 1]), max_below[Q[i].b + 1][1]))));
	}
	cout << res;
}
