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

ll w, l;

set < ll > res;

void calc() {
	ll temp = __gcd(w - 1, l - 1);
	for (int i = 1; i * i <= temp; i++)
		if (temp % i == 0) {
			res.insert(i);
			res.insert(temp / i);
		}
	temp = __gcd(w - 2, l);
	for (int i = 1; i * i <= temp; i++)
		if (temp % i == 0) {
			res.insert(i);
			res.insert(temp / i);
		}
	temp = __gcd(w - 1, __gcd(l, l - 2));
	for (int i = 1; i * i <= temp; i++)
		if (temp % i == 0) {
			res.insert(i);
			res.insert(temp / i);
		}
}

void sol() {
	cin >> w >> l;
	res.clear();
	calc();
	swap(w, l);
	calc();
	cout << res.size() << ' ';
	for (auto x : res) cout << x << " ";
	cout << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
