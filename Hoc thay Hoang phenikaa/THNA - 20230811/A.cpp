//[FINISHED]
#include <bits/stdc++.h>

#define name ""
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
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, sze[NMAX + 3], dp[NMAX + 3];

vector < int > a[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sze[i];
		int mx = 0;
		for (int j = 0; j < sze[i]; j++) {
			int x; cin >> x;
			if (x > mx) a[i].pb(x);
			mx = max(mx, x);
		}
	}
	sort(a + 1, a + n + 1, [&](vector < int > &x, vector < int > &y) {
		return x.back() < y.back();
	});
	vector < int > lst;
	lst.pb(0);
	for (int i = 1; i <= n; i++) lst.pb(a[i].back());
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		for (int t = 0; t < SZE(a[i]); t++) {
			int j = lower_bound(lst.begin(), lst.end(), a[i][t]) - lst.begin() - 1;
			dp[i] = max(dp[i], dp[j] + SZE(a[i]) - t);
		}
	}
	cout << dp[n];
	
}