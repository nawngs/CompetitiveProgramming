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

ll L, R, q, d[100003], hash_s[1000003], pow_base[1000003], len = 0;

string w[100003];

map < int, bool > f;

void create() {
	pow_base[0] = 1;
	for(int i = 1; i <= 1000000; i++){
		pow_base[i] = (pow_base[i - 1] * base) % MOD;
	}
}

void create_hash(int i) {
	ll h = 0;
	for (int j = 0; j < w[i].size(); j++) {
		h = (h * base + w[i][j]) % MOD;
		f[h] = 1;
	}
}

ll get_hash(ll l, ll r){
	return (hash_s[r] - hash_s[l - 1] * pow_base[r - l + 1] + MOD * MOD) % MOD;
}

string s;

void solve() {
	cin >> s;
		if (s.size() % len) {
			cout << "No" << '\n';
			return ;
		} 
		hash_s[0] = s[0];
		for (int i = 1; i < s.size(); i++) hash_s[i] = (hash_s[i - 1] * base + s[i]) % MOD;
		int cur = s.size() - 1;
		while (1) {
			int tam = cur - len + 1;
			while (tam >= 0) {
				//cout << tam << " " << cur << " " << get_hash(tam, cur) << '\n';
				if (f[get_hash(tam, cur)]) break;
				tam -= len;
			}
			if (tam < 0) {
				cout << "No" << '\n';
				return ;
			}
			if (tam == 0) break;
			cur = tam - 1;
		}
		cout << "Yes" << '\n';
}

int main() {
	fast;
	//fre();
	cin >> L >> R;
	for (int i = 1; i <= L; i++) {
		cin >> w[i];
		len = __gcd(len, (ll) w[i].size());
	}
	for (int i = 1; i <= R; i++) {
		cin >> d[i];
		len = __gcd(len, d[i]);
	}
	for (int i = 1; i <= L; i++) create_hash(i);
	create();
	cin >> q;
	while (q--) solve();
}
