#include <bits/stdc++.h>

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

int m, n, a[50], group[15][50], id[50], k[15], s[15], dp[50][1 << 15][50], dem[15][50], Bit0[1 << 15];

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
	cin >> m >> n;
	int cnt = -1;
	for (int i = 0; i < m; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			cin >> group[i][j];
			a[++ cnt] = group[i][j];
			id[cnt] = i;
			dem[i][j] = cnt;
			s[i] += a[cnt];
		}
	}
	for (int i = 0; i < (1 << m); i++) {
		Bit0[i] = -1;
		for (int j = 0; j < m; j++) {
			if (i >> j & 1) continue;
			Bit0[i] = j;
			break;
		}
	}
	memset(dp, 63, sizeof(dp));
	for (int i = 0; i < k[0]; i++)
		dp[dem[0][i]][0][dem[0][i]] = 0;
	int res = INF;
	for (int finished = 0; finished < (1 << m); finished++)
		for (int i = 0; i < n; i++)
			for (int lst = 0; lst < n; lst++) {
				if (dp[i][finished][lst] > INF) continue;
				for (int nxt_group = 0; nxt_group < m; nxt_group++) {
					if (finished >> nxt_group & 1) continue;
					for (int j = 0; j < k[nxt_group]; j++) {
						if (a[lst] < s[nxt_group] - group[nxt_group][j]) continue;
						minimize(dp[i][finished ^ (1 << nxt_group)][dem[nxt_group][j]], dp[i][finished][lst] + a[lst]);
					}
				}
				if (a[lst] < s[id[i]] - a[i]) continue;
				int temp = dp[i][finished][lst] + a[lst];
				int new_finished = finished ^ (1 << id[i]);
				int pos = Bit0[new_finished]; 
				if (pos == -1) {
					res = min(res, temp);
					continue;
				}
				for (int j = 0; j < k[pos]; j++) 
					minimize(dp[dem[pos][j]][new_finished][dem[pos][j]], temp);
			}
	if(res == INF) cout << -1;
	else cout << res;
}