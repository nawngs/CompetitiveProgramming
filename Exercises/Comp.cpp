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

const string NAME = "comp";
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

int n;

ll f[5003];

vector < int > g[5003], adj[5003];

queue < int > que;

bool vs[5003];

void bfs(int u) {
	que.push(u);
	vs[u] = 1;
	while (que.size()) {
		int x = que.front(); que.pop();
		for (auto v : g[x]) {
			if (vs[v]) continue;
			adj[x].push_back(v);
			vs[v] = 1;
			que.push(v);
		}
	}
}

void calc(int u) {
	ll s = 1;
	for (auto v : adj[u]) {
		calc(v);
		s += f[v];
	}
	f[u] = s;
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		while (k --) {
			int x; cin >> x;
			g[x].push_back(i);
		}
	}
	ll res = LINF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			adj[j].clear();
			vs[j] = false;
		}
		bfs(i);
		calc(i);
		ll cur = 0;
		for (int j = 1; j <= n; j++) cur += f[j];
		res = min(res, cur);
	}
	cout << res;
}
