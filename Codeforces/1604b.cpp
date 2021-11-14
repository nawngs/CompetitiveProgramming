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
const ll ESP = 1e-9;
const int INF = 1e9;
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, x, pre, t;

bool th;

void sol() {
	cin >> n;
	th = false;
	pre = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x <= pre) th = true;
		pre = x;
	}
	if (n % 2 == 0) {
		cout << "YES" << '\n';
		return ;
	}
	if (th) {
		cout << "YES" << '\n';
		return ;
	}
	else {
		cout << "NO" << '\n';
		return ;
	}
}

int main() {
	fast;
	//fre();
	cin >> t;
	while (t --) sol();
}
