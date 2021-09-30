#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll n, k, cnt[5][3000005], s[5][3000005];

void sol() {
	int l = 3, r = 3 * n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (s[3][mid] >= k) {
			ans = mid;
			r = mid - 1;
		} 
		else l = mid + 1;
	}
	k = k - s[3][ans - 1];
	int fi, sum = 0;
	for (int i = 1; i <= n; i++) {
		if (ans - i > 2 * n) continue;
		sum += cnt[2][ans - i];
		if (sum >= k) {
			fi = i;
			k -= (sum - cnt[2][ans - i]);
			break;
		} 
	}
	cout << fi << ' ';
	for (int i = 1; i <= n; i++) {
		if (ans - fi - i > n) continue;
		cout << i + k - 1 << " " << ans - fi - (i + k - 1) << '\n';
		return ;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("sorttuple3.inp", "r", stdin);
	//freopen("sorttuple3.out", "w", stdout);
	cin >> n >> k;
	//n = 1e6;
	//k = 1e18;
	for (int i = 1; i <= n; i++) cnt[1][i] = s[1][i] = 1;
	for (int i = 2; i <= 3; i++) {
		ll sum = 0;
		for (int j = 1; j <= i * n; j++) {
			if (j < i) cnt[i][j] = 0;
			else {
				cnt[i][j] += sum;
				s[i][j] = s[i][j - 1] + sum;
				if (j >= n) sum -= cnt[i - 1][j - n];
			}
			sum += cnt[i - 1][j];
			//cout << i << " " << j << " " << s[i][j] << '\n';
		}
	}
	sol();
}