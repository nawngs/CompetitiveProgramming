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

const string NAME = "";
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

ll n, m, total, d[23][23], deg[23], dp[(1 << 20)];

vector < int > temp;

bool vs[23];

void dfs(int u) {
	vs[u] = 1;
	for (int v = 1; v <= n; v++) {
		if (vs[v] || d[u][v] == INF) continue;
		dfs(v); 
	}
}

bool getbit(int val, int pos) {
	return (val & (1 << pos));
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		d[u][v] = min(d[u][v], 1ll * c);
		d[v][u] = min(d[v][u], 1ll * c);
		if (u != v) {
			deg[u] ++;
			deg[v] ++;
		}
		else deg[u] += 2;
		total += c;
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (!vs[i] && deg[i] > 0) {
			cout << -1 << '\n';
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) if (deg[i] & 1) temp.push_back(i);
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[j][k]);
	for (int bit = 0; bit < (1 << temp.size()); bit++) {
		if (__builtin_popcountl(bit) % 2 == 1) {
			dp[bit] = INF;
			continue;
		}
		if (__builtin_popcountl(bit) == 0) {
			dp[bit] = 0;
			continue;
		}
		else dp[bit] = INF;
		for (int i = 0; i < temp.size(); i++) {
			if (!getbit(bit, i)) continue;
			for (int j = 0; j < temp.size(); j++) {
				if (j == i || !getbit(bit, j)) continue;
				dp[bit] = min(dp[bit], dp[bit - (1 << i) - (1 << j)] + d[temp[i]][temp[j]]);
			}
		}
	}
	cout << total + dp[(1 << temp.size()) - 1];
}
