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

const string NAME = "football";
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
	//freopen(fout.c_str(), "w", stdout);
}

int n;

pii a[1003];

vector < int > adj[1003];

bool vs[1003][1003];

void dfs(int u) {
	for (auto v : adj[u]) {
		if (!vs[u][v]) {
			vs[u][v] = vs[v][u] = 1;
			cout << u << " " << v << " ";
			dfs(v);
		}
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) vs[i][j] = (i == j);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
		adj[i].clear(); 
	}
	while(1) {
		sort(a + 1, a + n + 1);
		if (a[n].fi == 0) break;
		for (int j = n - a[n].fi; j < n; j++) {
			if (a[j].fi == 0) {
				cout << -1 << '\n';
				return ;
			}
			else {
				a[j].fi --;
				adj[a[j].se].push_back(a[n].se);
				adj[a[n].se].push_back(a[j].se);
			}
		}
		a[n].fi = 0;
	}
	for (int i = 1; i <= n; i++) if (adj[i].size() & 1) dfs(i);
	for (int i = 1; i <= n; i++) if (!(adj[i].size() & 1)) dfs(i);
	cout << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
