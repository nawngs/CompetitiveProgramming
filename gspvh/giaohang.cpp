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

const string NAME = "giaohang";
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

int n, m, q;

ll d[503][503], pre[503][503];

bool minimize(ll &x, ll y) {
	if (x > y) {
		x = y;
		return 1;
	}
	return 0;
}

vector < int > store;

int main() {
	fast;
	//fre();
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) d[i][j] = pre[i][j] = LINF;
	for (int i = 1; i <= m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		if (minimize(d[u][v], c)) pre[u][v] = c;
		if (minimize(d[v][u], c)) pre[v][u] = c;
	}
	for (int i = 1; i <= n; i++) 
		d[i][i] = 0, pre[i][i] = 0;
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (k == j) continue;
				if (minimize(d[i][j], d[i][k] + d[k][j])) 
					pre[i][j] = pre[k][j];
				else if (d[i][j] == d[i][k] + d[k][j]) minimize(pre[i][j], pre[k][j]);
			}
	while (q--) {
		int k; cin >> k;
		store.resize(k);
		for (auto &x : store) cin >> x;
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			ll cur = LINF, val = 0;
			for (auto x : store) {
				if (minimize(cur, d[x][i])) 
					val = pre[x][i];
				if (cur == d[x][i]) val = min(val, pre[x][i]);
			}
			res += val;
		}
		cout << res << '\n';
	}
	
}