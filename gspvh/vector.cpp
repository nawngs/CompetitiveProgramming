#include <bits/stdc++.h>

#define name "vector"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, a[303], b[303];

void draw(int x, int y[]) {
	for (int i = 1; i <= x; i++) 
		cout << y[i] << " D" << '\n';
}

void win(int x, int y[]) {
	for (int i = 1; i <= x; i++) 
		cout << y[i] << " W" << '\n';
}

void lose(int x, int y[]) {
	for (int i = 1; i <= x; i++) 
		cout << y[i] << " L" << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << 6 * n + 4 * m << '\n';
	draw(n, a);
	win(n, a);
	draw(n, a);
	draw(n, a);
	win(n, a);
	draw(m, b);
	draw(m, b);
	win(m, b);
	lose(n, a);
	lose(m, b);
}