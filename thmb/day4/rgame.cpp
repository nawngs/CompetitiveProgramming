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

bool check(int n) {
	while (n % 2 == 0) n /= 2;
	return (n == 1);
}

int main() {
	int n;
	cin >> n;
	if (check(n)) {
		cout << 0 << '\n';
		while (n != 0) {
			int x;
			cin >> x;
			n -= x;
			int dem = 0;
			int tam = n;
			while (tam % 2 == 0) {
				dem ++;
				tam /= 2;
			}
			cout << (1 << dem) << '\n';
			n -= (1 << dem);
		}
		return 0;
	}
	while (n > 0) {
		int dem = 0;
		int tam = n;
		while (tam % 2 == 0) {
			dem ++;
			tam /= 2;
		}
		cout << (1 << dem) << '\n';
		n -= (1 << dem);
		if (n == 0) return 0;
		int x;
		cin >> x;
		n -= x;
	}
	return 0;
}
