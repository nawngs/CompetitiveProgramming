#pragma GCC optimize ("O3")
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

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	ll x, y;
	ld d;
};

Data stat;

ll x, m;

Data taodata(ll a, ll b, ld c) {
	Data ans;
	ans.x = a;
	ans.y = b;
	ans.d = c;
	return ans;
}

ld rutgonld(ld x) {
	ll tam = (ll) x;
	tam = tam / m;
	return x - tam * m;
}

void rutgon(Data &f) {
	f.x %= m;
	f.y %= m;
	f.d = rutgonld(f.d);
}

Data nhan(Data a, Data b) {
	ll temp = (a.x * b.x) % m;
	temp = (temp + ((a.y * b.y) % m) * (11 % m)) % m;
	ll tempy = (((a.x * b.y) % m) + ((a.y * b.x) % m)) % m;
	ld tempa = a.d * b.x;
	rutgonld(tempa);
	ld tempb = a.x * b.d;
	rutgonld(tempb);
	ld res = rutgonld(tempa + tempb);
	return taodata(temp, tempy, res);
}

Data mu(ll x) {
	if (x == 1) return stat;
	Data tam = mu(x / 2);
	tam = nhan(tam, tam);
	cout << tam.x << " " << tam.y << " " << tam.d << '\n';
	if (x % 2 == 1) tam = nhan(tam, stat);
	return tam;
}

void sol() {
	cin >> x >> m;
	stat = taodata(4, 1, sqrtl(11));
	rutgon(stat);
	Data ans = mu(x);
	ld resld = rutgonld(ans.d);
	cout << (ans.x + (ll) resld) % m; 
	

}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
