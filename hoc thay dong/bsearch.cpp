#include <bits/stdc++.h>

#define name ""
#define test "test"
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
#define int ll

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, v, frac[10003], res = 0;

void solve(int l, int r, int less, int big, int dem, ll val) {
	if (r < l) return ;
	int mid = (l + r + 1) / 2;
	res = (res + val * frac[n - dem - 1]) % MOD;
	if (less) solve(mid + 1, r, less - 1, big, dem + 1, (val * less) % MOD);
	if (big) solve(l, mid - 1, less, big - 1, dem + 1, (val * big) % MOD);
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> v;
	frac[0] = 1;
	for (int i = 1; i <= n; i++) frac[i] = (frac[i - 1] * i) % MOD;
	solve(0, n - 1, v - 1, n - v, 0, 1);
	cout << res;
}