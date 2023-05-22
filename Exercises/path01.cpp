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

const string NAME = "path01";
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

ll n, same[100003], res, f0[100003], f1[100003], dem = 0;

vector < pii > adj[100003];

void dfs(int u, int e, int val) {
	dem ++;
	same[u] = (e == 0 ? u : same[e]);
	for (auto v : adj[u]) {
		if (v.se != val || v.fi == e) continue;
		dfs(v.fi, u, val);
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	memset(same, 255, sizeof(same));
	for (int i = 1; i <= n; i++) {
		if (same[i] == -1) {
			dem = 0;
			dfs(i, 0, 0);
			f0[i] = dem - 1;
		}
		else f0[i] = f0[same[i]];
		res += f0[i];
	}
	memset(same, 255, sizeof(same));
	for (int i = 1; i <= n; i++) {
		if (same[i] == -1) {
			dem = 0;
			dfs(i, 0, 1);
			f1[i] = dem - 1;
		}
		else f1[i] = f1[same[i]];
		res += f1[i];
	}
	res /= 2;
	for (int i = 1; i <= n; i++) res += (f1[i] * f0[i]);
	cout << res;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
