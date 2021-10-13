#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll x, y, f[100005];

void sol() {
	cin >> x >> y;
	memset(f, 255, sizeof(f));
	f[x] = 0;
	queue < int > que;
	que.push(x);
	while (que.size()) {
		int tam = que.front();
		que.pop();
		//cout << tam << '\n';
		if (tam * 2 <= 100005 && f[tam * 2] == -1) {
			que.push(tam * 2);
			f[tam * 2] = f[tam] + 1;
		}
		if (tam + 1 <= 1e6 && f[tam + 1] == -1) {
			que.push(tam + 1);
			f[tam + 1] = f[tam] + 1;
		}
		if (tam - 1 >= 0 && f[tam - 1] == -1) {
			que.push(tam - 1);
			f[tam - 1] = f[tam] + 1;
		}
	}
	cout << f[y] << '\n';
}

int main() {
	fastflow;
	freopen("XY.INP", "r", stdin);
	freopen("XYtrau.OUT", "w", stdout);	
	int t = 2;
	while (t --) sol();
}
