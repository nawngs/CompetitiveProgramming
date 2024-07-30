#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 5e4;
const ll LINF = 1E18;
const ll NMAX = 1e6;
const int N = 200;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;


mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long get(long long l, long long r) {
    return l + (rd() % (r - l + 1));
}

int main() {
	fast;
	//int t; cin >> t; while (t --) sol();
	for (int tt = 1; tt <= 1; tt++) {
		// string cc = to_string(tt);
		// string name = "test"; name += cc; name += ".txt";
		// ofstream inp(name);
		int k;
		int n = get(5, 15), m = get(5, 15);
		k = 2;
		cout <<  k << '\n';
		for (int i = 1; i <= n; i++) cout <<  (get(0, 1) ? "B" : "R");
		cout <<  '\n';
		for (int i = 1; i <= m; i++) cout << "B";
		cout <<  '\n';
	}
}