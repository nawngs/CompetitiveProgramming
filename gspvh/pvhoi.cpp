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
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, low[300003], num[300003], timeDFS = 0, cnt[300003], scc = 0, num_scc[300003], num_child[300003];

ll res[300003];

pii edges[300003];

bool used[300003], bridge[300003], joint[300003], vs[300003];

vector < int > adj[300003], adj2[300003];

void dfs(int u, int e) {
	cnt[scc] ++;
	num_scc[u] = scc;
	num[u] = low[u] = ++ timeDFS;
	int child = 0;
	for (auto id : adj[u]) {
		if (!used[id]) {
			used[id] = 1;
			int v = edges[id].fi + edges[id].se - u;	
			if (num[v] == 0) {
				child ++;
				//cout << u << " " << v << '\n';
				dfs(v, u);
				adj2[u].push_back(v);
				adj2[v].push_back(u);
				low[u] = min(low[u], low[v]);
				if (low[v] > num[u]) bridge[id] = true;
				if (e == 0) {
					if (child > 1) joint[u] = 1;
				}
				else if (low[v] >= num[u]) joint[u] = true;
			}
			else low[u] = min(low[u], num[v]);
		}
	}
}

void dfs2(int u, int e) {
	vs[u] = 1;
	num_child[u] = 1;
	for (auto v : adj2[u]) {
		if (v == e) continue;
		dfs2(v, u);
		num_child[u] += num_child[v];
	}
}

void dfs3(int u, int e) {
	vs[u] = 1;
	if (joint[u]) {
		ll up = cnt[num_scc[u]] - num_child[u];
		ll tam = cnt[num_scc[u]] * (cnt[num_scc[u]] - 1) / 2 - cnt[num_scc[u]] + 1;
		for (auto v : adj2[u]) {
			if (v == e) continue;
			if (low[v] < num[u]) up += num_child[v];
			else tam -= (num_child[v] * (num_child[v] - 1)) / 2;
		}
		//cout << u << " " << up << " " << tam << '\n';
		tam -= up * (up - 1) / 2;
		res[u] = tam;
	}
	for (auto v : adj2[u]) {
		if (v == e) continue;
		dfs3(v, u);
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edges[i] = {u, v};
		adj[u].push_back(i);
		adj[v].push_back(i);
	}
	for (int i = 1; i <= n; i++) 
		if (!num[i]) {
			scc ++;
			dfs(i, 0);
		}
	ll invalid = (n * (n - 1)) / 2;
	for (int i = 1; i <= scc; i++) invalid -= (cnt[i] * (cnt[i] - 1)) / 2;
	for (int i = 1; i <= n; i++) if (!vs[i]) dfs2(i, 0);
	memset(vs, false, sizeof(vs));
	for (int i = 1; i <= n; i++) if (!vs[i]) dfs3(i, 0);
	for (int i = 1; i <= n; i++) cout << (res[i] + invalid - 1ll * n + 1ll * cnt[num_scc[i]]) % MOD << " ";
	cout << '\n';
	for (int i = 1; i <= m; i++) {
		if (bridge[i] == 1) {
			ll mina = min(num_child[edges[i].fi], num_child[edges[i].se]);
			ll maxa = cnt[num_scc[edges[i].fi]] - mina;
			cout << (maxa * mina + invalid) % MOD << " ";
		}
		else cout << invalid % MOD << ' ';
	}
}
