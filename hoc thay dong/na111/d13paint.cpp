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
const int NMAX = 4e3;
const ll MOD = 1e9 + 7;
const int BASE = 2e3;

int n, hv[NMAX + 3][NMAX + 3], ht[NMAX + 3][NMAX + 3];

void maximize(int &x, int y) {
	if (x < y) x = y;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c; int x, y, d;
		cin >> c >> x >> y >> d;
		x += BASE; y += BASE;
		if (c == 'A') {
			x -= d / 2; y -= d / 2;
			maximize(hv[x][y], d);
		}
		else {
			y -= d / 2;
			maximize(ht[x][y], d);
		}
	}
	for (int j = 0; j <= NMAX; j++) 
		for (int i = 0; i <= NMAX; i++) {
			maximize(hv[i + 1][j], hv[i][j] - 1);
			maximize(hv[i][j + 1], hv[i][j] - 1);
			maximize(hv[i + 1][j + 1], hv[i][j] - 1);	
			maximize(ht[i + 1][j + 1], ht[i][j] - 2);
			maximize(ht[i][j + 1], ht[i][j] - 1);
			if (i > 0) maximize(ht[i - 1][j + 1], ht[i][j] - 2);
		}
	ll cnt = 0;
	for (int i = 0; i <= NMAX; i++)
		for (int j = 0; j <= NMAX; j++) {
			if (hv[i][j] > 0) cnt += 4;
			else {
				//if (i == 2 && j == 1) cout << ht[i][j - 1] << " " << ht[i + 1][j - 1] << ' ' << ht[i + 1][j] << " " << ht[i][j] << '\n';
				if (j > 0 && (ht[i][j - 1] > 1 || ht[i + 1][j - 1] > 1)) cnt ++;
				if (ht[i][j] > 1 || (j > 0 && ht[i][j - 1] > 1)) cnt ++;
				if (ht[i][j] > 1 || ht[i + 1][j] > 1) cnt ++;
				if (ht[i + 1][j] > 1 || (j > 0 && ht[i + 1][j - 1] > 1)) cnt++;
   			}
   			//cout << i - BASE << " " << j - BASE << " " << cnt << '\n';
		}
	double res = 1.0 * cnt * 0.25;
	cout << fixed << setprecision(2) << res;
}