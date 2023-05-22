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
	const ll BLOCK_SIZE = 800;

	void fre() {
		string finp = NAME + ".inp";
		string fout = NAME + ".out";
		freopen(finp.c_str(), "r", stdin);
		freopen(fout.c_str(), "w", stdout);
	}

	ll n, q, a[nmax + 5], s[nmax / BLOCK_SIZE + 5], nblocks;

	void init() {
		nblocks = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;
		for (int i = 1; i <= n; i++) s[(i + BLOCK_SIZE - 1) / BLOCK_SIZE] += a[i]; 
	}

	void update(int pos, int val) {
		int block = (pos + BLOCK_SIZE - 1) / BLOCK_SIZE;
		s[block] = s[block] - a[pos] + val;
		a[pos] = val;
	}

	ll get_seg(ll l, ll r) {
		ll sum = 0;
		for (int i = l; i <= r; i++) sum += a[i];
		return sum;
	}


	ll query(ll l, ll r) {
		int lblock = (l + BLOCK_SIZE - 1) / BLOCK_SIZE;
		int rblock = (r + BLOCK_SIZE - 1) / BLOCK_SIZE;
		if (lblock == rblock) return get_seg(l, r);	
		ll res = 0;
		for (int i = lblock + 1; i < rblock; i++) res += s[i];
		return res + get_seg(l, min(n, lblock * BLOCK_SIZE)) + get_seg((rblock - 1) * BLOCK_SIZE + 1, r);
	}

	void sol() {
		cin >> n >> q;
		for (int i = 1; i <= n; i++) cin >> a[i];
		init();
		while (q--) {
			int k, x, y;
			cin >> k >> x >> y;
			if (k == 1) update(x, y);
			else cout << query(x, y) << '\n';
		}	
	}

	int main() {
		fast;
		//fre();
		int t = 1;
		//cin >> t;
		while (t --) sol();
	}
