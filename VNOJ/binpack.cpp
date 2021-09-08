#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = 1E9 + 7;

int l, n, a[1000005], ans, f[25];

void backtrack(int pos) {
	for (int i = 1; i <= 2; i++) {
		f[pos] = i;
		if (pos == n) {
			int sum1 = 0, sum2 = 0, cnt = 0;
			for (int j = 1; j <= n; j++) {
				//cout << j << " " << f[j] << '\n';
				if (f[j] == 1) {
					if (sum1 + a[j] > l) {
						cnt ++;
						sum1 = a[j];
					}
					else sum1 += a[j];
				}
				else {
					if(sum2 + a[j] > l) {
						cnt ++;
						sum2 = a[j];
					}
					else sum2 += a[j];
				}
			}
			if (sum1 != 0) cnt ++;
			if (sum2 != 0) cnt ++;
			ans = min(ans, cnt);
		}
		else backtrack(pos + 1);
	}
}

void sub1() {
	ans = n;
	memset(f, 255, sizeof(f));
	backtrack(1);
	cout << ans << '\n';
	return ;
}

void sub2() {
	int sum1 = 0;
	int sum2 = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			if (sum1 % 2 == 1) sum1 += a[i];
			else if (sum2 % 2 == 1) sum2 += a[i];
				else if (sum1 < l) sum1 += a[i];
					else if (sum2 < l) sum2 += a[i];
						else {
							cnt ++;
							sum1 = a[i];
						}
		}
		else {
			if (sum1 % 2 == 0 && sum1 < l) sum1 += a[i];
			else if (sum2 % 2 == 0 && sum2 < l) sum2 += a[i];
				else if (sum1 < l - 1) sum1 += a[i];
					else if (sum2 < l - 1) sum2 += a[i];
					 	else if (sum1 > sum2) {
					 			cnt ++;
					 			sum1 = a[i];
					 		}
					 		else {
					 			cnt ++;
					 			sum2 = a[i];
					 		}
					 	
		}

	}
	if (sum1 != 0) cnt ++;
	if (sum2 != 0) cnt ++;
	cout << cnt << '\n';
	return ;
}

void minimize(int &a, int b) {
	if (b < a) a = b;
}

/*
int dp[10005][33][33];

void sub3() {

	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= l; j++)
			for (int k = 0; k <= l; k++) dp[i][j][k] = INF;

	dp[1][a[1]][0] = 0;
	dp[1][0][a[1]] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= l; j++) {
			for (int k = 0; k <= l; k++) {
				//if (dp[i][j][k] != INF) cout << i << " " << j << " " << k << " " << dp[i][j][k] << '\n';
				minimize(dp[i + 1][a[i + 1]][k], dp[i][j][k] + 1);
				if (j + a[i + 1] <= l) minimize(dp[i + 1][j + a[i + 1]][k], dp[i][j][k]);
				minimize(dp[i + 1][j][a[i + 1]], dp[i][j][k] + 1);
				if (k + a[i + 1] <= l) minimize(dp[i + 1][j][k + a[i + 1]], dp[i][j][k]);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= l; i++) 
		for (int j = 0; j <= l; j++) ans = min(ans, dp[n][i][j] + (i != 0) + (j != 0));
	cout  << ans;
	return;
}

int g[105][5005][105];

void sub4() {
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= l; j++) 
			for (int k = 0; k <= n; k++) g[i][j][k] = INF;
	g[1][0][0] = a[1];
	g[1][a[1]][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= l; j++) {
			for (int k = 0; k <= n; k++) {
				if (g[i][j][k] == INF) continue;
				//cout << i << " " << j << " " << k << " " << g[i][j][k] << '\n';
				minimize(g[i + 1][a[i + 1]][k + 1], g[i][j][k]);
				if (j + a[i + 1] <= l) minimize(g[i + 1][j + a[i + 1]][k], g[i][j][k]);
				minimize(g[i + 1][j][k + 1], a[i + 1]);
				if (g[i][j][k] + a[i + 1] <= l) minimize(g[i + 1][j][k], g[i][j][k] + a[i + 1]);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= l; i++) {
		for (int k = 0; k <= n; k++) {
			if (g[n][i][k] == INF) continue;
			ans = min(ans, k + (i != 0) + (g[n][i][k] != 0));
		}
	}
	cout << ans;
}
*/

pair < int, int > p[10005][5005];

void minimize_pair(pair < int, int > &x, int cnt, int k) {
	if (x.fi > cnt) {
		x = {cnt, k};
	}
	else if(x.fi == cnt) x.se = min(x.se, k);
}

void sub5() {
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= l; j++) p[i][j] = {INF, INF};
	p[1][a[1]] = {0, 0};
	p[1][0] = {0, a[1]};
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= l; j++) {
			int cnt = p[i][j].fi;
			int k = p[i][j].se;
			if (cnt == INF || k == INF) continue;
			//cout << i << " " << j << " " << k << " " << cnt << '\n';
			minimize_pair(p[i + 1][a[i + 1]], cnt + 1, k);
			if (j + a[i + 1] <= l) minimize_pair(p[i + 1][j + a[i + 1]], cnt, k);
			minimize_pair(p[i + 1][j], cnt + 1, a[i + 1]);
			if (k + a[i + 1] <= l) minimize_pair(p[i + 1][j], cnt, k + a[i + 1]);
		}
	}
	int ans = INF;
	for (int j = 0; j <= l; j++) {
		ans = min(ans, p[n][j].fi + (j != 0) + (p[n][j].se != 0));
	}
	cout << ans << '\n';
	return ;
	
}

int main() {
	freopen("binpack.inp", "r", stdin);
	freopen("binpack.out", "w", stdout);
	cin >> l >> n;
	bool check = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 2) check = false;
	}
	
	if (n <= 20) {
		sub1();
		//sub4();
		//sub5();
		return 0;
	}
	if (n <= 10000) {
		sub5();
		return 0;
	}
	sub2();
	
	/*if (l <= 30) {
		sub3();
		return 0;
	}
	if (n <= 100) {
		sub4();
		return 0;
	}
	*/
	
}