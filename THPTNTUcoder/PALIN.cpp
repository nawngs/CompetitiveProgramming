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

ll pow_base[100003], hashs[100003], hashs_rev[100003];

string s;

void build_hash(string str, long long arr[]){
	for(int i = 1; i < str.size(); i++){
		arr[i] = (arr[i - 1] * base + str[i]) % MOD;
	}
}

long long get_hash(long long l, long long r, long long arr[]){
	return (arr[r] - arr[l - 1] * pow_base[r - l + 1] + MOD * MOD) % MOD;
}

void sol() {
	cin >> s;
	ll n = s.size();
	string s_rev = s;
	reverse(s_rev.begin(), s_rev.end());
	s = ' ' + s;
	s_rev = ' ' + s_rev;
	//cout << s << " " <<  s_rev << '\n';
	pow_base[0] = 1;
	for(int i = 1; i <= n; i++){
		pow_base[i] = (pow_base[i - 1] * base) % MOD;
	}
	build_hash(s, hashs);
	build_hash(s_rev, hashs_rev);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int mid1 = (r + l) / 2, mid2 = (r + l + 1) / 2;
		cout << (get_hash(l, mid1, hashs) == get_hash(n - r + 1, n - mid2 + 1, hashs_rev) ? "YES" : "NO") << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
