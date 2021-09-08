#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const ll MOD = 1E9 + 7;

ll n, m, a[100005], vs[100005], d[100005], up[100005], down[100005], ans = 0;

pair < ll, ll > f[100005];

vector < ll > adj1[100005], adj2[100005], topo;

bool th = true;

void dfs(ll u) {
	vs[u] = 1;
	for (auto v : adj2[u]) {
		if (vs[v] && d[v]) continue;
		//cout << u << " " << v << '\n';
		if (vs[v] && !d[v]) {
			//cout << "yeag" << '\n';
			cout << -1;
			th = false;
			exit(0);
		}
		dfs(v);
	}
	topo.push_back(u);
	d[u] = 1;
}

int main() {
	cin >> n >> m;
	memset(vs, 0, sizeof(vs));
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		ll u, v;
		cin >> u >> v;
		adj1[u].push_back(v);
		adj2[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
		if (!vs[i]) {
			dfs(i);
			if (th == false) {
				//cout << -1;
				return 0;
			}
		}

	for (int i = 0; i < topo.size(); i++) {
		f[topo[i]].fi = a[topo[i]];
		f[topo[i]].fi %= MOD;
		f[topo[i]].se = 1;
		for (auto v : adj2[topo[i]]) {
			f[topo[i]].fi += (f[v].fi + ((f[v].se) * a[topo[i]]) % MOD) % MOD;
			f[topo[i]].se += f[v].se;
			f[topo[i]].se %= MOD;

		}
		ans += f[topo[i]].fi;
		ans %= MOD;
		//cout << i << " " << f[topo[i]].fi << '\n'; 
	}

	//cout << topo.size() << '\n';
	
	cout << ans;
}