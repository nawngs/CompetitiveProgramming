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
const int INF = 1E9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

bool dp[5003][5003];

string s;

vector < int > submask[5003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> s; n = SZE(s); s = ' ' + s;
	int k = __lg(n);
	for (int i = 1; i < (1 << k); i++)
		for (int j = i; j < (1 << k); j++) 
		 	if ((i & j) == i) submask[j].pb(i);
	for (int i = 0; i < (1 << k); i++)
		dp[i][i] = 1;
	for (int i = 0; i < n - (1 << k) + 1; i++) {
		char val = 'z';
		for (int u = i; u < n; u++) 
			if (dp[u][u - i] == 1) 
				val = min(val, s[u + 1]);
		cout << val; 
		for (int u = i; u < n; u++) {
			if (dp[u][u - i] == 1 && s[u + 1] == val) {
				dp[u + 1][u - i] = 1;
				for (auto sub : submask[(1 << k) - 1 - u + i]) {
					dp[u + 1 + sub][u - i + sub] = 1;
				}
			}
		}
	}
}