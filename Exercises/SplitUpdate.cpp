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

ll n, q, a[200002], it_a[1200002], s[200002], dp[200002];

bool next[200002];

bool check(ll prev2, ll prev1, ll cur) {
	if (cur < prev1 && prev2 < prev1) return true; // prev1 la day
	if (cur > prev1 && prev2 > prev1) return true; // prev1 la dinh
	return false;
}

void sol() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = 0;
	dp[2] = abs(a[2] - a[1]);
	for (int i = 3; i <= n; i++) {
		if (check(a[i - 2], a[i - 1], a[i])) {
			next[i] = true;
			dp[i] = max(dp[i - 2] + abs(a[i] - a[i - 1]), dp[i - 1]);
		}
		else dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
	}
	while (q --) {
		ll l, r, x;
		cin >> l >> r >> x;
		update_a(1, 1, n, l, r, x);
		ll val_l = query_a(1, 1, n, l, l);
		if (l > 2) {
			ll val_l_prev1 = query_a(1, 1, n, l - 1, l - 1);
			ll val_l_prev2 = query_a(1, 1, n, l - 2, l - 2);
			if (check(val_l_prev2, val_l_prev1, val_l)) {
				dp[l] = max(dp[l - 2] + abs(a[l] - a[l - 1]), dp[l - 1]);
				next[l] = 1;
			}
			else {
				next[l] = 0;
				dp[l] = dp[l - 1] + abs(a[l] - a[l - 1]);
			}
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
