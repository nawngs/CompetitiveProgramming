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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
    return l + (rd() % (r - l + 1));
}

int a[103], n;

void sol() {
	int n = get_random(1, 100), m = get_random(1, 20), k = 0;		
	for (int i = 1; i <= n; i++) {
		a[i] = get_random(0, 1);
		k += !a[i];
	}
	for( int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << '\n';
	cout << n << " " << m << " " << k << '\n';
	for (int i = 1; i <= m; i++) {
		int l = get_random(1, n - 1), r = get_random(l + 1, n);
		cout << l;
		if (a[l] == a[r]) cout << " = ";
		if (a[l] > a[r]) cout << " > ";
		if (a[l] < a[r]) cout << " < ";
		cout << r << '\n';
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t = get_random(1, 5);
	cout << t << '\n'; while (t --) sol();
}