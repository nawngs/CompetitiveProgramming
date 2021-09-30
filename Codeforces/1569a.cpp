#include <bits/stdc++.h>

using namespace std;

int t, dem[55], cnt[55];

int main() {
	cin >> t;
	while (t --) {
		int n;
		string s;
		bool th = false;
		cin >> n >> s;
		s = ' ' + s;
		memset(dem, 0, sizeof(dem));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			dem[i] = dem[i - 1] + (s[i] == 'a');
			cnt[i] = cnt[i - 1] + (s[i] == 'b');
			//cout << i << " "
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (dem[j] - dem[i - 1] == cnt[j] - cnt[i - 1]) {
					cout << i << " " << j << '\n';
					th = true;
					break;
				}
			}
			if (th) break;
		}
		if (!th) cout << -1 << " " << -1 << '\n';
	}
}