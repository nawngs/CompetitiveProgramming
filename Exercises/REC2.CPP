#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() {
	cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += min(n - i + 1, k);
	cout << ans;
}