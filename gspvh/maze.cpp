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

const string NAME = "maze";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const int num[4] = {'y', 'r', 'g', 'b'};
void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

char a[103][103];

int r, c, d[103][103][16];

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

int main() {
	fast;
	fre();
	cin >> r >> c;	
	pii st;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> a[i][j];
			if (a[i][j] == '*') {
				st.fi = i;
				st.se = j;
			}
		}
	}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			for (int k = 0; k < 16; k++) d[i][j][k] = INF;
	d[st.fi][st.se][0] = 0;
	queue < piii > que;
	que.push({st, 0});
	while (que.size()) {
		auto u = que.front();
		que.pop();
		//cout << u.fi.fi << " " << u.fi.se << " " << u.se << '\n'; 
		for (int i = 0; i < 4; i++) {
			int x = u.fi.fi + dx[i], y = u.fi.se + dy[i];
			if (x < 1 || x > r || 1 < 1 || y > c || a[x][y] == '#') continue;
			if (a[x][y] == '.' || a[x][y] == 'X' || a[x][y] == '*') {
				if (d[x][y][u.se] == INF) {
					d[x][y][u.se] = d[u.fi.fi][u.fi.se][u.se] + 1;
					que.push({{x, y}, u.se});
				}
			}
			if ('a' <= a[x][y] && a[x][y] <= 'z') {
				int newbit = u.se;
				for (int i = 0; i < 4; i++) {
					if (num[i] == a[x][y]) {
						newbit = (newbit | (1 << i));
						break;
					}
				}
				if (d[x][y][newbit] == INF) {
					d[x][y][newbit] = d[u.fi.fi][u.fi.se][u.se] + 1;
					que.push({{x, y}, newbit});
				}
			}
			if ('A' <= a[x][y] && a[x][y] <= 'Z') {
				for (int i = 0; i < 4; i++) {
					if (num[i] - 32 == a[x][y]) {
						if (getbit(u.se, i)) {
							if (d[x][y][u.se] == INF) {
								d[x][y][u.se] = d[u.fi.fi][u.fi.se][u.se] + 1;
								que.push({{x, y}, u.se});
							}
						}
					}
				}
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			if (a[i][j] == 'X') {
				for (int bit = 0; bit < 16; bit++) ans = min(ans, d[i][j][bit]);
			}
		}
	if (ans == INF) cout << "The poor student is trapped!";
	else cout << "Escape possible in " << ans << " steps.";
}
