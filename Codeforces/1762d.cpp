#include <bits/stdc++.h>

#define name ""
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

int n;

int ask(int u, int v) {
	cout << "? " << u << " " << v << '\n';
	int ans; cin >> ans;
	return ans;
}

void solve(int a, int b, int c) {
	if (c == n + 1) {
		cout << "! " << a << " " << b << '\n';
		int res; cin >> res;
		return ;
	}
	int x1 = ask(a, c), x2 = ask(b, c);
	if (x1 == x2) return solve(a, b, c + 1);
	if (x1 > x2) return solve(a, c, c + 1);
	return solve(b, c, c + 1);
}

void sol() {
	cin >> n;
	solve(1, 2, 3);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}