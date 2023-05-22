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

int n, x, a[100003], s[200003], q;

void sol() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + (a[i] >= x);
	}
	cin >> q;
	ll dem = 0, r = n;
	while (q--) {
		int type;
		int y;
		cin >> type;
		if (type == 2) {
			dem ++;
			continue;
		}  
		cin >> y;
		if (type == 1) {
			r ++;
			s[r] = s[r - 1] + (y >= x);
		}
		else {
			//cout << y + 1 << " " << s[y + 1] << " " << s[dem] << '\n';
			cout << max(0, s[y + dem] - s[dem]) << '\n';
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
