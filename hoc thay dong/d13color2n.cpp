#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1E9 + 7;

ll n, dp[1003][2003][2][2], k;

void add(ll &x, const ll &y) {
	x += y;
	if (x > MOD) x -= MOD;
	if (x < 0) x += MOD;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < 2; i++) {
		dp[1][1][i][i] = 1;
		dp[1][2][i][1 - i] = 1;
	}
	for (int i = 1; i < n; i++) 
	for (int j = 1; j <= k; j++) 
	for (int lst1 = 0; lst1 < 2; lst1++)
	for (int lst2 = 0; lst2 < 2; lst2++) {
		if (dp[i][j][lst1][lst2] == 0) continue;
		//cout << i << " " << j << " " << lst1 << " " << lst2 << '\n';
		for (int cur1 = 0; cur1 < 2; cur1++)
		for (int cur2 = 0; cur2 < 2; cur2++) {
			int newj = j;
			if (cur1 == cur2) {
				if (cur1 != lst1 && cur2 != lst2) newj ++;
			}
			else newj += (cur1 != lst1) + (cur2 != lst2);
			//if (j == 2) cout << cur1 << " " << cur2 << " " << newj << '\n';
			add(dp[i + 1][newj][cur1][cur2], dp[i][j][lst1][lst2]);
		}
	}
	ll res = 0;
	for (int lst1 = 0; lst1 < 2; lst1++)
	for (int lst2 = 0; lst2 < 2; lst2++) add(res, dp[n][k][lst1][lst2]);
	cout << res << '\n';
}