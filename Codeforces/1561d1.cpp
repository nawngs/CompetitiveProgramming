#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll n, m, f[200005], pre[200005], sumf = 1, dem = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	f[1] = 1;
	f[1] %= m;
	for (int i = 2; i <= n; i++) {
		f[i] = sumf;
		f[i] %= m;
		int pre = i;
		int pre2 = 1;
		for (int j = 1; j * j <= i; j++) {
			dem ++;
			int l = i / (j + 1);
			int r = i / (i / j) - 1;
			//cout << pre << " " << l << '\n';
			f[i] += (f[j] * (pre - l)) % m;
			pre = l;
			f[i] %= m;
			f[i] += (f[i / j] * (r - pre2)) % m;
			f[i] %= m;
			pre2 = r;

		}
		sumf += f[i];
		sumf %= m;
		//if (i == 2) cout << f[i] << '\n';
		//cout << i << " " << f[i] << '\n';

	}
	//cout << dem << '\n';
	cout << f[n];
}
