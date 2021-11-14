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

const string NAME = "cutting";
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

ll n, a[1000005], s[1000005], it[6000005], m, dp[1000005];

ll bs(ll val, ll r) {
	int l = 0, mid, ans = -1;
	while(l <= r) {
		mid = (l + r) / 2;
		if (s[mid] >= val) {
			ans = mid;
			r = mid - 1;
		} 
		else l = mid + 1;
	} 
	return ans;
}

void build_tree(ll node, ll l, ll r) {
	if (l == r) {
		it[node] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return -INF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	build_tree(1, 0, n);
	for (int i = 1; i <= n; i++) dp[i] = INF;

	for (int i = 1; i <= n; i++) {
		ll tam = bs(s[i] - m, i - 1);
		if (tam == -1) {
			cout << -1 << '\n';
			return ;
		}
		dp[i] = dp[tam] + query(1, 0, n, tam + 1, i);
	}
	cout << dp[n] << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
