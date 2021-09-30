#include <bits/stdc++.h>

using namespace std;

int t, pos[200005], a[100005], n;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		pos[x] = i;
	} 
	pos[n * 2 + 2] = 1e9;
	for (int i = n * 2; i >= 2; i -= 2) pos[i] = min(pos[i], pos[i + 2]);
	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, i - 1 + pos[a[i] + 1] - 1);
	}
	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t --) sol();
}