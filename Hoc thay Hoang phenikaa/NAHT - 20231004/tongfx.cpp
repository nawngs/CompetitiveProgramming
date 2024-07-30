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
const int NMAX = 2e6;
const ll BASE = 2309;
const int LG = 21;

ll n, m, MOD, dp[NMAX + 3], f[NMAX + 3], a[NMAX + 3];

struct Node {
	ll total, nxt[2];
	Node() {
		total = 0;
		nxt[0] = nxt[1] = -1;
	}
};
 
vector < Node > trie;
 
void create() {
	trie.pb(Node());
}
 
void add(int x, ll val) {
	int cur = 0;
	for (int i = LG; i >= 0; i--) {
		int bit = (x >> i) & 1;
		if (trie[cur].nxt[bit] == -1) {
			create();
			trie[cur].nxt[bit] = trie.size() - 1;
		}
		cur = trie[cur].nxt[bit];
		trie[cur].total = (trie[cur].total + val) % MOD;
	}
}

ll get(int x, int mx) {
	ll cur = 0, res = 0;
	for (int i = LG; i >= 0; i--) {
		int bitx = (x >> i) & 1;
		int bitmx = (mx >> i) & 1;
		if (!bitmx && trie[cur].nxt[bitx ^ 1] != -1) res = (res + trie[trie[cur].nxt[bitx ^ 1]].total) % MOD;
		if (trie[cur].nxt[bitx ^ bitmx] == -1) {
			create();
			trie[cur].nxt[bitx ^ bitmx] = trie.size() - 1;
		}
		cur = trie[cur].nxt[bitx ^ bitmx];
	}
	return (res + trie[cur].total) % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> MOD;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= 2 * m; i++) {
		trie.clear();
		create(); add(a[1], 1);
		for (int j = 2; j <= n; j++) {
			ll temp = get(a[j], i);
			f[i] = (f[i] + temp) % MOD;
			add(a[j], (temp + 1) % MOD);
		}
	}
	ll res = 0;
	for (int i = 1; i <= 2 * m; i++) res = (res + i * (f[i] - f[i + 1] + MOD)) % MOD;
	cout << res;
}