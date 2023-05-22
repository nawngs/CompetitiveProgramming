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
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string s, s_rev;

ll pow_base[nmax + 5], hashs[nmax + 5], hashs_rev[nmax + 5];

void create() {
	pow_base[0] = 1;
	for(int i = 1; i <= nmax; i++){
		pow_base[i] = (pow_base[i - 1] * base) % MOD;
	}
}

void build_hash(string str, long long arr[]){
	for(int i = 1; i < str.size(); i++){
		arr[i] = (arr[i - 1] * base + str[i]) % MOD;
	}
}

long long get_hash(long long l, long long r, long long arr[]){
	return (arr[r] - arr[l - 1] * pow_base[r - l + 1] + MOD * MOD) % MOD;
}

void sol() {
	getline(cin, s);
	if (s[s.size() - 1] == '\r') s.erase(s.size() - 1);
	if (s.size() % 2 == 1) {
		cout << "NO" << '\n';
		return ;
	}
	s_rev = s;
	reverse(s_rev.begin(), s_rev.end());
	s = ' ' + s;
	s_rev = ' ' + s_rev;
	build_hash(s, hashs);
	build_hash(s_rev, hashs_rev);
	int l = 1;
	int i = 2;
	while (i < s.size()) {
		if (i + i - l - 1 >= s.size()) break;
		if (s[i] == s[i - 1]) {
			int taml = i;
			int tamr = i + (i - 1 - l);
			//cout << l << " " << i - 1 << " " << s.size() - tamr << " " << s.size() - taml << '\n';
			if (get_hash(l, i - 1, hashs) == get_hash(s.size() - tamr, s.size() - taml, hashs_rev)) {
				l = i = i + i - l;
			}
		}
		i ++;
	}
	cout << (l == s.size() ? "YES" : "NO") << '\n';

}

int main() {
	//fast;
	//fre();
	create();
	int t = 1;
	cin >> t;
	getline(cin, s);
	while (t --) sol();
}
