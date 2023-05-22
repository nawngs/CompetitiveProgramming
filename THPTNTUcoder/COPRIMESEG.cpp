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

ll n, a[100005], it[600005];

void build_tree(ll node, ll l, ll r) {
	if (l == r) {
		it[node] = a[l];
		return ;
	}
	ll mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it[node] = __gcd(it[node * 2], it[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return __gcd(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build_tree(1, 1, n);
	ll l = 1, r = 0, ans = INF, pos;
	while (r <= n) {
		r ++;
		ll tam = query(1, 1, n, l, r);
		if (tam == 1) {
			if (ans > r - l + 1) ans = r - l + 1;
			r --;
			l ++;
		}
	}
	if (ans == INF) cout << -1;
	else cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
