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

int n, prime[nmax + 3];

vector < int > cur;

map < vector < int >, int > f;

void sang() {
	for (int i = 1; i <= nmax; i++) prime[i] = i;
	for (int i = 2; i * i <= nmax; i++) 
		if (prime[i] == i) for (int j = i * 2; j <= nmax; j+=i) prime[j] = i;
	
}

int main() {
	fast;
	cin >> n;
	sang();
	ll ans = 0;
	for (int x = 1; x <= n; x++) {
		cur.clear();
		int pre = -1, dem = 0;
		int i = x;
		while (i > 1) {
			if (pre == prime[i]) dem ++;
			else {
				dem %= 2;
				if (dem != 0) cur.push_back(pre);
				dem = 1;
			}
			pre = prime[i];
			i /= prime[i];
		}
		if (dem % 2 == 1) cur.push_back(pre);
		sort(cur.begin(), cur.end());
		ll tam = f[cur];
		ans += tam * (tam - 1) / 2;
		f[cur] ++;
	}
	cout << ans;
}
