#include <bits/stdc++.h>

#define name "gotoschool"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < pii, int >
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
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int n, m, k, d[2003][2003][4];

bool a[2003][2013];

string s;

pii h, school, trace[2003][2003][4];

map < char, int > meaning;

bool minimize(int &x, int y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

bool check(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == 0);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	for (int i = 0; i <= 9; i++) {
		char c = i + '0';
		meaning[c] = i;
	}
	for (int i = 0; i <= 'z' - 'a'; i++) {
		char C = i + 'A', c = i + 'a';
		meaning[C] = 10 + i, meaning[c] = 36 + i;
	}
	meaning['#'] = 62; meaning['$'] = 63;
	
	cin >> n >> m >> k >> h.fi >> h.se >> school.fi >> school.se;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int j = 0;
		for (auto c : s) {
			int val = meaning[c];
			for (int p = 0; p < 6; p++) a[i][++ j] = (val >> p & 1);
		}
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
	for (int dir = 0; dir < 4; dir++) d[i][j][dir] = INF;
	deque < piii > dq;
	for (int dir = 0; dir < 4; dir++) {
		d[h.fi][h.se][dir] = 0;
		dq.pb({h, dir});
	}
	while(!dq.empty()) {
		auto u = dq.front(); dq.pop_front();
		int i = u.fi.fi, j = u.fi.se, dir = u.se;
		// cout << i << " " << j << " " << dir << " " << d[i][j][dir] << '\n';
		int newi = i + dx[dir], newj = j + dy[dir];
		if (check(newi, newj) && minimize(d[newi][newj][dir], d[i][j][dir])) {
			trace[newi][newj][dir] = trace[i][j][dir];
			dq.push_front({{newi, newj}, dir});
		}
		for (int newd = 0; newd < 4; newd++) {
			newi = i + dx[newd], newj = j + dy[newd];
			if (check(newi, newj) && minimize(d[newi][newj][newd], d[i][j][dir] + 1)) {
				// cout << newi << " " << newj << " " << newd << " " <<d[newi][newj][newd] << " " << d[i][j][dir] + 1 << '\n';
				trace[newi][newj][newd] = {i, j};
				dq.push_back({{newi, newj}, newd});
			}
		}
	}
	int dir = 0;
	for (int i = 0; i < 4; i++) if (d[school.fi][school.se][i] < d[school.fi][school.se][dir]) dir = i;
	if (d[school.fi][school.se][dir] > k) {
		cout << -1 << '\n';
		return 0;
	}
	cout << d[school.fi][school.se][dir] << '\n';
	vector < pii > res;
	while (1) {
		res.pb(school);
		if (d[school.fi][school.se][dir] == 0) break;
		int cur = d[school.fi][school.se][dir] - 1;
		school = trace[school.fi][school.se][dir];
		for (int newd = 0; newd < 4; newd++) if (d[school.fi][school.se][newd] == cur) {
			dir = newd;
			break;
		}
	}
	res.pb(h);
	reverse(res.begin(), res.end());
	for (auto x : res) cout << x.fi << " " << x.se << '\n';
}