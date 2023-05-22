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

ll n, k;

string s;

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

bool check(int pos, int mask, int bigger) {
	if (pos > n || bigger) return true;
	int poss = -1;
	if (__builtin_popcount(mask) < k) poss = 9;
	else for (int i = 9; i >= 0; i--) if (getbit(mask, i)) {poss = i; break;};
	if (poss == -1) return false;
	//cout << pos << " " << poss << '\n';
	for (int i = pos; i <= n; i++) {
		if (s[i] - '0' > poss) return false;
		if (s[i] - '0' < poss) return true;
	}
	return true;
}

void dp(int pos, int mask, int bigger) {
	if (pos > n) return ;
	int cur = s[pos] - '0';
	for (int i = 0; i <= 9; i++) {
		if (bigger || i >= cur) {
			int tam = mask | (1 << i);
			//cout << pos << " " << i << '\n';
			if ( __builtin_popcount(tam) > k) continue;
			int cur_big = (bigger || i > cur);
			if (check(pos + 1, tam, cur_big)) {
				cout << i;
				dp(pos + 1, tam, cur_big);
				return ;
			}

		}
	}
}

void sol() {
	cin >> s >> k;
	n = s.size();
	s = ' ' + s;
	dp(1, 0, 0);
	cout << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
