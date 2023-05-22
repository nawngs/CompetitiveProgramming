#include <bits/stdc++.h>

#define name "resort"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Node {
	int nxt[26];
	ll cnt;
};

vector < Node > trie;

void add_node() {
	Node res;
	for (int i = 0; i < 26; i++) 
		res.nxt[i] = -1;
	res.cnt = 0;
	trie.push_back(res);
}

int n, cnt[100003][26][26];

string s[100003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	add_node();
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		int cur = 0;
		for (auto c : s[i]) {
			trie[cur].cnt ++;
			if (trie[cur].nxt[c - 'a'] == -1) {
				trie[cur].nxt[c - 'a'] = sz(trie);
				add_node();
			}
			cur = trie[cur].nxt[c - 'a'];
		}
		trie[cur].cnt ++;
	}
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (auto c : s[i]) {
			for (int j = 0; j < 26; j++) {
				if (j == c - 'a') continue;
				int val = 0;
				if (trie[cur].nxt[j] != -1) val = trie[trie[cur].nxt[j]].cnt;
				cnt[i][j][c - 'a'] += val;
			}
			cur = trie[cur].nxt[c - 'a'];
		}
	}
	int q; cin >> q;
	while (q--) {
		int id;
		string str; 
		cin >> id >> str;
		ll res = 1;
		for (int i = 0; i < 26; i++)
			for (int j = i + 1; j < 26; j++) 
				res += cnt[id][str[i] - 'a'][str[j] - 'a'];

		cout << res << '\n';
	}
}