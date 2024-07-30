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
const int LG = 19;

struct Node {
	int cnt, nxt[2], dem[LG + 3];
	Node() {
		cnt = 0;
		nxt[0] = nxt[1] = -1;
		for (int i = 0; i <= LG; i++) dem[i] = 0;
	}
};

vector < Node > trie;

void create() {
	trie.pb(Node());
	return ;
}

int X0R;

void add(int x) {
	int cur = 0;
	trie[cur].cnt ++;
	for (int j = LG; j >= 0; j--) trie[cur].dem[j] += (x >> j & 1);
	for (int i = LG; i >= 0; i--) {
		int val = (x >> i & 1);
		if (trie[cur].nxt[val] == -1) {
			create();
			trie[cur].nxt[val] = trie.size() - 1;
		}
		cur = trie[cur].nxt[val]; trie[cur].cnt ++;
		for (int j = i; j >= 0; j--) trie[cur].dem[j] += (x >> j & 1);
	}
}

void erase(int x) {
	int cur = 0;
	for (int i = LG; i >= 0; i--) {
		int val = (x >> i & 1);
		if (trie[cur].nxt[val] == -1) {
			create();
			trie[cur].nxt[val] = trie.size() - 1;
		}
		cur = trie[cur].nxt[val];
	}
	if (trie[cur].cnt == 0) return ;
	cur = 0;
	trie[cur].cnt --;
	for (int j = LG; j >= 0; j--) trie[cur].dem[j] -= (x >> j & 1);
	for (int i = LG; i >= 0; i--) {
		int val = (x >> i & 1);
		cur = trie[cur].nxt[val]; trie[cur].cnt --;
		for (int j = i; j >= 0; j--) trie[cur].dem[j] -= (x >> j & 1);
	}
	
}

ll get(int x) {
	ll cur = 0, res = 0;
	for (int i = LG; i >= 0; i--) {
		if (trie[cur].nxt[0] == -1) {
			create();
			trie[cur].nxt[0] = trie.size() - 1;
		}
		if (trie[cur].nxt[1] == -1) {
			create();
			trie[cur].nxt[1] = trie.size() - 1;
		}
		int val = (X0R >> i & 1);
		int nxt0 = trie[cur].nxt[val];
		if (x >= trie[nxt0].cnt) {
			x -= trie[nxt0].cnt;
			for (int j = i - 1; j >= 0; j--) {
				if (X0R >> j & 1) res += (trie[nxt0].cnt - trie[nxt0].dem[j]) * (1 << j);
				else res += trie[nxt0].dem[j] * (1 << j);
			}
			res += x * (1 << i);
			cur = trie[cur].nxt[val ^ 1];
		}
		else cur = trie[cur].nxt[val];
	}
	return res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	int q; cin >> q;
	create();
	while (q--) {
		int x, y; cin >> x >> y;
		if (x == 0) add(y ^ X0R);
		if (x == 1) erase(y ^ X0R);
		if (x == 2) X0R ^= y;
		if (x == 3) cout << get(y) << '\n';
	}
	
}
