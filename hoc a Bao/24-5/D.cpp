//[UNFINISHED]
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

int n, w[12][12], a[12][12];

string s[12];

int dp[(1 << 24)], nxtmsk, nxtmsk2;

vector < pii > pos[2];

void minimize(int &x, int y) {
	if (x > y) x = y;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
			if (s[i][j] == '.') w[i][j] = 0;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'B') a[i][j] = 1;
		}
	for (int i = 0; i < (1 << (2 * n)); i++) 
		dp[i] = INF;
	dp[(1 << n) - 1] = 0;
	for (int msk = 0; msk < (1 << (2 * n)); msk++) 
	if (__builtin_popcount(msk) == n && dp[msk] != INF) {
		pos[0].clear(); pos[1].clear();
		int cur1 = 0, cur2 = 0;
		for (int bit = 0; bit < 2 * n; bit++) {
			if (msk >> bit & 1) {
				if (cur2 < n && !(msk >> (bit + 1) & 1)) pos[a[cur1][cur2]].pb({cur1, cur2});
				cur1 ++;
			}
			else cur2 ++;
		} 
		for (auto x : pos[1]) {
			nxtmsk = msk ^ (1 << (x.fi + x.se)) ^ (1 << (x.fi + x.se + 1));
			minimize(dp[nxtmsk], dp[msk] + w[x.fi][x.se]);
			for (auto y : pos[0]) {
				nxtmsk2 = nxtmsk ^ (1 << (y.fi + y.se)) ^ (1 << (y.fi + y.se + 1));
				minimize(dp[nxtmsk2], dp[msk] + abs(w[x.fi][x.se] - w[y.fi][y.se]));
			}
		}
		for (auto x : pos[0]) {
			int nxtmsk = msk ^ (1 << (x.fi + x.se)) ^ (1 << (x.fi + x.se + 1));
			minimize(dp[nxtmsk], dp[msk] + w[x.fi][x.se]);
		}
	}
	cout << dp[((1 << (2 * n)) - 1) ^ ((1 << n) - 1)];
	
}



