#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 2e4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, b[N + 3], par[N + 3], cnt[N + 3];

ll total = 0;

pii ed[N + 3];

bool del[N + 3];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return ;
	par[v] = u; total += 1ll * cnt[u] * cnt[v]; cnt[u] += cnt[v];
}

void sol() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> ed[i].fi >> ed[i].se;
		del[i] = 0;
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		char c; cin >> c;
		if (c == 'R') {
			cin >> b[i];
			del[b[i]] = 1;
		}
		else b[i] = -1;
	}
	total = 0;
	for (int i = 1; i <= n; i++) par[i] = i, cnt[i] = 1;
	for (int i = 1; i < n; i++) if (!del[i]) merge(ed[i].fi, ed[i].se);
	vector < ll > res;
	for (int i = q; i >= 1; i--) {
		if (b[i] == -1) res.pb(1ll * n * (n - 1) / 2 - total);
		else merge(ed[b[i]].fi, ed[b[i]].se);
	}
	reverse(res.begin(), res.end());
	for (auto x : res) cout << x << '\n';
	cout << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}