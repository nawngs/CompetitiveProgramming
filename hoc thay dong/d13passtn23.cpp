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
const int NMAX = 1e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, L, R;

vector < int > f[NMAX + 3];

string s[NMAX + 3], dp[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> L >> R;
	for (int i = 1; i <= n; i++) cin >> s[i];
	sort(s + 1, s + n + 1, [&](string &x, string &y) {
		return x + y > y + x;
	});
	dp[0] = "";
	for (int i = 1; i <= n; i++) {
		for (int j = NMAX; j >= 0; j--) {
			if (j >= s[i].size() && dp[j - s[i].size()].size() == j - s[i].size()) 
				dp[j] = max(dp[j], dp[j - s[i].size()] + s[i]);
		}
	}
	int mx = -1;
	for (int i = L; i <= R; i++) 
		if (dp[i].size() == i && ((mx == -1) || (dp[i] > dp[mx]))) mx = i;
	if (mx == -1) {
		cout << -1;
		return 0;
	}
	cout << dp[mx];
}