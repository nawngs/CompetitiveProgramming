#include <bits/stdc++.h>

#define int ll
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

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m;

char a[103][103];

int s[103][103];


bool check(int x, int y, int u, int v) {
	int val = s[u][v] - s[x - 1][v] - s[u][y - 1] + s[x - 1][y - 1];
	return val == (u - x + 1) * (v - y + 1);
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			s[i][j] = (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j] - '0');
		}
	ll res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			for (int p = i; p <= n; p++)
				for (int q = j; q <= m; q++) {
					if (check(i, j, p, q)) {
						//cout << i << " " << j << " " << p << " " << q << '\n';
						res += (p - i + 1) * (p - i + 1) + (q - j + 1) * (q - j + 1);
					}
					res %= MOD;
				}
	cout << res;
}