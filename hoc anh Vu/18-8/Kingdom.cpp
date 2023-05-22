#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < pii, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[2003][2003], vs[2003][2003];

bool check(int x) {
	int mina = INF, maxa = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			mina = min(mina, a[i][j]);
			maxa = max(maxa, a[i][j]);
		}
	if (maxa - mina <= x) return true;
	queue < piii > que;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == mina) {
				vs[i][j] ++;
				que.push({{i, j}, 1});
			}
		}
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	int l = 0, r = 1e9, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}
