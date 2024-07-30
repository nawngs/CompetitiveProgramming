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

pii dis[203];

int res[203], n, ans[203][203];

vector < int > small, big;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) dis[i] = {0, i};
	for (int i = 2; i <= n; i++)
	for (int j = i + 1; j <= n; j++) {
		cout << 1 << " " << i << " " << j << '\n';
		int res; cin >> res;
		ans[i][j] = ans[j][i] = res;
		if (res != 1) dis[(res == i ? j : i)].fi ++;
	}
	sort(dis + 1, dis + n + 1, greater < pii >());
	int pos = dis[1].se;
	res[pos] = 1; res[1] = dis[1].fi + 2;
	for (int i = 2; i <= n; i++) if (i != pos) {
		if (ans[i][pos] == i) small.pb(i);
		else big.pb(i);
	}
	for (auto x : small) {
		int cnt = 0;
		for (auto y : small) if (x != y) cnt += (ans[x][y] == y);
		res[x] = res[1] - cnt - 1;
	}
	for (auto x : big) {
		int cnt = 0;
		for (auto y : big) if (x != y) cnt += (ans[x][y] == y);
		res[x] = res[1] + cnt + 1;
	}
	cout << "OK ";
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
}
