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

ll n, k, it[600003];
vector < pll > s;

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(node * 2, l, (l + r) / 2, u, v) + query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
}

void update(ll node, ll l, ll r, ll pos) {
	if (pos < l || pos > r) return ;
	it[node] ++;
	if (l == r) return ;
	update(node * 2, l, (l + r) / 2, pos);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos);
}

void sol() {
	cin >> n >> k;
	s.resize(n + 1, {0, 0});
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x >= k) s[i].fi = s[i - 1].fi + 1;
		else s[i].fi = s[i - 1].fi - 1;
		s[i].se = i;
	}
	sort(s.begin(), s.end(), [](pll &x, pll &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
	});
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += query(1, 0, n, 0, s[i].se);
		update(1, 0, n, s[i].se);
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
