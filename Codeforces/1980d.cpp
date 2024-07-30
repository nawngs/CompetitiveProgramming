#include <bits/stdc++.h>

#define name ""
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
const int INF = 1e9;
const ll LINF = 1E18;
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[N + 3], b[N + 3];

bool check(int pos) {
	for (int i = 1; i <= n; i++) a[i] = b[i];
	a[pos] = a[pos + 1];
	int pre = 0;
	for (int i = 1; i < n; i++) {
		if (i == pos) continue;
		int cur = __gcd(a[i], a[i + 1]);
		if (cur < pre) return false;
		pre = cur;
	}
	return true;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int era = -1;
	for (int i = 2; i < n; i++) if (__gcd(a[i], a[i + 1]) < __gcd(a[i], a[i - 1])) {
		era = i;
		break;
	}
	if (era == -1) {
		cout << "YES" << '\n';
		return ;
	}
	if (check(era) || check(era - 1) || check(era + 1)) {
		cout << "YES" << '\n';
		return ;
	}
	cout << "NO" << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}