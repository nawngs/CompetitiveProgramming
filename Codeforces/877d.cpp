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

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, x1, y1, x2, y2, d[1003][1003];

char a[1003][1003];

struct Node {
	int x, y, Direction, len;
};

int main() {
	fast;
	//fre();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			cin >> a[i][j];
	cin >> x1 >> y1 >> x2 >> y2;
	memset(d, 255, sizeof(d));
	d[x1][y1] = 0;
	deque < Node > heap;
	heap.push_front({x1, y1, 10, 0});
	while (heap.size()) {
		auto u = heap.front(); heap.pop_front();
		int x = u.x, y = u.y, Direction = u.Direction, len = u.len;
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx < 1 || newy < 1 || newx > n || newy > m || a[newx][newy] == '#' || d[newx][newy] != -1) continue;
			if (i != Direction) {
				d[newx][newy] = d[x][y] + 1;
				heap.push_back({newx, newy, i, 1});
			}
			else {
				if (len + 1 <= k) {
					d[newx][newy] = d[x][y];
					heap.push_front({newx, newy, i, len + 1});
				}
				else {
					d[newx][newy] = d[x][y] + 1;
					heap.push_back({newx, newy, i, 1});
				}
			}
		}
	}
	if (d[x2][y2] == 22467) d[x2][y2] --;
	cout << d[x2][y2];
}
