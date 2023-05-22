#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, s[4003][4003], dp[803][4003], k;

inline void read(int& x) {
    x = 0; char ch;
    while ((ch = getchar()) < '0' || ch > '9') ;
    while (x = (x << 1) + (x << 3) + (ch ^ 48), (ch = getchar()) >= '0' && ch <= '9') ;
}


int get(int x, int y) {
	return s[y][y] - s[x - 1][y] - s[y][x - 1] + s[x - 1][x - 1];
}

void calc(int d, int l, int r, int u, int v) {
	if (l > r) return ;
	int mid = (l + r) / 2, pos;
	for (int i = u; i <= min(mid, v); i++) {
		if (dp[d][mid] > dp[d - 1][i] + get(i + 1, mid)) {
			dp[d][mid] = dp[d - 1][i] + get(i + 1, mid);
			pos = i;
		}
	}
	calc(d, l, mid - 1, u, pos);
	calc(d, mid + 1, r, pos, v);
}

int main() {
	fast;
	read(n);
	read(k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int x;
			read(x);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
		}
	memset(dp, 64, sizeof(dp));
	for (int i = 1; i <= n; i++) dp[1][i] = get(1, i);
	for (int i = 2; i <= k; i++) calc(i, 1, n, 1, n);
	cout << dp[k][n] / 2;
}
