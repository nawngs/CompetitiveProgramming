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

struct Data {
	int x, y, index;
} a[1000003];

int n;

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].index = i;
		a[i].x /= 1000;
	}
	sort(a + 1, a + n + 1, [&](Data &x, Data &y) {
		return (x.x < y.x) || (x.x == y.x && (x.x % 2 == 0 ? x.y < y.y : x.y > y.y)); 
	});
	for (int i = 1; i <= n; i++) cout << a[i].index << " ";
}
