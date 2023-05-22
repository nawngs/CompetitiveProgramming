#include <bits/stdc++.h>

#define name "BitAnd2"
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

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[1000003], dp[(1 << 20)];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int id = 0;
		for (int bit = 0; bit < 20; bit++) 
			if (!(a[i] >> bit & 1)) 
				id ^= (1 << bit);
		dp[id] = max(dp[id], a[i]);
	}
	for (int i = (1 << 20) - 1; i > 0; i--) 
		for (int bit = 0; bit < 20; bit++)
			if (i >> bit & 1) 
				dp[i ^ (1 << bit)] = max(dp[i ^ (1 << bit)], dp[i]);
	for (int i = 1; i <= n; i++) 
		cout << dp[a[i]] << ' ';
	
}