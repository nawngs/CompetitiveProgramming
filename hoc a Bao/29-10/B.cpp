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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 30;
const int LGN = 20;

int n, k, a[NMAX + 3], nxt[NMAX + 3][LG + 3], jump[NMAX + 3], temp[NMAX + 3];

pii dp[NMAX + 3];

deque < int > pos[NMAX + 3];

bool check(int bit) {
	bool ok = false;
	temp[n + 1] = n + 1;
	dp[n + 1] = {0, 0};
	for (int i = n; i >= 1; i--) {
		temp[i] = max(jump[i], nxt[i][bit]);
		dp[i] = {0, 0};
	}
	for (int i = n; i >= 1; i--) if (temp[i] != n + 1) {
		if (dp[temp[i] + 1].fi == 0) dp[i] = {1, temp[i]};
		else dp[i] = {dp[temp[i] + 1].fi + 1, dp[temp[i] + 1].se};
		if (dp[i].fi == k && dp[i].se - i < n / 2) {
			ok = true;
			break;
		}
	}
	if (ok) for (int i = 1; i <= n; i++) jump[i] = temp[i];
	return ok;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) a[n + i] = a[i];
	n += n;
	for (int j = 0; j <= LG; j++) nxt[n + 1][j] = n + 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= LG; j++) {
            if (a[i] >> j & 1) nxt[i][j] = i;
            else nxt[i][j] = nxt[i + 1][j];
        } 
    }
	int res = 0;
	// check(2);
	for (int i = 30; i >= 0; i--) 
		if (check(i)) res ^= (1 << i);
	cout << res;
}