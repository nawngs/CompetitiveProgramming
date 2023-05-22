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

const string NAME = "viplist";
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

int n, m, k, sze[100003];

vector < int > adj[100003];

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue < int > que;
	for (int i = 1; i <= n; i++) {
		sze[i] = adj[i].size();
		if (sze[i] < k) {
			sze[i] = -1;
			que.push(i);
		}
	}
	while (que.size()) {
		auto u = que.front();
		que.pop();
		for (auto v : adj[u]) {
			if (sze[v] == -1) continue;
			sze[v] --;
			if (sze[v] < k) {
				sze[v] = -1;
				que.push(v);
			}
		}
	}
	vector < int > res;
	res.clear();
	for (int i = 1; i <= n; i++) if (sze[i] >= k) res.push_back(i);
	cout << res.size() << '\n';
	for (auto v : res) cout << v << " ";
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
