#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a, b, s[200003], it[1200003];

void build_tree(ll node, ll l, ll r) {
	if (l == r) {
		it[node] = s[l];
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	return min(query(node * 2, l, (l + r) / 2, u, v), query(node * 2 + 1, (l + r) / 2 + 1, r, u, v));
}

void sol() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	build_tree(1, 0, n);
	ll ans = -INF;
	for (int i = a; i <= n; i++) {
		ll tam = query(1, 0, n, max(1ll * 0, i - b), i - a);
		ans = max(ans, s[i] - tam);
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
