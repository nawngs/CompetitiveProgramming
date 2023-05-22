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

struct Node {
	bool end;
	int a[26];
} trie[100003];

int n, k, timer = 0;

bool CanWin[100003], CanLose[100003];

string s;


void add_string() {
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!trie[cur].a[s[i] - 'a']) trie[cur].a[s[i] - 'a'] = ++ timer;
		cur = trie[cur].a[s[i] - 'a'];
	}
	trie[cur].end = 1;
}

void dfs(int u = 0) {
	if (trie[u].end) {
		CanWin[u] = 0;
		CanLose[u] = 1;
		return ;
	}
	for (int i = 0; i <= 'z' - 'a'; i++) {
		if (!trie[u].a[i]) continue;
		dfs(trie[u].a[i]);
		CanWin[u] |= (!CanWin[trie[u].a[i]]);
		CanLose[u] |= (!CanLose[trie[u].a[i]]);
	}
}

void get_ans(int x) {
	cout << (x == 1 ? "First" : "Second") << '\n';
}

int main() {
	fast;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		add_string();
	}
	dfs();
	if (k == 1) get_ans(CanWin[0]);
	else if (!CanWin[0]) get_ans(CanWin[0]);
	else if (CanLose[0]) get_ans(CanWin[0]);
	else if (k % 2 == 1) get_ans(CanWin[0]);
	else get_ans(0);
}
	 