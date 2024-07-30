#include <bits/stdc++.h>

#define name "candyroad"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 998244353;
const ll BASE = 2309;

ll n, m, a[NMAX + 3], dp[NMAX + 3];

map < int, int > nxt;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll res = 0;
	ll val = (m * (m + 1)) / 2; val %= MOD;
	for (int i = n; i >= 1; i--) {
		dp[i] = (dp[i + 1] + val) % MOD;
		if (nxt.find(a[i]) == nxt.end()) dp[i] = (dp[i] - (n + 1 - i) * a[i] + MOD * MOD) % MOD;
		else dp[i] = (dp[i] - (nxt[a[i]] - i) * a[i] + MOD * MOD) % MOD;
		nxt[a[i]] = i; res = (res + dp[i]) % MOD;
		//cout << res << '\n';
	}
	cout << res;
}