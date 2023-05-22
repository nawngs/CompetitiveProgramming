/*#pragma GCC optimize ("O2")
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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m;

string s;

vector < int > adj[1003];

int valid[1003][3];

vector < char > res;

vector < int > temp;

bool can_create;

int change(char c) {
	if (c == 'R') return 0;
	if (c == 'B') return 1;
	return 2;
}

int calc_valid(int id) {
	return (valid[id][0] == 0) + (valid[id][1] == 0) + (valid[id][2] == 0);
}

char change_into_char(int x) {
	if (x == 0) return 'R';
	if (x == 1) return 'B';
	return 'G';
}

void dfs(int u) {
	for (auto v : adj[u]) {
		if (!can_create) return ;
		if (res[v] == '#') {
			valid[v][change(res[u])] ++;
			if (calc_valid(v) == 0) {
				can_create = false;
				valid[v][change(res[u])] --;
				return ;
			} 
			if (calc_valid(v) == 2) {
				valid[v][change(res[u])] --;
				continue;
			}
			temp.push_back(v);
			for (int i = 0; i < 3; i++) {
				if (valid[v][i] == 0) {
					valid[v][i] ++;
					res[v] = change_into_char(i);
					dfs(v);
				}
			}
			valid[v][change(res[u])] --;
		}
		else {
			if (res[u] == res[v]) {
				can_create = false;
				return ;
			}
		}
	}
}

int main() {
	fast;
	cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) valid[i][change(s[i])]++;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	res.resize(n + 1, '#');
	//dfs(1, 1);
	for (int i = 1; i <= n; i++) {
		if (res[i] == '#') {
			bool th = false;
			for (int c = 0; c < 3; c++) {
				if (valid[i][c] > 0) continue; 
				can_create = true;
				valid[i][c] ++;
				res[i] = change_into_char(c);
				temp.clear();
				temp.push_back(i);
				dfs(i);
				if (!can_create) {
					for (auto x : temp) {
						valid[x][change(res[x])] --;
						res[x] = '#';
					}
				}
				else {
					th = 1;
					break;
				}
			}
			if (!th) {
				cout << "Impossible" << '\n';
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (res[i] == '#') {
			cout << "Impossible" << '\n';
			return 0;
		}	
	}
	for (int i = 1; i <= n; i++) cout << res[i];
}
*/

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
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long get(long long l, long long r) {
    return l + (rd() % (r - l + 1));
}

int n, m;

string s;

bool created = false;

bitset < 3 > valid[1003];

vector < int > adj[1003];

char res[1003];

int change(char c) {
	if (c == 'R') return 0;
	if (c == 'B') return 1;
	return 2;
}

char change_into_char(int x) {
	if (x == 0) return 'R';
	if (x == 1) return 'B';
	return 'G';
}

void solve() {
	for (int i = 1; i <= n; i++) {
		valid[i] = 0;
		valid[i] = ~valid[i];
		res[i] = '#';
	}
	for (int i = 1; i <= n; i++) valid[i][change(s[i])] = 0;
	//cout << valid[1].count() << '\n';
	while (1) {
		int val = INF, choice = -1;
		for (int i = 1; i <= n; i++) {
			if (valid[i].count() == 0) continue;
			if (val > (int) valid[i].count()) {
				val = (int) valid[i].count();
				choice = i;
			}
		}
		if (choice == -1) break;
		int tam = get(1, val), pos;
		for (int i = 0; i < 3; i++) {
			tam -= valid[choice][i];
			if (tam == 0) {
				pos = i;
				break;
			}
		}
		valid[choice] = 0;
		for (auto x : adj[choice]) valid[x][pos] = 0;
		res[choice] = change_into_char(pos);
	}
	for (int i = 1; i <= n; i++) if (res[i] == '#') return ;
	for (int i = 1; i <= n; i++) cout << res[i];
	cout << '\n';
	created = 1;
}

int main() {
	//fast;
	cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//solve();
	
	for (int i = 1; i <= 1; i++) {
		solve();
		if (created) return 0;
	}
	cout << "Impossible";
}
