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
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, x, m;

ld b[N + 3];

void sol() {
	setprecision(20);
	cin >> n;
	bool ok = 1, th = 1;
	m = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x != 1) th = 0;
		if (!th && x == 1) ok = 0;
		if (x != 1) b[++ m] = log2(log2(x));
	}
	if (!ok) {
		cout << -1 << '\n';
		return ;
	}
	ll res = 0;
	for (int i = 2; i <= m; i++) if (b[i] < b[i - 1]) {
		ld rem = b[i - 1] - b[i];
		if (rem > EPS) {
			int add = 1 + (rem - EPS) / 1;	
			res += add;
			b[i] += add;
		}
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}