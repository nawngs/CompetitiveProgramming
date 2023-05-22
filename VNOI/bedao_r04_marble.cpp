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

int a, b, x, y;

void sol() {
	cin >> a >> b >> x >> y;
	if (x == y) {
		cout << min(a, b) / x << '\n';
		return ;
	}
	if (x < y) swap(x, y);
	// x > y a > b
	int ans = 0;
	while (a != b) {	
		if (max(x, y) > max(a, b) || min(x, y) > min(a, b)) {
			cout << ans << '\n';
			return ;
		}
		if (a < b) swap(a, b);
		int tam = (a - b + x - y - 1) / (x - y);
		a -= tam * x;
		b -= tam * y;
		ans += tam;
	}
	ans += 2 * (a / (x + y));
	a %= (x + y);
	ans += a > x;
	cout << ans << '\n';

}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
