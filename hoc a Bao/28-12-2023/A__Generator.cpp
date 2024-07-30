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
const int INF = 1e8;
const ll LINF = 1E18;
const int NMAX = 30;
const int N = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;


mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long get(long long l, long long r) {
    return l + (rd() % (r - l + 1));
}

void create() {
	int n = get(2, 10), m = get(1, 10);
	cout << n << " " << m << '\n';
	for (int i = 1; i <= n; i++) cout << get(1, 7) << ' ';
	cout << '\n';
	for (int i = 1; i <= m; i++) {
		int l = get(1, n - 1), r = get(l + 1, n), k = get(1, n);
		cout << l << " " << r << " " << k << '\n';
	}
}

int main() {
    //fast;
	int t = 5;
	cout << t << '\n';
	while (t--) create();
}