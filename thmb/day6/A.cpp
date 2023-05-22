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

struct Node {
	bool end;
	int a[26];
};

vector < Node > trie;

void add_node() {
	Node tam;
	tam.end = false;
	for (int i = 0; i < 26; i++) {
		tam.a[i] = -1;
	}
	trie.push_back(tam);
}

void add_string(string s) {
	int pre = 0;
	for (int i = 0; i < s.size(); i++) {
		if (trie[pre].a[s[i] - 'a'] == -1) {
			add_node();
			trie[pre].a[s[i] - 'a'] = trie.size() - 1;

		} 
		pre = trie[pre].a[s[i] - 'a'];
	}
	trie[pre].end = true;
} 

int n, m;

void solve() {
	string s;
	cin >> s;
	int pre = 0;
	for (int i = 0; i < s.size(); i++) {
		if (trie[pre].a[s[i] - 'a'] == -1) {
			cout << 0 << '\n';
			return ;
		}
		pre = trie[pre].a[s[i] - 'a'];
	}
	cout << (trie[pre].end) << '\n';
}

int main() {
	fast;
	cin >> n;
	add_node();
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		add_string(s);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) solve();
	
}
