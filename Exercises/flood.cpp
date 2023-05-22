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

const string NAME = "flood";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int x[4] = {-1, 0, 0, 1};
const int y[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	int x, y;
	Data (int _x, int _y) : x(_x), y(_y) {};
};


int n, m, k, water_reach[1003][1003], raft[1003][1003];

string s[1003];

pii home, shop;

deque < pii > dq;


void dfs1() {
	queue < pii > que;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'S') {
				que.push({i, j});
				water_reach[i][j] = 1;
			}
			else water_reach[i][j] = INF;
		}
	}
	while (que.size()) {
		auto u = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int newx = u.fi + x[i];
			int newy = u.se + y[i];
			if (newx > n || newx == 0 || newy > m || newy == 0) continue;
			pii tam = {newx, newy};
			if (water_reach[newx][newy] == INF && tam != home && tam != shop) {
				water_reach[newx][newy] = water_reach[u.fi][u.se] + 1;
				que.push({newx, newy});
			}
		}
	}

}

bool dfs(int time_st) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) raft[i][j] = -1;
	raft[home.fi][home.se] = k;

	dq.push_front({home.fi, home.se});
	while(dq.size()) {
		auto u = dq.front();
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int newx = u.fi + x[i];
			int newy = u.se + y[i];
			if (newx > n || newx == 0 || newy > m || newy == 0) continue;
			int w = 0;
			if (water_reach[newx][newy] <= time_st) w = 1;
			if (raft[newx][newy] < raft[u.fi][u.se] - w) {
				raft[newx][newy] = raft[u.fi][u.se] - w;
				if (w == 0) dq.push_front({newx, newy});
				else dq.push_back({newx, newy});
			}
		}
	}
	return raft[shop.fi][shop.se] >= 0;
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'H') home = {i, j};
			if (s[i][j] == 'G') shop = {i, j};
		}
	}
	dfs1();
	if (abs(shop.fi - home.fi) + abs(shop.se - home.se) - 1 <= k) {
		cout << -1 << '\n';
		return ;
	}
	int l = 0, r = 1e5, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (dfs(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << (ans == 1e5 ? -1 : ans);	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
