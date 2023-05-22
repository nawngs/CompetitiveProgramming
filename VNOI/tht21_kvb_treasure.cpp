#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const int INF = 1e9;
const int nmax = 1e7;
const int MOD = 1;

int n;

ll sum = 0;

vector < int > a;

void readINP() {
	a.resize(n + 2, 0);
	sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
}

//#######################################################################################

//SUB1 + SUB2

int f[26];

vector < pll > larr, rarr;

void backtrack(int pos, int l, int r) {
	if (pos == r + 1) {
		int sum1, sum2;
		sum1 = sum2 = 0;
		for (int i = 0; i <= r - l; i++) {
			if (f[l + i] == 1) sum1 += a[l + i];
			if (f[l + i] == 2) sum2 += a[l + i];
		}
		if (r == n) rarr.push_back({sum1 - sum2, sum1});
		else larr.push_back({sum1 - sum2, sum1});
		return ;
	}
	for (int i = 0; i <= 2; i++) {
		f[pos] = i;
		backtrack(pos + 1, l, r);
	}
}

int bs(int x) {
	int l = 0, r = rarr.size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (rarr[mid].fi <= x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void sol1() {
	larr.clear();
	rarr.clear();
	memset(f, 0, sizeof(f));
	backtrack(1, 1, n / 2);
	backtrack(n / 2 + 1, n / 2 + 1, n);
	sort(rarr.begin(), rarr.end(), [](pll &x, pll &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
	});
	ll ans = 0;
	for (auto v : larr) {
		int tam = bs(-v.fi);
		if (rarr[tam].fi + v.fi != 0 || tam == -1) continue;
		ans = max(ans, 2 * (v.se + rarr[tam].se));
	}
	cout << sum - ans << '\n';
} 

//###############################################################

// SUB3 + SUB4

const int ESP = 5e4;

int dp[105][2 * ESP];

void sol2() {
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= 2 * ESP; j++) dp[i][j] = -INF;

	dp[1][ESP] = 0;
	dp[1][ESP + a[1]] = a[1];
	dp[1][ESP - a[1]] = 0;

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 2 * ESP; j++) {
			if (dp[i][j] == -INF) continue;
			if (j == ESP) ans = max(ans, dp[i][j]);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + a[i + 1]] = max(dp[i + 1][j + a[i + 1]], dp[i][j] + a[i + 1]);
			dp[i + 1][j - a[i + 1]] = max(dp[i + 1][j - a[i + 1]], dp[i][j]);
		}
	}
	cout << sum - 2 * ans << '\n';
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while (cin >> n) {
		readINP();
		if (n <= 24) sol1();
		else sol2();
	}
}
