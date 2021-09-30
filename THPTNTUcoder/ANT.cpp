#include <bits/stdc++.h>

using namespace std;

int n, x, a[100005];

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, [](int x, int y) {
		return abs(x) < abs(y);
	});
	
}