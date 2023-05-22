#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll a[5];

void sol() {
	cin >> a[1] >> a[2] >> a[3];
	sort(a + 1, a + 4);
	if (a[1] < 0 || a[3] != 90 || a[1] + a[2] != 90) cout << "NO" << '\n';
	else cout << "YES" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
