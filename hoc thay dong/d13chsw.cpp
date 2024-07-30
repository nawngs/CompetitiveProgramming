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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

string a, b;

void sol() {
	cin >> a >> b; n = a.size();
	a = ' ' + a; b = ' ' + b;
	int cnta, cntb1, dem10, dem01, total; cnta = cntb1 = dem10 = dem01 = total = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != '?') {
			if (a[i] == '1') cnta ++;
			if (a[i] != b[i]) {
				if (a[i] == '1') dem10 ++;
				else dem01 ++;
			}
		}
		else total ++;
		if (b[i] == '1') cntb1 ++; 
	}
	if (cnta > cntb1) {
		cout << -1 << '\n';
		return ;
	}
	cout << total + max(dem01, dem10) << '\n';
	
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}