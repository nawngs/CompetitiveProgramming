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

bool dp[5003];

int n;

string a, b;

void sol() {
	cin >> a >> b; n = a.size();
	a = ' ' + a; b = ' ' + b;
	dp[n] = dp[n + 1] = 1;
	for (int i = n - 1; i >= 1; i--) {
		dp[i] = false;
		for (int j = i; j <= n; j++) {
			if (a[i] == b[i] && a[i] == a[j] && b[i] == b[j]) dp[i] |= dp[j + 1];
		}
	}
	cout << (dp[1] ? "YES" : "NO") << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}