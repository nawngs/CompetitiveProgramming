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

ll n, a[200003], k;

bool th[200003];

vector < int > p;

void sol() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll s = 0, tam, res = 0;
	while (1) {
		tam = s % n;
		if (th[tam]) break;
		s += a[tam];
		th[tam] = 1;
		p.push_back(tam);
	}
	reverse(p.begin(), p.end());
	while (p.back() != tam && k > 0) {
		k --;
		res += a[p.back()];
		p.pop_back();
	}
	if (k == 0) {
		cout << res << '\n';
		return ;
	}
	reverse(p.begin(), p.end());
	ll sump = 0;
	for (auto x : p) sump += a[x];
	res += sump * (k / p.size());
	k %= p.size();
	for (int i = 0; i < k; i++) res += a[p[i]];
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
