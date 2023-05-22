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
	ll x, w, i;
} a[200003], b[200003];

ll n, m;

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].w;
		a[i].i = i;
	}
	sort(a + 1, a + m + 1, [](Data &x, Data &y) {
		return x.w < y.w;
	});
	ll res = 0;
	for (int i = 1; i <= 2 * n; i++) {
		res += a[i].w;
		b[i] = a[i];
	}
	sort(b + 1, b + 2 * n + 1, [](Data &x, Data &y) {
		return x.x < y.x;
	});
	cout << res << '\n';
	for (int i = 1; i <= n; i++) cout << b[i].i << " " << b[2 * n - i + 1].i << '\n';
	
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
