	#include <bits/stdc++.h>
	#define ll long long

	using namespace std;

	ll n, k, a[300005], cnt[1000005], f[1000005], dem = 0;

	int main() {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			cnt[a[i]] ++;
			if (a[i] > k) dem ++;
		}
		f[k] = dem;
		for (int i = k + 1; i <= 1e6; i++) {
			for (int j = i + k; j <= 1e6; j += i) f[j] += cnt[i] - (i == j);
		}
		for (int i = 1; i <= n; i++) cout << f[a[i]] << ' ';
	}