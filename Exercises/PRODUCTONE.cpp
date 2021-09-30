#include <bits/stdc++.h>

using namespace std;

int n, a[100005], dem = 0;

long long ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			ans += -1 - a[i];
			dem ++;
		}
		else ans += abs(a[i] - 1);
	}
	if (dem % 2 == 1) ans += 2;
	cout << ans;
}