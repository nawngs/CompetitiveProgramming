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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}


ll pow_base[1000003], hash_s[2000003], tam;

vector < int > a;

string s;

void create() {
	pow_base[0] = 1;
	for(int i = 1; i <= 1000000; i++){
		pow_base[i] = (pow_base[i - 1] * base) % MOD;
	}
}

ll get(ll l, ll r){
	return (hash_s[r] - hash_s[l - 1] * pow_base[r - l + 1] + MOD * MOD) % MOD;
}

bool cmp(int x, int y) {
	int l = 1, r = tam, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (get(x, x + mid - 1) == get(y, y + mid - 1)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	//cout << x << " " << y << " " << ans << '\n';
	return (ans == tam || s[x + ans] < s[y + ans]);
}


void sol() {
	create();
	cin >> s;
	tam = s.size();
	s = s + s;
	ll n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) hash_s[i] = (hash_s[i - 1] * base + s[i]) % MOD; 		
	int res = 1;
	for (int i = 2; i <= tam; i++) if (cmp(i, res)) res = i; 
	for (int i = res; i < res + tam; i++) cout << s[i];
	
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
