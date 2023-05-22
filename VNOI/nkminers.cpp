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
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dp[100003][4][4][4][4], a[100003], ans = 0;

void maximize(int &x, int y) {
	x = max(x, y);
	ans = max(ans, x);
}

int get_diff(int a, int b, int c) {
	vector < int > tam;
	tam.clear();
	tam.push_back(a);
	tam.push_back(b);
	tam.push_back(c);
	sort(tam.begin(), tam.end());
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		if (tam[i] == 0) continue;
		if (i == 0 || tam[i] != tam[i - 1]) ans ++;
	}
	return ans;
}

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'M') a[i + 1] = 1;
		if (c == 'F') a[i + 1] = 2;
		if (c == 'B') a[i + 1] = 3;
	}
	for (int i = 0; i <= n; i++) 
		for (int pre11 = 0; pre11 < 4; pre11++)
			for (int pre12 = 0; pre12 < 4; pre12++) 
				for (int pre21 = 0; pre21 < 4; pre21++) 
					for (int pre22 = 0; pre22 < 4; pre22++) dp[i][pre11][pre12][pre21][pre22] = -INF;
	dp[0][0][0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int pre11 = 0; pre11 < 4; pre11++) {
			for (int pre12 = 0; pre12 < 4; pre12++) {
				for (int pre21 = 0; pre21 < 4; pre21++) {
					for (int pre22 = 0; pre22 < 4; pre22++) {
						if (dp[i - 1][pre11][pre12][pre21][pre22] == -INF) continue;
						maximize(dp[i][pre12][a[i]][pre21][pre22], dp[i - 1][pre11][pre12][pre21][pre22] + get_diff(pre11, pre12, a[i]));
						maximize(dp[i][pre11][pre12][pre22][a[i]], dp[i - 1][pre11][pre12][pre21][pre22] + get_diff(pre21, pre22, a[i]));
					}
				}
			}
		}
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
