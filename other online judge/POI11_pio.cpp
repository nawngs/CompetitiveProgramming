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
const int NMAX = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 19;

ll n, a[NMAX + 3], pre[NMAX + 3], suff[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; i + j * j + 1 <= n; j++) 
			pre[i + j * j + 1] = max(pre[i + j * j + 1], a[i] + j + 1);
		for (int j = 0; i - j * j - 1 >= 1; j++)
			suff[i - j * j - 1] = max(suff[i - j * j - 1], a[i] + j + 1);
	}
	for (int i = 1; i <= n; i++) pre[i] = max(pre[i], pre[i - 1]);
	for (int i = n; i >= 1; i--) suff[i] = max(suff[i], suff[i + 1]);
	for (int i = 1; i <= n; i++) cout << max(0ll, max(pre[i], suff[i]) - a[i]) << '\n';
}