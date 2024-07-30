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

int n;

struct Node {
	bool lst;
	int nxt[26];
	int mxlen = 0;
	Node() {
		lst = false; mxlen = 0;
		for (int i = 0; i < 26; i++) nxt[i] = -1;
	}
};

vector < Node > trie;

vector < char > res;

void create() {
	trie.pb(Node());
	return ;
}

void add(const string &s) {
	int cur = 0;
	for (auto c : s) {
		if (trie[cur].nxt[c - 'a'] == -1) {
			create();
			trie[cur].nxt[c - 'a'] = SZE(trie) - 1;
		}
		cur = trie[cur].nxt[c - 'a'];
	}
	trie[cur].lst = true;
}

void dfs(int u) {
	for (int i = 0; i < 26; i++) {
		int v = trie[u].nxt[i];
		if (v == -1) continue;
		dfs(v);
		trie[u].mxlen = max(trie[u].mxlen, trie[v].mxlen + 1);
	}
}

void solve(int u, bool bck) {
	if (trie[u].lst) res.pb('P');
	int pos = -1;
	for (int i = 0; i < 26; i++) {
		int v = trie[u].nxt[i];
		if (v == -1) continue;
		if (pos == -1 && trie[v].mxlen + 1 == trie[u].mxlen) pos = i;
	}
	for (int i = 0; i < 26; i++) {
		int v = trie[u].nxt[i];
		if (v == -1 || i == pos) continue;
		res.pb(i + 'a');
		solve(v, 0);
	}
	if (pos != -1) {
		res.pb(pos + 'a');
		solve(trie[u].nxt[pos], bck);
	}
	if (!bck) res.pb('-');
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	create();
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		add(s);
	}
	dfs(0); solve(0, 1);
	cout << res.size() << '\n';
	for (auto x : res) cout << x << '\n';
}