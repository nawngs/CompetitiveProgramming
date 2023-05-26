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

mt19937_64 rng(time(0));

int n, m, k;

string s[4103];

bool valid[4103];

int cnt[4103][33];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) 
			cnt[j][s[i][j] - 'A'] ++; 
	}
	for (int i = 1; i <= n; i++) {
		int dem = 0;
		for (int j = 0; j < m; j++)
			for (int c = 0; c < 26; c++) if (s[i][j] - 'A' != c) dem += cnt[j][c];
		if (dem == (n - 1) * k) valid[i] = 1;
	}
	for (int REP = 0; REP <= 15; REP++) {
		int sze = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			if (!valid[i] && rng() % 2) {
				sze++;
				for (int j = 0; j < m; j++) 
					cnt[j][s[i][j] - 'A'] ++; 
				}
		}
		for (int i = 1; i <= n; i++) {
			if (!valid[i]) continue;
			int dem = 0;
			for (int j = 0; j < m; j++)
				for (int c = 0; c < 26; c++) 
					if (s[i][j] - 'A' != c) dem += cnt[j][c];
			if (dem != sze * k) valid[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		if (valid[i]) cout << i;
}