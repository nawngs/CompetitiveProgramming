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

int a, b, x, y, n;

void sol() {
	cin >> a >> b >> x >> y;
	if ((a + b) % 2 != (x + y) % 2) {
		cout << -1 << '\n';
		return ;
	}
	if (a == x && b == y) {
		cout << 0 << '\n';
		return ;
	}
	if (abs(x - a) == abs(y - b)) {
		cout << 1 << '\n' << x << " " << y << '\n';
		return ;
	}
	int change_i = (x > a ? 1 : -1);
	int change_j = (2 * b > n ? -1 : 1);
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		int i = a + change_i * mid;
		int j = b + change_j * mid;
		//cout << mid << " " << i << " " << j << '\n';
		if (i < 1 || j < 1 || i > n || j > n || (x > a && i >= x) || (x < a && i <= x) || (y > b && j >= y) || (y < b && j <= y)) {
			r = mid - 1;
			continue;
		}
		//cout << mid << " " << i << " " << j << '\n';
		i = i + abs(y - j) * (i > x ? -1 : 1);
		//cout << mid << " " << i << '\n';
		if (i == x) {
			cout << 2 << '\n';
			cout << a + change_i * mid << " " << b + change_j * mid << '\n' << x << " " << y << '\n';
			return ;
		}
		if (a > x) {
			if (i < x) r = mid - 1;
			else l = mid + 1;
		}
		else {
			if (i < x) l = mid + 1;
			else r = mid - 1;
		}

	}
	
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> n >> t;
	while (t --) sol();
}
