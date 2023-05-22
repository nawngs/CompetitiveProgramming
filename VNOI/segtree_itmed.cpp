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

ll n, k, a[100005], it[800005];

void update(ll node, ll l, ll r, ll pos, ll val) {
	if (pos < l || pos > r) return ;
	it[node] = max(it[node], val);
	if (l == r) return ;
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return -INF;
	if (u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= 6 * n; i++) it[i] = -INF;
	update(1, 1, n, 1, a[1]);
	ll ans = max(a[1], 1ll * 0);
	for (int i = 2; i <= n; i++) {
		ll temp = query(1, 1, n, max(i - k, 1ll * 1), i - 1);
		temp += a[i];
		ans = max(ans, max(temp, a[i]));
		update(1, 1, n, i, max(temp, a[i]));
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
