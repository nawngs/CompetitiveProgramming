#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "sc";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, f[503][503], g[503][503];

pii a[503][503];

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int x; cin >> x;
			while (x % 2 == 0) {
				a[i][j].fi ++;
				x /= 2;
			}
			while (x % 5 == 0) {
				a[i][j].se ++;
				x /= 5;
			}
			f[i][j] = g[i][j] = INF;
		}
	f[1][1] = a[1][1].fi;
	priority_queue < piii, vector < piii >, greater < piii > >  heap;
	heap.push({f[1][1], {1, 1}});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		int v = u.fi, i = u.se.fi, j = u.se.se;
		if (v != f[i][j]) continue;
		for (int p = 0; p < 4; p++) {
			int newi = i + dx[p];
			int newj = j + dy[p];
			if (newi < 1 || newj < 1 || newi > n || newj > m) continue;
			if (f[newi][newj] > v + a[newi][newj].fi) {
				f[newi][newj] = v + a[newi][newj].fi;
				heap.push({f[newi][newj], {newi, newj}});
			}
		}
	}
	g[1][1] = a[1][1].se;
	heap.push({g[1][1], {1, 1}});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		int v = u.fi, i = u.se.fi, j = u.se.se;
		if (v != g[i][j]) continue;
		for (int p = 0; p < 4; p++) {
			int newi = i + dx[p];
			int newj = j + dy[p];
			if (newi < 1 || newj < 1 || newi > n || newj > m) continue;
			if (g[newi][newj] > v + a[newi][newj].se) {
				g[newi][newj] = v + a[newi][newj].se;
				heap.push({g[newi][newj], {newi, newj}});
			}
		}
	}
	cout << min(f[n][m], g[n][m]) << '\n';
}
