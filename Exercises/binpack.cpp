#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "binpack";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, l, a[1000003];

void minimize(int &x, int y) {
	x = min(x, y);
}

void minimize_pair(pair < int, int > &x, int cnt, int k) {
	if (x.fi > cnt) {
		x = {cnt, k};
	}
	else if(x.fi == cnt) x.se = min(x.se, k);
}

namespace sub1 {
	int f[23], ans;
	void backtrack(int pos) {
		for (int i = 1; i <= 2; i++) {
			f[pos] = i;
			if (pos == n) {
				int sum1 = 0, sum2 = 0, cnt = 0;
				for (int j = 1; j <= n; j++) {
					//cout << j << " " << f[j] << '\n';
					if (f[j] == 1) {
						if (sum1 + a[j] > l) {
							cnt ++;
							sum1 = a[j];
						}
						else sum1 += a[j];
					}
					else {
						if(sum2 + a[j] > l) {
							cnt ++;
							sum2 = a[j];
						}
						else sum2 += a[j];
					}
				}
				if (sum1 != 0) cnt ++;
				if (sum2 != 0) cnt ++;
				ans = min(ans, cnt);
			}
			else backtrack(pos + 1);
		}
	}

	void solve() {
		ans = n;
		memset(f, 255, sizeof(f));
		backtrack(1);
		cout << ans << '\n';
		return ;
	}
}

namespace sub2 {
	void solve() {
		int ans = 0, Box1 = 0, Box2 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				if (Box1 < l && Box1 % 2 != l % 2) Box1 ++;
				else if (Box2 < l && Box2 % 2 != l % 2) Box2 ++;
				else if (Box1 < l) Box1 ++;
				else if (Box2 < l) Box2 ++;
				else {
					ans ++;
					Box1 = 1; 
				}
			}
			else {
				if (Box1 < l - 1 && Box1 % 2 == l % 2) Box1 += 2;
				else if (Box2 < l - 1 && Box2 % 2 == l % 2) Box2 += 2;
				else if (Box1 < l - 1) Box1 += 2;
				else if (Box2 < l - 1) Box2 += 2;
				else if (Box1 > Box2) {
					ans ++;
					Box1 = 2;
				}
				else {
					ans ++;
					Box2 = 2;
				}
			}	
		}
		if (Box1 != 0) ans ++;
		if (Box2 != 0) ans ++;
		cout << ans << '\n';
	}
}

namespace sub345 {
	pair < int, int > p[10002][5002];
	void solve() {
		for (int i = 1; i <= n; i++) 
			for (int j = 0; j <= l; j++) p[i][j] = {INF, INF};
		p[1][a[1]] = {0, 0};
		p[1][0] = {0, a[1]};
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= l; j++) {
				int cnt = p[i][j].fi;
				int k = p[i][j].se;
				if (cnt == INF || k == INF) continue;
				//cout << i << " " << j << " " << k << " " << cnt << '\n';
				minimize_pair(p[i + 1][a[i + 1]], cnt + 1, k);
				if (j + a[i + 1] <= l) minimize_pair(p[i + 1][j + a[i + 1]], cnt, k);
				minimize_pair(p[i + 1][j], cnt + 1, a[i + 1]);
				if (k + a[i + 1] <= l) minimize_pair(p[i + 1][j], cnt, k + a[i + 1]);
			}
		}
		int ans = INF;
		for (int j = 0; j <= l; j++) {
			ans = min(ans, p[n][j].fi + (j != 0) + (p[n][j].se != 0));
		}
		cout << ans << '\n';
		return ;
	}
}

int main() {
	fast;
	//fre();
	cin >> l >> n;
	bool IsSub2 = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 2) 
			IsSub2 = false;
	}
	if (n <= 20) {
		sub1::solve();
		return 0;
	}
	if (IsSub2) {
		sub2::solve();
		return 0;
	}
	sub345::solve();
	// anh yeu em vai lone
}
