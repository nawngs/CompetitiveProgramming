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

const string NAME = "moveboard";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int changex[2] = {0, 1};
const int changey[2] = {1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m;

bool th[1003][1003], visit[1003][1003];

char ans[2003], s[1003][1003];

void bfs1() {
	memset(th, false, sizeof(th));
	th[n][m] = 1;
	queue < pii > que;
	que.push({n, m});
	while (que.size()) {
		auto u = que.front();
		que.pop();	
		for (int i = 0; i < 2; i++) {
			int newx = u.fi - changex[i];
			int newy = u.se - changey[i];
			if (newx <= 0 || newy <= 0 || th[newx][newy] || s[newx][newy] == '#') continue;
			th[newx][newy] = 1;
			que.push({newx, newy});
		}
	}
} 

void bfs() {
	for (int i = 1; i <= n + m; i++) ans[i] = '}';
	ans[1] = s[1][1];
	visit[1][1] = 1;
	queue < pii > que;
	que.push({1, 1});
	while (que.size()) {
		auto u = que.front();
		que.pop();
		if (s[u.fi][u.se] != ans[u.fi + u.se - 1]) continue;
		for (int i = 0; i < 2; i++) {
			int newx = u.fi + changex[i];
			int newy = u.se + changey[i];
			if (newx > n || newy > m || s[newx][newy] == '#' || !th[newx][newy] || visit[newx][newy]) continue;
			if (s[newx][newy] <= ans[newx + newy - 1]) {
				ans[newx + newy - 1] = s[newx][newy];
				visit[newx][newy] = 1;
				que.push({newx, newy});
			}
		}
	}
}

void bfs2() {
	for (int i = 1; i <= n + m; i++) ans[i] = '#';
	memset(visit, false, sizeof(visit));
	ans[1] = s[1][1];
	visit[1][1] = 1;
	queue < pii > que;
	que.push({1, 1});
	while (que.size()) {
		auto u = que.front();
		que.pop();
		if (s[u.fi][u.se] != ans[u.fi + u.se - 1]) continue;
		for (int i = 0; i < 2; i++) {
			int newx = u.fi + changex[i];
			int newy = u.se + changey[i];
			if (newx > n || newy > m || s[newx][newy] == '#' || !th[newx][newy] || visit[newx][newy]) continue;
			if (s[newx][newy] >= ans[newx + newy - 1]) {
				ans[newx + newy - 1] = s[newx][newy];
				visit[newx][newy] = 1;
				que.push({newx, newy});
			}
		}
	}
} 

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> s[i][j];
	bfs1();
	if (!th[1][1]) {
		cout << -1;
		return ;
	}
	bfs();
	for (int i = 1; i < n + m; i++) cout << ans[i];
	cout << '\n';
	bfs2();
	for (int i = 1; i < n + m; i++) cout << ans[i];
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
