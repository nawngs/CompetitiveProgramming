#include <bits/stdc++.h>

#define name ""
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

int n, a[503], cnt[503][503], b[503];

void sol() {
	cin >> n;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) 
			cnt[i][j] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1) 
			cnt[a[i - 1]][a[i]] ++, cnt[a[i]][a[i - 1]] ++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (i > 1)
			cnt[b[i - 1]][b[i]] --, cnt[b[i]][b[i - 1]] --;
	}
	if (a[1] != b[1] || a[n] != b[n]) {
		cout << "NO" << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (cnt[i][j] != 0) {
				cout << "NO" << '\n';
				return ;
			}
		}
	cout << "YES" << '\n';


}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}