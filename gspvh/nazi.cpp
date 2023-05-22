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
const ll ESP = 1e-9;
const ll INF = 1e18;
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

int n, r, c, x, y, f[103][103];

void sol() {
	cin >> r >> c >> n;
	queue < piii > que;	
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		f[x][y] = 1;
		que.push({{x, y}, 1});
	}
	int res = 0;
	while (que.size()) {
		auto u = que.front();
		res = max(res, u.se);
		que.pop();
		for (int i = 0; i < 4; i++) {
			int newx = u.fi.fi + dx[i];
			int newy = u.fi.se + dy[i];
			if (newx < 1 || newx > r || newy < 1 || newy > c || f[newx][newy] != 0) continue;
			f[newx][newy] = u.se + 1;
			que.push({{newx, newy}, u.se + 1});
		}
	}
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
