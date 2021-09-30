	#include <bits/stdc++.h>

	using namespace std;

	int n, k, f[100005], a[100005];

	int main() {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int j = 1; j <= k; j++) {
			for (int i = 1; i <= n; i++) {
				if (j < a[i]) continue;
				f[j] = (f[j] || !f[j - a[i]]);		
			}
		}
		//for (int i = 0; i <= k; i++) cout << f[i] << '\n';
		if (f[k] == 1) cout << "First" << '\n';
		else cout << "Second" << '\n';
	}