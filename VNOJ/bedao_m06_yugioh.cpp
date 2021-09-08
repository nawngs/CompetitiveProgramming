#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int nmax = 1e6;

ll n, x, a[1000005], cnt[1000005], dem = 0, ans = 1e9;

bool f[nmax + 7];

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = true;
	f[1] = f[0] = false;
	for (int i = 2; i * i <= nmax; i++) 
		if (f[i]) for (int j = i * i; j <= nmax; j += i) f[j] = false;
}

int main() {
	sang();
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[i] = cnt[i - 1];
		if (a[i] > 0 && a[i] < x && f[a[i]]) {
			cnt[i] ++;
			dem ++;
		}
		//cout << i << " " << cnt[i] << '\n';
	}
	for (int i = dem; i <= n; i++) {
		ans = min(ans, dem - cnt[i] + cnt[i - dem]);
	}
	cout << ans;
}
