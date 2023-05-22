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

const string NAME = "";
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

int n, res[1005];

bool check[1002][1002];

pii a[1002];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) check[i][j] = false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		res[i] = 0;
		check[a[i].fi][a[i].se] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i].fi == a[i].se) res[i] = a[i].fi;
		else {
			if (check[a[i].fi + 1][a[i].se]) res[i] = a[i].fi;
			else if (check[a[i].fi][a[i].se - 1]) res[i] = a[i].se;
				else {
	 				for (int j = a[i].fi + 1; j < a[i].se; j++) {
						if (check[a[i].fi][j - 1] && check[j + 1][a[i].se]) {
							res[i] = j;
							break;
						}
					}
				}
		}
		cout << a[i].fi << " " << a[i].se << " " << res[i] << '\n';
	}
}

int main() {
	//fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
