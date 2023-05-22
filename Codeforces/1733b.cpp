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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, x, y;

void sol() {
	cin >> n >> x >> y;
	if (x == 0) swap(x, y);
	if ((x != 0 && y != 0) || (x == 0 && y == 0)) {
		cout << -1 << '\n';
		return ;
	}
	if ((n - 1) % x != 0) {
		 cout << -1 << '\n';
		 return ;
	}
	int cur = 1, val = x;
	for (int i = 2; i <= n; i++) {
		cout << cur << ' ';
		val --;
		if (val == 0) {
			cur = i + 1;
			val = x;
		}
	}
	cout << '\n';	
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
