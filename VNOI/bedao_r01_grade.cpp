#include <bits/stdc++.h>

using namespace std;

int n, q, res[1000005], pre[1000005], dem[1000005];

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			if (pre[x] == i) continue;
			if (pre[x] == i - 1) dem[x] ++;
			else {
				res[x] = max(res[x], dem[x]);
				dem[x] = 1;
			}
			pre[x] = i;
		}
	}
	for (int i = 1; i <= 1000000; i++) res[i] = max(res[i], dem[i]);
	while (q --) {
		int x;
		cin >> x;
		cout << res[x] << '\n';
	}
}