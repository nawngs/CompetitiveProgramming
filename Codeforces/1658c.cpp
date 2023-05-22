#pragma GCC optimize ("O2")
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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[100003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = a[1];
	for (int i = 2; i <= n + 1; i++) 
		if (a[i] - a[i - 1] > 1) {
			cout << "NO" << '\n';
			return ;
		}
	for (int i = 1; i <= n; i++) {
		if (a[i] == n && a[i + 1] != 1) {
			cout << "NO" << '\n';
			return ;
		}
	}
	int dem1 = 0, dem = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) dem1 ++;
		if (a[i] == n) dem ++;
	}
	if (dem1 > 1 || dem > 1 || dem1 == 0) {
		cout << "NO" << '\n';
		return ;
	}
	cout << "YES" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
