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
const ll ESP = 1e-9;
const ll INF = 1e17 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, f[300003], max_path[300003], g[300003], max_path_above[300003], ans;

vector < pii > adj[300003];

void dfs(int u, int e) {
	vector < int > temp;
	temp.clear();
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		dfs(v.fi, u);
		f[u] = max(f[u], f[v.fi] + v.se);
		max_path[u] = max(max_path[u], max_path[v.fi]);
		temp.push_back(f[v.fi] + v.se);
	}
	sort(temp.begin(), temp.end(), greater < int > ());
	int s = 0;
	for (int i = 0; i < min(2ll, (int)temp.size()); i++) s += temp[i];
	max_path[u] = max(max_path[u], s);
}

void dfs2(int u, int e) {
	vector < int > temp, tam;
	temp.clear();
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		g[v.fi] = max(g[v.fi], g[u] + v.se);
		max_path_above[v.fi] = max_path_above[u];
		temp.push_back(f[v.fi] + v.se);
		tam.push_back(max_path[v.fi]);
	}
	sort(temp.begin(), temp.end(), greater < int > ());
	sort(tam.begin(), tam.end(), greater < int > ());
	while (temp.size() < 4) temp.push_back(0);
	while (tam.size() < 4) tam.push_back(0);
	for (auto v : adj[u]) {		
		if (v.fi == e) continue;
		g[v.fi] = max(g[v.fi], (f[v.fi] + v.se == temp[0] ? temp[1] : temp[0]) + v.se);
		int s = 0;
		s += temp[0] + temp[1];
		if (f[v.fi] + v.se == temp[0] || f[v.fi] + v.se == temp[1]) s = s + temp[2] - f[v.fi] - v.se;
		max_path_above[v.fi] = max(max_path_above[v.fi], s);
		max_path_above[v.fi] = max(max_path_above[v.fi], g[u] + ((f[v.fi] + v.se == temp[0] ? temp[1] : temp[0])));
		max_path_above[v.fi] = max(max_path_above[v.fi], (tam[0] == max_path[v.fi] ? tam[1] : tam[0]));
	}
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		ans = min(ans, abs(max_path_above[v.fi] - max_path[v.fi]));
		dfs2(v.fi, u);
	}
}

signed main() {
	fast;
	while (cin >> n && n != 0) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			g[i] = 0;
			max_path_above[i] = 0;
			f[i] = 0;
			max_path[i] = 0;
		}
		for (int i = 2; i <= n; i++) {
			int p, l;
			cin >> p >> l;
			adj[p].push_back({i, l});
			adj[i].push_back({p, l});
		}
		dfs(1, 0);
		ans = INF;
		dfs2(1, 0);
		cout << ans << '\n';
	}
}
