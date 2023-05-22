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
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data{
	int cnt[10];
} s[nmax + 5];

int a, b, k, cnt[nmax + 5];

bool f[nmax + 5];

void sang() {
	memset(f, true, sizeof(f));
	f[1] = f[0] = false;
	for (int i = 2; i * i <= nmax; i++) {
		if (f[i]) for (int j = i * i; j <= nmax; j += i) f[j] = false;
	}
	for (int i = 2; i <= nmax; i++) {
		if (f[i]) for (int j = i; j <= nmax; j += i) cnt[j] ++;
	}
}

void create() {
	for (int i = 1; i <= nmax; i++) {
		s[i] = s[i - 1];
		s[i].cnt[cnt[i]] ++;
	}
}

void sol() {
	cin >> a >> b >> k;
	cout << s[b].cnt[k] - s[a - 1].cnt[k] << '\n'; 
}

int main() {
	fast;
	sang();
	create();
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
