#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

void sol() {
	ll n, m, k;
	cin >> n >> m >> k;
	k -= 2;
	if (m < n - 1 || m > n * (n - 1) / 2) {
		cout << "NO" << '\n';
		return ;
 	}
 	ll res;
 	if (n == 1) res = 0;
 	else if (n == 2) res = 1;
 		else if (m < n * (n - 1) / 2) res = 2;
 			else res = 1;
 	cout << (res <= k ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t --) sol();
}
