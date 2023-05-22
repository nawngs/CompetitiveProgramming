#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "POSITION";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, f[100002], res[100002], value[100002], last = 0;

vector < ll > val;

pii pos[100005];

void sol() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		pos[i].fi = -1;
	}
	for (int j = 0; j < n; j++) {
		if (pos[j].fi == -1) {
			ll i = j;
			pos[i].fi = j;
			pos[i].se = 0;
			value[0] = i;
			val.clear();
			val.push_back(i);
			last = 0;
			while (pos[f[i]].fi != j) {
				last ++;
				value[last] = f[i];
				pos[f[i]].fi = j;
				pos[f[i]].se = pos[i].se + 1;
				i = f[i];
				val.push_back(i);
			}
			//cout << j << ' ' << last << '\n';
			for (auto x : val) {			
				if (pos[x].se + m <= pos[f[i]].se) res[x] = value[pos[x].se + m];
				else {
					ll tam = pos[x].se + m - pos[f[i]].se;
					tam %= last - pos[f[i]].se + 1;
					res[x] = value[pos[f[i]].se + tam];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) cout << res[i] << " ";
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
