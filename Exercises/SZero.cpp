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

const string NAME = "SZero";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[30005];

bool check1() {
	int tam = 1e9;
	for (int i = 1; i < n; i++) {
		tam = min(tam, a[i]);
		if (a[i] > a[i + 1]) {
			if (tam >= a[i] - a[i + 1]) {
				tam -= a[i] - a[i + 1];
			}
			else return false;
		}
	}
	return true;
}

bool check2() {
	int tam = 1e9;
	for (int i = n; i > 1; i --) {
		tam = min(tam, a[i]);
		if (a[i] > a[i - 1]) {
			if (tam >= a[i] - a[i - 1]) {
				tam -= a[i] - a[i - 1];
			}
			else return false;
		}
	}
	return true;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (check1()) {
		cout << "YES" << '\n';
		return ;
	}
	if (check2()) {
		cout << "YES" << '\n';
		return ;
	}
	cout << "NO" << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
