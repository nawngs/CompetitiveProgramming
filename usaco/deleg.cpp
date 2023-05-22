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

const string NAME = "deleg";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, cnt[100003];

int dem[100003];

vector < int > adj[100003], children[100003];

void dfs(int u, int e) {
	cnt[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		cnt[u] += cnt[v];
		children[u].push_back(cnt[v]);
	}
	if (cnt[u] != n) children[u].push_back(n - cnt[u]);
}

bool check (int k) {
	for (int i = 0; i <= k; i++) dem[i] = 0;
	for (int i = 1; i <= n; i++) {
		int th = 0;
		for (auto &x : children[i]) {
			int tam = x % k;
			if (tam == 0) continue;
			if (dem[k - tam]) {
				dem[k - tam] --;
				th --;
			}
			else {
				dem[tam] ++;
				th ++;
			}
		}
		if (th) return false;
	}
	return true;
}

void sol() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i < n; i++) {
		if ((n - 1) % i == 0) cout << check(i);
		else cout << 0;
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
