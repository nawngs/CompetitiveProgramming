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

int n, m, num[100003], low[100003], timer = 0, sze = 0;

pii a[100003];

bool Is_Bridge[100003], th = false;

vector < int > adj[100003];

void dfs(int u, int e) {
	num[u] = low[u] = ++ timer;
	for (auto x : adj[u]) {
		int v = a[x].fi + a[x].se - u;
		if (v == e) continue;
		if (!num[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= num[v]) {
				Is_Bridge[x] = 1;
			}
		}
		else low[u] = min(low[u], num[v]);
	}
}

void calc(int u, int e, int len) {
	num[u] = len;
	sze ++;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (num[v] == -1) calc(v, u, (len ^ 1));
		else if (num[v] == num[u]) th = 1;
	}
}

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].fi >> a[i].se;
		adj[a[i].fi].push_back(i);
		adj[a[i].se].push_back(i);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		num[i] = -1;
	}
	for (int i = 1; i <= m; i++) {
		if (Is_Bridge[i]) continue;
		adj[a[i].fi].push_back(a[i].se);
		adj[a[i].se].push_back(a[i].fi);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (num[i] == -1) {
			sze = 0; th = false;
			calc(i, 0, 0);
			if (th) res += sze;
		}
	}
	cout << res;
}
