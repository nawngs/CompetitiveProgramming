#include <bits/stdc++.h>

using namespace std;

int t, n, a[105];

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

int main() {
	cin >> t;
	//cout << getbit(5, 32) << '\n';
	while (t --) {
		cin >> n;
		int cnt[35];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			for (int j = 0; j <= 30; j++) {
				cnt[j] += getbit(a[i], j);

			}
		}
		int ans = 0;
		for (int i = 0; i <= 30; i++) if(cnt[i] == n) ans += (1 << i);
		cout << ans << '\n';
	}
}