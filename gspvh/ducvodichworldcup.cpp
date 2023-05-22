#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll unsigned long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "ducvodichworldcup";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 9e18 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, q;

ll cnt_end[1003][1003], cnt_start[1003][1003], s[27];

char a[1003][1003];

ll mul(ll x, ll y) {
	if (y == 0 || x == 0) return 0;
	if (LINF / y < x) return LINF;
	else return x * y;
}

void add(ll &x, ll y) {
	x += y;
	if (x > LINF) x = LINF;
}

int main() {
	fast;
	fre();
	int O; cin >> O;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	cnt_end[n][m] = 1;
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--) {
			add(cnt_end[i][j], cnt_end[i + 1][j]);
			add(cnt_end[i][j], cnt_end[i][j + 1]);
		}
	while (q--) {
		ll x; cin >> x;
		string res = "";
		res += a[1][1];
		memset(cnt_start, 0, sizeof(cnt_start));
		cnt_start[1][1] = 1;
		for (int len = 2; len <= n + m - 1; len++) {
			for (int i = 'a'; i <= 'z'; i++) 
				s[i - 'a'] = 0;
			for (int i = max(1, len - m); i <= min(len - 1, n); i++) {
				int j = len - i;
				if (i < n) 
					add(s[a[i + 1][j] - 'a'], mul(cnt_start[i][j], cnt_end[i + 1][j]));
				if (j < m)
					add(s[a[i][j + 1] - 'a'], mul(cnt_start[i][j], cnt_end[i][j + 1]));
			}
			for (int c = 'a' - 'a'; c <= 'z' - 'a'; c++) {
				if (s[c] < x) x -= s[c];
				else {
					char ch = c + 'a';
					res += ch;
					for (int i = max(1, len - m); i <= min(len - 1, n); i++) {
						int j = len - i;
						if (i < n && a[i + 1][j] - 'a' == c) 
							add(cnt_start[i + 1][j], cnt_start[i][j]);
						if (j < m && a[i][j + 1] - 'a' == c)
							add(cnt_start[i][j + 1], cnt_start[i][j]);
					}
					break;
				}
			}
		}
		cout << res << '\n';
	}
}
