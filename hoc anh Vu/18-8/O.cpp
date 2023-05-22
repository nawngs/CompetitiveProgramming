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

int casemiro = 0, n;

ll f[23][205][205];

string s, t, a[205];

void minimize(ll &x, ll y) {
	x = min(x, y);
}

void sol() {
	cin >> t >> n;
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		++ dem;
		cin >> a[dem];
		++ dem;
		cin >> a[dem];
	}
	a[++ dem] = s; a[++ dem] = t;
	for (int len = 1; len <= s.size(); len++)
		for (int i = 1; i <= dem; i++)
			for (int j = 1; j <= dem; j++) f[len][i][j] = (i == j ? 0 : LINF);
	for (int i = 1; i < dem - 2; i+=2) f[a[i].size()][i][i + 1] = 1;
	for (int i = 1; i <= dem; i++) reverse(a[i].begin(), a[i].end());
	for (int len = 1; len <= s.size(); len++) {
		for (int i = 1; i <= dem; i++) if (len <= a[i].size())
			for (int j = 1; j <= dem; j++)
				if (a[j].size() >= len && a[i][len - 1] == a[j][len - 1]) minimize(f[len][i][j], f[len - 1][i][j]);
		for (int k = 1; k <= dem; k++) if (len <= a[k].size())
			for (int i = 1; i <= dem; i++) if (len <= a[i].size()) 
				for (int j = 1; j <= dem; j++) if (len <= a[j].size()) 
					minimize(f[len][i][j], f[len][i][k] + f[len][k][j]);
		// for (int i = 1; i <= dem; i++) 
		// 	for (int j = 1; j <= dem; j++) cout << len << " " << a[i] << " " << a[j] << " " << f[len][i][j] << '\n';
	}
	cout << "Case " << ++ casemiro << ": ";
	if (f[s.size()][dem - 1][dem] == LINF) cout << "No solution" << '\n';
	else cout << f[s.size()][dem - 1][dem] << '\n';
}

signed main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (cin >> s && s != ".") sol();
}