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

int n, m, d[9], newd[9];

int dp[103][2][3][4][5][6][7][8], res = 0;

bool th[10];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

void back_track(int id, int pos) {
	if (pos == 9) {
		if (dp[id][d[2]][d[3]][d[4]][d[5]][d[6]][d[7]][d[8]] == 0) return ;
		for (int i = 2; i <= 9; i++) {
			if (!th[i]) newd[i] = i - 1;
			else newd[i] = min(i - 1, d[i] + 1);
		}
		if (th[1]) {
			// cout << id + 1 << " " << 1 << '\n';
			// for (int j = 2; j <= 8; j++) cout << newd[j] << " ";
			// cout << '\n';
			add(dp[id + 1][newd[2]][newd[3]][newd[4]][newd[5]][newd[6]][newd[7]][newd[8]], 
			dp[id][d[2]][d[3]][d[4]][d[5]][d[6]][d[7]][d[8]]);
		}
		for (int i = 2; i <= 9; i++) if(d[i] == i - 1 && th[i]) {
			newd[i] = 0;
			// cout << id + 1 << " " << i << '\n';
			// for (int j = 2; j <= 8; j++) cout << newd[j] << " ";
			// cout << '\n';
			add(dp[id + 1][newd[2]][newd[3]][newd[4]][newd[5]][newd[6]][newd[7]][newd[8]], 
			dp[id][d[2]][d[3]][d[4]][d[5]][d[6]][d[7]][d[8]]);
			newd[i] = i - 1;
		}
		return ;
	}
	for (int i = (th[pos] ? 0 : pos - 1); i < pos; i++) {
		d[pos] = i;
		back_track(id, pos + 1);
	}
}

void calc(int pos) {
	if (pos == 9) {
		// for (int i = 2; i <= 8; i++) cout << d[i] << ' ';
		// cout << '\n';
		add(res, dp[n][d[2]][d[3]][d[4]][d[5]][d[6]][d[7]][d[8]]);
		return ;
	}
	for (int i = (th[pos] ? 0 : pos - 1); i < pos; i++) {
		d[pos] = i;
		calc(pos + 1);
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x; cin >> x;
		th[x] = 1;
	}
	dp[0][1][2][3][4][5][6][7] = 1;
	for (int i = 0; i < n; i++) {
		back_track(i, 2);
	}
	calc(2);
	cout << res;
}