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
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, h[1000003], par[1000003], total = 0, s[1000003], pre[1000003][2];

bool vs[1000003];

vector < int > adj[1000003], res;

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	par[u] = e;
	s[u] = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (h[v]) {
			if (h[v] < h[u] && ((h[u] - h[v]) % 2 == 0)) {
				s[u] ++;
				s[par[v]] --;
				total ++;
			}
		}
		else {
			dfs(v, u);
			s[u] += s[v];
		}
	}
}

void dfs2(int u) {
	vs[u] = 1;
	pre[u][0] = pre[u][1] = INF;
	for (auto v : adj[u]) {
		if (v == par[u]) continue;
		if (par[v] == u) {
			dfs2(v);
			pre[u][0] = min(pre[u][0], pre[v][0]);
			pre[u][1] = min(pre[u][1], pre[v][1]);
		}
		else {
			if (abs(h[u] - h[v]) & 1) pre[u][0] = min(pre[u][0], h[v]);
			else pre[u][1] = min(pre[u][1], h[v]); 
		}
	}
	if (s[u] == total) {
		res.push_back(u);
		for (auto v : adj[u]) {
			if (v == par[u]) continue;
			if (par[v] == u) {
				if (pre[v][0] < h[u] && pre[v][1] < h[u]) {
					res.pop_back();
					return ;
				}
			}
		}
	}
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) if (!h[i]) dfs(i, 0);
	//for (int i = 1; i <= n; i++) cout << i << " " << s[i] << '\n';
	for (int i = 1; i <= n; i++) if (!vs[i]) dfs2(i);
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (auto x : res) cout << x << " ";
}
