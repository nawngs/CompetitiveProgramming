#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

const int a[9] = {5, 10, 1, 2, 4, 8, 16, 7, 14};

void sol() {
	ll x;
	cin >> x;
	if (x == 1) {
		cout << 50 << '\n';
		return ;
	}
	x -= 1;
	x %= 9;
	if (x == 0) x = 9;
	cout << a[x - 1] << '\n';

}

int main() {
	slow;
	int t;
	cin >> t;
	while (t --) sol();
}
