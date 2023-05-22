
/*#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "votes";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E15;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k;

bool used[503];

pair < ld, pii > dp[503][503];

pair < int, int > a[503];

int main() {
	fast;
	fre();
	cin >> n >> k;
	vector < int > b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].se >> a[i].fi;
		if (a[i].fi == -1) a[i].fi = INF;
		b.push_back(a[i].se);
	}
	// cout << "//##############################################################################" << '\n';
	// for (int i = 1; i <= n; i++)
	// 	cout << a[i].se << " " << a[i].fi << '\n';
	// cout << "//##############################################################################" << '\n';
	ld res = 0;
	sort(b.begin(), b.end());
	for (int i = 0; i < k; i++) res += b[i];
	ld cur = 0;
	vector < int > pos;
	for (int tnv = 1; tnv <= k; tnv++) {
		int new_tnv = -1;
		ld ans = INF;
		for (int i = 1; i <= n; i++) {
			if (used[i] || a[i].fi == INF) continue;
			vector < int > tam;
			tam = pos;
			ld temp = 0;
			tam.push_back(a[i].fi);
			sort(tam.begin(), tam.end());
			int cnt = 1;
			for (auto x : tam) {
				temp += 1.0 * x / cnt;
				cnt ++;
			}
			tam.clear();
			for (int j = 1; j <= n; j++) {
				if (used[j] || j == i) continue;
				tam.push_back(a[j].se);
			}
			sort(tam.begin(), tam.end());
			for (int j = 0; j < k - tnv; j++) {
				temp += 1.0 * tam[j] / (tnv + 1);
			}
			if (ans > temp) {
				ans = temp;
				new_tnv = i;
			}
		}
		//cout << a[new_tnv].fi << " " << a[new_tnv].se << '\n';
		res = min(res, ans);
		used[new_tnv] = 1;
		pos.push_back(a[new_tnv].fi);
	}
	cout << fixed << setprecision(15) << res << '\n';

}*/
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

const string NAME = "votes";
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

int n, k;

double dp[503][503][503];

pair < int, int > a[503];


int main() {
	fast;
	fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].se >> a[i].fi;
		if (a[i].fi == -1) a[i].fi = INF;
	}
	sort(a + 1, a + n + 1);
	double res = INF;
	for (int tnv = 0; tnv <= k; tnv++) {
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= min(i, k); j++) {
				if (i == j) for (int p = 0; p <= tnv; p++) dp[i][j][p] = INF;
				else dp[i][j][tnv] = INF;
			}
		dp[0][0][0] = 0;
		for (int i = 1; i <= n; i++) 
			for (int j = 0; j <= min(i, k); j++) {
				if (i == j) {
					for (int p = 0; p <= min(tnv, j); p++) {
						dp[i][j][p] = dp[i - 1][j][p];
						if (j > 0) {
							dp[i][j][p] = min(dp[i][j][p], dp[i - 1][j - 1][p] + 1.0 * a[i].se / (tnv + 1));
							if (p > 0) dp[i][j][p] = min(dp[i][j][p], dp[i - 1][j - 1][p - 1] + 1.0 * a[i].fi / p);
						}			
					}
				}
				else {
					dp[i][j][tnv] = min(dp[i][j][tnv], dp[i - 1][j][tnv]);	
					if (j > 0) dp[i][j][tnv] = min(dp[i][j][tnv], dp[i - 1][j - 1][tnv] + 1.0 * a[i].se / (tnv + 1));
				}
				if (j == k) res = min(res, dp[i][j][tnv]);
			}
	}
	cout << fixed << setprecision(15) << res << '\n';

}

