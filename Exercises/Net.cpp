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

const string NAME = "net";
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

int n, m, num[13], tail[13], bridges = 0, low[13], timeDFS = 0;

vector < int > adj[13];

void dfs(int u, int pre){
	num[u] = low[u] = ++ timeDFS;
	int child = 0;
	for(auto v : adj[u]){
		if(v == pre) continue;
		if(!num[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			child ++;
			if(num[v] == low[v]) bridges ++;
		}
		else low[u] = min(low[u], num[v]);
	}
	tail[u] = timeDFS;
}

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) if(num[i] == 0) dfs(i, 0);
	cout << m - bridges + 1;
}
