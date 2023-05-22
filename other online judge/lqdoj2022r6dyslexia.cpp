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

const string NAME = "DYSLEXIA";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

const char B64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int position[256];
void initBase64(){
    for (int i = 0; i < 64; i++)
        position[B64[i]] = i;
}


int n;
string S64; 
char S[nmax + 3]; 
void b64Conversion(const string &s){
    int ptr = 0;
    for (char c: s){
        int x = position[c];
        for (int i = 0; i < 6; i++){
            S[ptr++] = (x & 1) + '0';
            x >>= 1;
        }
    }
}

namespace sub1 {
	ll cnt[2][1003];
	void solve() {
		cnt[S[0] - '0'][0] ++;
		for (int i = 1; i < n; i++) {
			cnt[0][i] = cnt[0][i - 1];
			cnt[1][i] = cnt[1][i - 1];
			cnt[S[i] - '0'][i] ++;
		}
		ll res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				ll dem0 = cnt[0][j], dem1 = cnt[1][j];
				if (i > 0) {
					dem0 -= cnt[0][i - 1];
					dem1 -= cnt[1][i - 1];
				}
				if (dem0 == 0) res = (res + dem1 * dem1) % MOD;
				else if (dem1 == 0) res = (res + dem0 * dem0) % MOD;
				else res = (res + dem0 * dem1) % MOD;
			}
		}
		cout << res;
	}
}

namespace sub3 {
	void solve() {
		ll cur = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			cur = (cur + i * i) % MOD;
			res = (res + cur) % MOD;
		}
		cout << res << '\n';
	}
}

int main() {
	fast;
	//fre();
	cin >> n >> S64;
    initBase64(); b64Conversion(S64);
    if (n <= 1e3) sub1::solve();
    else sub3::solve();
}
