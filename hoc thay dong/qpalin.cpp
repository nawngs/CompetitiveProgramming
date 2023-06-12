#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1E9 + 7;
const ll BASE = 2309;

int n, q;

ll pw[300003], inv[300003];

string s;

struct IT {
	ll it[1200003];
	#define lnode node * 2, l, (l + r) / 2
	#define rnode node * 2 + 1, (l + r) / 2 + 1, r
	void update(int node, int l, int r, int pos, ll val) {
		if (pos < l || pos > r) return ;
		if (l == r) {
			it[node] = val;
			return ;
		}
		update(lnode, pos, val); update(rnode, pos, val);
		it[node] = (it[node * 2] + it[node * 2 + 1]) % MOD;
	}
	ll query(int node, int l, int r, int u, int v) {
		if (v < l || r < u) return 0;
		if (u <= l && r <= v) return it[node];
		return (query(lnode, u, v) + query(rnode, u, v)) % MOD;
	}
} Tree1, Tree2;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q >> s;
	s = ' ' + s;
	pw[0] = 1; inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw[i] = (pw[i - 1] * BASE) % MOD;
		inv[i] = mu(pw[i], MOD - 2);
	}
	for (int i = 1; i <= n; i++) {
		Tree1.update(1, 1, n, i, (s[i] * pw[i]) % MOD);
		Tree2.update(1, 1, n, n - i + 1, (s[i] * pw[n - i + 1]) % MOD);
	}
	while (q--) {
		int type; cin >> type;
		if (type == 2) {
			int l, r; cin >> l >> r;
			ll v1 = Tree1.query(1, 1, n, l, r), v2 = Tree2.query(1, 1, n, n - r + 1, n - l + 1);
			v1 = (v1 * inv[l - 1]) % MOD; v2 = (v2 * inv[n - r]) % MOD;
			cout << (v1 == v2 ? "YES" : "NO") << '\n';
		}
		else {
			int pos; cin >> pos;
			char c; cin >> c;
			Tree1.update(1, 1, n, pos, (c * pw[pos]) % MOD);
			Tree2.update(1, 1, n, n - pos + 1, (c * pw[n - pos + 1]) % MOD);
		}
	}
}
