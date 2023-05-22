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

int n, m;

set < int > adj[500003], toremove;

queue < int > bfs;

vector < int > todo;

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].insert(v); adj[v].insert(u);
	}
	vector < int > res;
	for (int i = 1; i <= n; i++)
		toremove.insert(i);
	for (int i = 1; i <= n; i++) {
		if (toremove.count(i)) {
			toremove.erase(i);
			bfs.push(i);
			int cnt = 0;
			while (bfs.size()) {
				int x = bfs.front(); bfs.pop();
				cnt ++;
				todo.clear();
				for (int j : toremove) 
					if (!adj[x].count(j)) 
						todo.push_back(j);
				for (int j : todo)
					toremove.erase(j), bfs.push(j);
			}
			res.push_back(cnt);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto x : res) cout << x << " ";
}
