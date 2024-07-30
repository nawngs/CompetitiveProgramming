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
const int N = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, c, k, cnt[N + 3][18];

bool exist[1 << 18], bad[1 << 18];

string s;

void sol() {
	cin >> n >> c >> k >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < c; j++) cnt[i][j] = cnt[i - 1][j];
		cnt[i][s[i] - 'A'] ++;
	}
	for (int i = 0; i < (1 << c); i++) exist[i] = bad[i] = 0;
	for (int i = 1; i <= n - k + 1; i++) {
		int msk = 0;
		for (int j = 0; j < c; j++)
			if (cnt[i + k - 1][j] - cnt[i - 1][j] != 0) msk |= (1 << j);
		exist[msk] = 1;
	}
	exist[(1 << (s[n] - 'A'))] = 1;
	for (int i = 0; i < (1 << c); i++) 
		bad[i] = exist[(1 << c) - 1 - i];
	for (int j = 0; j < c; j++)
		for (int i = 0; i < (1 << c); i++) if (bad[i] && (i >> j & 1))
			bad[i ^ (1 << j)] = bad[i];
	int res = c;
	for (int i = 0; i < (1 << c); i++) 
		if (!bad[i]) res = min(res, __builtin_popcount(i));
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