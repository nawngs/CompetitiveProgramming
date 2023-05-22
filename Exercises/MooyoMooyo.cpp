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

const string NAME = "mooyomooyo";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, dem = 0;

string s[103];

bool th, visited[103][12];

vector < pii > pos;

void change() {
	for (int i = n; i >= 2; i--)
		for (int j = 1; j <= 10; j++) {
			if (s[i][j] == '0') {
				for (int k = i - 1; k >= 1; k--) {
					if (s[k][j] != '0') {
						swap(s[k][j], s[i][j]);
						break;
					}
				}
			}
		}
}

void bfs(int i, int j, char c) {
	if (s[i][j] != c || visited[i][j] || i > n || j > 10 || i < 1 || j < 1) return ;
	//cout << i << " " << j << '\n';
	visited[i][j] = 1;
	pos.push_back({i, j});
	bfs(i + 1, j, c);
	bfs(i - 1, j, c);
	bfs(i, j + 1, c);
	bfs(i, j - 1, c);
}

void flood_fill() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= 10; j++) visited[i][j] = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			if (s[i][j] != '0' && !visited[i][j]) {
				pos.clear();
				bfs(i, j, s[i][j]);
				if (pos.size() >= k) {
					th = true;
					for (auto x : pos) s[x.fi][x.se] = '0';
					
				}
				
			}
		}
	}
	//cout << "\n" << "//##############################################################################" << '\n';
}

void PrintAns() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) cout << s[i][j];
		cout << '\n';
	}
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	while (1) {
		th = false;
		change();
		//PrintAns();
		flood_fill();
		if (!th) {
			PrintAns();
			return ;
		}
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
