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

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[50003];

bool have[100003];

int par[100003];

vector < int > pos[100003];

int find_par(int x) {
	return (par[x] == x ? x : par[x] = find_par(par[x])); 
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll sum = 0;
	have[a[1]] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) sum += a[i];
		have[a[i]] = 1;
	}
	for (int i = 1; i <= 100000; i++) {
		if (have[i]) par[i] = i;
		for (int j = i; j <= 100000; j += i) 
			if (have[j]) pos[i].push_back(j);	
	}
	for (int i = 100000; i >= 1; i--) {
		if (pos[i].size()) {
			int temp = find_par(pos[i][0]);
			for (auto x : pos[i]) {
				if (find_par(x) != temp) sum += i;
				par[par[x]] = temp;
			}
		}
	}
	cout << 1ll * 123456 * (n - 1) - sum;
}
