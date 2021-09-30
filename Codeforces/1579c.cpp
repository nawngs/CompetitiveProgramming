#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

int n, m, k;
string s[15];
bool check[23][23];

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	memset(check, false, sizeof(check));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool th = true;
			for (int d = 0; d <= k; d++) {
				if (i - d < 1 || j - d < 1 || j + d > m || s[i - d][j - d] == '.' || (s[i - d][j + d] == '.')) {
					th = false;
					break;
				}
			}
			if (th == false) continue;
			int d = 0;
			while(1) {
				if (i - d < 1 || j - d < 1 || j + d > m || s[i - d][j - d] == '.' || (s[i - d][j + d] == '.')) {
					break;
				}
				check[i - d][j - d] = true;
				check[i - d][j + d] = true;
				d ++;
			}
		}
	}
			//cout << i << " " << j << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j] == false && s[i][j] == '*') {
				//cout << i << " " << j << " " << check[i][j] << '\n';
				cout << "NO" << '\n';
				return ;
			}
		}
	}
	cout << "YES" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t --) sol();
}
