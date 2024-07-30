//[UNFINISHED]
#include <bits/stdc++.h>

#define name "equivalent"
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

string str, s, ans;

int nxt[10], deg[2503], res = 0;

vector < int > adj[2503];

map < string, bool > f;

priority_queue < pair < pii, int >, vector < pair < pii, int > >, greater < pair < pii, int > > > heap;

void create(int st) {
	s = "";
	for (int i = st; i < SZE(str); i++) s += str[i];
	for (int i = 0; i < st; i++) s += str[i];
}

void solve() {
	memset(nxt, 255, sizeof(nxt));
	for (int i = 0; i < SZE(s); i++) adj[i].clear(), deg[i] = 0;
	for (int i = SZE(s) - 1; i >= 0; i--) {
		int v = s[i] - '0';
		if (v < 9 && nxt[v + 1] != -1) adj[i].pb(nxt[v + 1]), deg[nxt[v + 1]] ++;
		if (nxt[v] != -1) adj[i].pb(nxt[v]), deg[nxt[v]] ++;
		if (v > 0 && nxt[v - 1] != -1) adj[i].pb(nxt[v - 1]), deg[nxt[v - 1]] ++;
		nxt[v] = i;
	}
	for (int i = 0; i < SZE(s); i++) if (deg[i] == 0) heap.push({{0, s[i] - '0'}, i});
	ans = "";
	while (!heap.empty()) {
		auto u = heap.top(); heap.pop();
		char c = (u.fi.se + '0');
		ans += c;
		for (auto v : adj[u.se]) {
			deg[v] --;
			if (deg[v] == 0) heap.push({{u.fi.fi + 1, s[v] - '0'}, v});
		}
	}
	if (f.find(ans) == f.end()) res ++;
	f[ans] = 1;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	int n; cin >> n;
	for (int t = 1; t <= n; t++) {
		cin >> str;
		for (int i = 0; i < SZE(str); i++) {
			create(i);
			solve();
		}
	}
	cout << res;
}