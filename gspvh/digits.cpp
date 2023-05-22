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

const string NAME = "digits";
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

int a[30], b[30], n;


int main() {
	fast;
	fre();
	cin >> n;
	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 1; i <= n / 2; i++) {
		a[i] = 9;
		b[n - i + 1] = 9;
	}
	a[n / 2 + 1] = 1;
	b[1] = 1;
	for (int i = n / 2 + 2; i <= n; i++) {
		a[i] = 0;
		b[n - i + 2] = 0;
	}
	int res[30], remember = 0;//but remember_you = 1 :(
	for (int i = n; i >= 1; i--) {
		res[i] = a[i] - b[i] - remember;
		if (res[i] < 0) {
			res[i] += 10;
			remember = 1;
		}
		else remember = 0;
	}
	for (int i = 1; i <= n; i++) cout << res[i];
}
