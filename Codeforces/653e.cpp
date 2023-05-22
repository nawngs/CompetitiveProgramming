#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "tree";
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

int n, m, cnt[300003], deg1, cnt_scc[300003];

bool th[300003], del[300003];

set < int > toremove;

queue < int > bfs;

vector < int > adj[300003], todo;

bool sol() {
	cin >> n >> m >> deg1;
	for (int i = 1; i <= n; i++) {
		th[i] = 1;
		adj[i].clear();
	}
	toremove.clear(); todo.clear();
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		if (u == 1) th[v] = 0;
		if (v == 1) th[u] = 0;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	for (int i = 2; i <= n; i++)
		toremove.insert(i);
	int scc = 0;
	for (int i = 2; i <= n; i++) {
		if (toremove.count(i)) {
			scc ++;
			cnt_scc[scc] = 0;
			toremove.erase(i);
			bfs.push(i);
			while (bfs.size()) {
				int x = bfs.front(); bfs.pop();
				cnt_scc[scc] += th[x];
				for (auto j : adj[x]) del[j] = 1;
				todo.clear();
				for (int j : toremove) 
					if (!del[j]) 
						todo.push_back(j);
				for (int j : todo)
					toremove.erase(j), bfs.push(j);
				for (auto j : adj[x]) del[j] = 0;

			}
		}
	}
	if (scc > deg1) return false;
	int s = 0;
	for (int i = 1; i <= scc; i++) {
		s += cnt_scc[i];
		if (!cnt_scc[i]) return false;
	}
	if (s >= deg1) return 1;
	return 0;
}

int main() {
	fast;
	//fre();
	//int O; cin >> O;
	int t = 1;
	//cin >> t;
	while (t --) cout << (sol() ? "possible" : "impossible") << ' ';
}