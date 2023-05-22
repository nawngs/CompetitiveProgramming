#include <bits/stdc++.h>

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
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll dp[100003][33], pw[32], n, a[100003], s[100003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1, greater < ll >());
	for (int i = 1; i <= n; i++) 
		s[i] = (s[i - 1] + a[i]);
	ll res = LINF;
	for (ll i = max(1ll, n / 30); i <= n; i++) {
		ll total = (i - 1) * 3600;
		ll temp = 1;
		for (int j = 1; j <= n; j+=i) {
			total += (s[min(n, j + i - 1)] - s[j - 1]) * temp;
			temp *= 2;
		}
		res = min(res, total);
	}
	cout << res;
}