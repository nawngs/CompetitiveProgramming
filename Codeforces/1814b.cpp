#include <bits/stdc++.h>

#define int ll
#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll aa, bb;

ll solve(ll x) {
	ll res = x - 1 + (aa + x - 1) / x + (bb + x - 1) / x;
	return res;
}	

void sol() {
	cin >> aa >> bb;
	ll res = LINF;
	for (ll i = 1; i * i <= max(aa, bb) + NMAX; i++) 
		res = min(res, solve(i));
	cout << res << '\n';
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}