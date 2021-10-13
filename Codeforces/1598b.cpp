#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, a[1005][7];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= 5; j++) cin >> a[i][j];

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i == j) continue;
			int s1 = 0, s2 = 0, cnt = 0;
			for (int k = 1; k <= n; k++) {
				if (a[k][i] == 1 && a[k][j] == 0) {
					s1 ++;
					continue;
				}
				if (a[k][i] == 0 && a[k][j] == 1) {
					s2 ++;
					continue;
				}
				if (a[k][i] == a[k][j] && a[k][i] == 1) {
					cnt ++;
					continue;
				}
			}
			if (max(0, (n / 2) - s2) + max(0, (n / 2) - s1) <= cnt) {
				cout << "YES" << '\n';
				return ;
			} 
		}
	}
	cout << "NO" << '\n';
	return ;
}

int main() {
	fastflow;
	int t;
	cin >> t;
	while (t --) sol();
}