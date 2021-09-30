#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll t, n, f[nmax + 5], demf;

bool check[nmax + 5];

vector < ll > prime;

void sang() {
	for (int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++) 
		if (check[i]) for (int j = i * i; j <= nmax; j += i) check[j] = false;

	for (int i = 1; i <= nmax; i++) if (check[i]) prime.push_back(i);
}

void sol() {
	ll l = 1, r = demf, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (f[mid] <= n) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << n - f[ans] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	sang();
	for (int i = 1; i < prime.size(); i++) f[++ demf] = prime[i] * prime[i - 1];
	cin >> t;
	while (t --) {
		cin >> n;
		sol();
	}
}
