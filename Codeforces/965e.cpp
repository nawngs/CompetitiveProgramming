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
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Node {
	int nxt[26];
	bool end;
};

vector < Node > trie;

void add() {
	Node NewNode;
	for (int i = 0; i < 26; i++) NewNode.nxt[i] = -1;
	NewNode.end = false;
	trie.push_back(NewNode);
}

int n, cur;

multiset < int > ms[100003];

void dfs(int u, int dpt) {
	if (trie[u].end) ms[u].insert(dpt);
	for (int c = 0; c < 26; c++) {
		int v = trie[u].nxt[c];
		if (v == -1) continue;
		dfs(v, dpt + 1);
		if (ms[v].size() > ms[u].size()) swap(ms[v], ms[u]);
		auto it = ms[v].begin();
		while (it != ms[v].end()) {
			ms[u].insert(*it);
			advance(it, 1);
		}
	}
	if (!trie[u].end && u != 0) {
		ms[u].erase(ms[u].find(*ms[u].rbegin()));
		ms[u].insert(dpt);
	}

}

int main() {
	fast;
	//fre();
	cin >> n;
	add();
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		int pos = 0;
		for (auto c : s) {
			int val = c - 'a';
			if (trie[pos].nxt[val] == -1) {
				add();
				trie[pos].nxt[val] = trie.size() - 1;
			}
			pos = trie[pos].nxt[val];
		}
		trie[pos].end = 1;
	}
	dfs(0, 0);
	int res = 0;
	auto it = ms[0].begin();
	while (it != ms[0].end()) {
		res += *it;
		advance(it, 1);
	}
	cout << res;
}
