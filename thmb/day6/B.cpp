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
	int height, cnt;
	int a[26];
};

int n;

ll ans = 0;

vector < Node > trie;

string s;

void add_node() {
	Node tam;
	tam.height = 0;
	tam.cnt = 0;
	for (int i = 0; i < 26; i++) {
		tam.a[i] = -1;
	}
	trie.push_back(tam);
}

void add_string() {
	int pre = 0;
	for (int i = 0; i < s.size(); i++) {
		trie[pre].cnt ++;
		ans = max(ans, 1ll * trie[pre].cnt * 1ll * trie[pre].height);
		if (trie[pre].a[s[i] - 'A'] == -1) {
			add_node();
			trie.back().height = trie[pre].height + 1;
			trie[pre].a[s[i] - 'A'] = trie.size() - 1;
		} 
		pre = trie[pre].a[s[i] - 'A'];
	}
	trie[pre].cnt ++;
	//cout << trie[pre].cnt << " " << trie[pre].height << '\n';
	ans = max(ans, 1ll * trie[pre].cnt * 1ll * trie[pre].height);
} 

int main() {
	fast;
	add_node();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		add_string();
	}
	cout << ans;
}
