#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, deg[NMAX + 3];

string s;

vector < int > adj[26][26];

vector < int > res;

void dfs(int u) {
	//cout << u << '\n';
	int to;
	for (auto v = 0; v < 26; v++) {
		if (adj[u][v].empty()) continue;
		to = v;
		int id = adj[u][v].back(); adj[u][v].pop_back();
		dfs(to);
		res.pb(id);
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	int st, fn;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		st = s[0] - 'a', fn = s[s.size() - 1] - 'a';
		adj[st][fn].pb(i);
	}
	dfs(st);
	if (res.size() != n) {
		cout << -1 << '\n';
		return 0;
	}
	reverse(res.begin(), res.end());
	for (auto x : res) cout << x << " ";
}