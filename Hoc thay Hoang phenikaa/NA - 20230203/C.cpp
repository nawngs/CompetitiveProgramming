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

int n, v[200003];

vector < int > a, b;

map < int, int > dp[200003];

void sol() {
	cin >> n;
	for (int i = 0; i <= n; i++) dp[i].clear();
	dp[0][-1] = 0; 
	a.clear();
	a.pb(0); v[0] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		b.clear();
		while (sz(a)) {
			if (v[a.back()] != v[i]) b.push_back(a.back());
			a.pop_back();
		}
		if (sz(b) == 6) b.pop_back();
		reverse(b.begin(), b.end());
		a = b;
		for (auto id : a) {
			for (auto x : dp[id]) {
				if (x.fi == v[i]) continue;
				dp[i][v[id]] = max(dp[i][v[id]], x.se + 1);
			}
		}
		a.pb(i);
	}
	int res = 0;
	for (int i = 0; i <= n; i++)
		for(auto x : dp[i]) res = max(res, x.se);
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}
