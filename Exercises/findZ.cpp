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

const string NAME = "findZ";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string a, b;

bool dp[503][503];

int res[503], n, m, pos[503][503];

void readINP() {
	cin >> a >> b;
	n = a.size();
	a = ' ' + a;
	m = b.size();
	b = ' ' + b;	
}

void init1() {
	for (int i = 1; i <= m; i++) res[i] = INF;
	memset(dp, false, sizeof(dp));
	res[0] = 0;
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = true;
		for (int j = 1; j <= m; j++) {
			dp[i][j] = (dp[i - 1][j] || (dp[i - 1][j - 1] && a[i] == b[j]));
			if (dp[i][j]) res[j] = min(res[j], i);
			//cout << i << " " << j << " " << dp[i][j] << '\n';
		}
	}
	//for (int i = 1; i <= m; i++) cout << res[i] << '\n';
}

void init2() {
	memset(pos, 255, sizeof(pos));
	pos[n][1] = n + 1;
	for (int i = n - 1; i >= 1; i--) {
		pos[i][1] = n + 1;
		for (int j = 2; j <= m; j++) {
			char c = '0';
			for (int k = i + 1; k <= n; k++) {
				if (pos[k][j - 1] == -1) break;
				if (a[k] > c) {
					pos[i][j] = k;
					c = a[k];
				}
			}
		}
	}
}

void solve() {
	if (res[m] != INF) {
		for (int i = 1; i <= m; i++) cout << b[i];
		cout << '\n';
		return ;
	}
	string temp = "";
	string ans  = "";
	for (int i = 0; i < m; i++) {
		if (i != 0) temp = temp + b[i];
		int len = m - i;
		for (int j = res[i] + 1; j <= n; j++) {
			if (pos[j][len] == -1) break;
			if (a[j] < b[i + 1]) {
				int tam = j;
				string str = temp;
				int need = len;
				while (need > 0) {
					str += a[tam];
					tam = pos[tam][need];
					need --;
				}
				if (ans == "") ans = str;
				else ans = max(ans, str);
			}
		}
	}
	if (ans == "") cout << -1 << '\n';
	else cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) {
		readINP();
		init1();
		init2();
		solve();
	}
}
