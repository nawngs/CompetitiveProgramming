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
const string s = " CEGHPSTUV";

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int k, res[33], m;

vector < int > adj[33];

pair < char, int > f[12];

void back_track(int pos) {
	if (pos > 1) {
		k --;
		if (k == 0) {
			for (int i = 1; i < pos; i++) cout << f[res[i]].fi;
			exit(0);
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (f[i].se == 0) continue;
		bool th = 1;
		for (auto x : adj[pos]) {
			if (res[x] == i) {
				th = false;
				break;
			}
		}
		if (!th) continue;
		res[pos] = i;
		f[i].se --;
		back_track(pos + 1);
		f[i].se ++;
		res[pos] = '#';
	}
}

int main() {
	fast;
	//fre();
	//" CEGHPSTUV"
	f[1].fi = 'G'; f[2].fi = 'S'; f[3].fi = 'P'; f[4].fi = 'V'; f[5].fi = 'H'; f[6].fi = 'C', f[7].fi = 'U'; f[8].fi = 'T'; f[9].fi = 'E';
	for (int i = 1; i <= 9; i++) cin >> f[i].se;
	sort(f + 1, f + 9 + 1);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		adj[v].push_back(u);
	}
	cin >> k;
	back_track(1);
}
