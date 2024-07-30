//[FINISHED]
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
const int NMAX = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, val[NMAX + 3], cnt[NMAX + 3], l[NMAX + 3];

vector < pii > a[NMAX + 3];

vector < int > b[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= k; i++) a[i].resize(n + 1);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= k; j++) {
			cin >> a[j][i].fi;
			a[j][i].se = i;
		}
	for (int i = 1; i <= n; i++) {
		b[i].resize(k + 1);
		for (int j = 1; j <= k; j++) cin >> b[i][j];
	}
	for (int j = 1; j <= k; j++) {
		sort(a[j].begin(), a[j].end());
		l[j] = 1;
	}
	int res = 0;
	queue < int > que;
	while(1) {
		bool ok = false;
		for (int j = 1; j <= k; j++) {
			while (l[j] <= n && val[j] >= a[j][l[j]].fi) {
				if (++cnt[a[j][l[j]].se] == k) que.push(a[j][l[j]].se);
				l[j] ++;
			}
		}
		while (!que.empty()) {
			int id = que.front(); que.pop();
			ok = true; res ++;
			for (int j = 1; j <= k; j++) val[j] += b[id][j];
		}
		if (!ok) break;
	}
	cout << res;
}