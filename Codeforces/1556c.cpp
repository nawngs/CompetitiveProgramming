#include <bits/stdc++.h>

using namespace std;

long long n, a[1005], f[1005], g[1005], ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i += 2) {
		//long long pre = a[i];
		for (int j = i - 1; j > 0; j -= 2) {
			if (a[i] < a[j]) {
				f[i] += a[i];
				a[j] -= a[i];
				a[i] = 0;
				//cout << j << " " << i << " " << f[i] << '\n';
				break;
			}
			f[i] += a[j];	
			a[i] -= a[j];
			a[j] = 0;
			f[i] += g[j];
		}
		if (a[i] <= 0) g[i + 1] = 1;	
		ans += f[i];
	}
	cout << ans;
}