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

ll n, m, s[(1 << 20)];

int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < (1 << m); i++) s[i] = 1;
	for (int i = 1; i <= n; i++) {
		int k, temp = 0;
		cin >> k;
		while (k --) {
			int x;
			cin >> x;
			x --;
			temp ^= (1 << x);
		}
		s[temp] *= 2;
		s[temp] %= MOD;
	}
	for (int j = 0; j < m; j++) 
		for (int i = 0; i < (1 << m); i++) 
			if ((i >> j) & 1) s[i] = (s[i] * s[(i ^ (1 << j))]) % MOD;
	for (int i = 0; i < (1 << m); i++) s[i] = (s[i] - 1 + MOD) % MOD;
	for (int j = 0; j < m; j++) 
		for (int i = 0; i < (1 << m); i++) 
			if ((i >> j) & 1) s[i] = (s[i] - s[(i ^ (1 << j))] + MOD) % MOD;
	int Q; cin >> Q;
	while(Q --) {
		int k, temp = 0;
		cin >> k;
		while (k --) {
			int x;
			cin >> x;
			x --;
			temp ^= (1 << x);
		}
		cout << s[temp] << '\n';
	}	
}

