#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < short int, short int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "hanoi";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const short int dx[4] = {-1, 0, 0, 1};
const short int dy[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

short int r, c, newx, newy;
int k, cnt, ans = 0;

vector < vector < char > > s;

vector < vector < bool > > visited;

vector < pair < int, pii > > res;

void bfs(short int x,short int y) {
	if (visited[x][y]) return ;
	visited[x][y] = 1;
	for (short int i = 0; i < 4; i++) {
		newx = x + dx[i];
		newy = y + dy[i];
		if (newx < 0 || newx >= r || newy < 0 || newy >= c || s[newx][newy] == '#') continue;
		bfs(newx, newy);
	}
}

void bfs_calc(short int x,short int y) {
	if (visited[x][y]) return ;
	visited[x][y] = 1;
	cnt ++;
	for (short int i = 0; i < 4; i++) {
		newx = x + dx[i];
		newy = y + dy[i];
		if (newx < 0 || newx >= r || newy < 0 || newy >= c || s[newx][newy] == '#') continue;
		bfs_calc(newx, newy);
	}
}

void bfs_change(short int x,short int y) {
	s[x][y] = '#';
	for (short int i = 0; i < 4; i++) {
		newx = x + dx[i];
		newy = y + dy[i];
		if (newx < 0 || newx >= r || newy < 0 || newy >= c || s[newx][newy] == '#') continue;
		bfs_change(newx, newy);
	}
}

void sol() {
	cin >> r >> c >> k;
	s.resize(r);
	visited.resize(r);
	for (short int i = 0; i < r; i++) {
		s[i].resize(c);
		visited[i].resize(c);
	}
	for (short int i = 0; i < r; i++) 
		for (short int j = 0; j < c; j++) cin >> s[i][j];
	for (short int j = 0; j < c; j++) {
		if (s[0][j] == '.') bfs(0, j);
		if (s[r - 1][j] == '.') bfs(r - 1, j);
	}
	for (short int i = 0; i < r; i++) {
		if (s[i][0] == '.') bfs(i, 0);
		if (s[i][c - 1] == '.') bfs(i, c - 1);
	}
	for (short int i = 1; i < r - 1; i++) {
		for (short int j = 1; j < c - 1; j++) {
			if (s[i][j] == '.' && !visited[i][j]) {
				cnt = 0;
				bfs_calc(i, j);
				res.push_back({cnt, {i, j}});
			}
		}
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size() - k; i++) {
		ans += res[i].fi;
		bfs_change(res[i].se.fi, res[i].se.se);
	}
	cout << ans << '\n';
	for (short int i = 0; i < r; i++) {
		for (short int j = 0; j < c; j++) cout << s[i][j];
		cout << '\n';
	}
}

int main() {
	fast;
	fre();
	sol();
}