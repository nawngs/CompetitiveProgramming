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
		int child[2];
	} trie[4000003];

	ll n, a[100003], suff[100003], timer = 0;

	void update(ll x) {
		int cur = 0;
		for (int i = 39; i >= 0; i--) {
			int bit = (x >> i) & 1;
			if (trie[cur].child[bit] == 0) trie[cur].child[bit] = ++ timer;
			cur = trie[cur].child[bit];
		}
	}

	ll query(ll x) {
		 ll res = 0, cur = 0;
		 for (ll i = 39; i >= 0; i--) {
		 	int bit = (x >> i) & 1;
		 	if (trie[cur].child[bit ^ 1] != 0) {
		 		res |= (1ll << i);
		 		cur = trie[cur].child[bit ^ 1];
		 	}
		 	else {
		 		if (trie[cur].child[bit] == 0) break;
		 		cur = trie[cur].child[bit];
		 	}
		 }
		 return res;
	}

	int main() {
		fast;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		suff[n + 1] = 0;
		for (int i = n; i >= 1; i--) suff[i] = suff[i + 1] ^ a[i];
		ll ans = suff[1], prefix = 0;
		update(0);
		for (int i = 1; i <= n; i++) {
			prefix = prefix ^ a[i];
			update(prefix);
			ans = max(ans, query(suff[i + 1]));
		}
		cout << ans;
	}
