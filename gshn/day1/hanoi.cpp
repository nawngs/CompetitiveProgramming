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

int n, pos[23];;

string s;

vector < int > a[4];

vector < pii > res;

void move(int id, int finish) {
	if (id == 0) return ;
	if (pos[id] != finish) {
		move(id - 1, 6 - finish - pos[id]);
		res.push_back({pos[id], finish});
		pos[id] = finish;
	}
	move(id - 1, finish);
}

int main() {
	fast;
	cin >> n >> s;
	s = ' ' + s;
	for (int i = n; i >= 1; i--) {
		if (s[i] == 'A') a[1].push_back(i);
		if (s[i] == 'B') a[2].push_back(i);
		if (s[i] == 'C') a[3].push_back(i);
		pos[i] = (s[i] == 'A' ? 1 : s[i] == 'B' ? 2 : 3);
	}
	move(n, 3);
	cout << res.size() << '\n';
	for (auto x : res) {
		cout << (x.fi == 1 ? 'A' : x.fi == 2 ? 'B' : 'C') << (x.se == 1 ? 'A' : x.se == 2 ? 'B' : 'C') << '\n';
	}
}
 