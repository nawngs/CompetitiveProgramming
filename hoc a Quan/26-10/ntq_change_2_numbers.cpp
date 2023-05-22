#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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

ll res = LINF, tempa = 1, tempb = 1;

int a, b, cnt[nmax + 3];

bool IsPrime[nmax + 3];

vector < int > prime, valid;

void sieve() {
	memset(IsPrime, 1, sizeof(IsPrime));
	IsPrime[1] = IsPrime[0] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (IsPrime[i]) 
			for (int j = i * i; j <= nmax; j+=i) 
				IsPrime[j] = false;
	for (int i = 2; i <= nmax; i++)
		if (IsPrime[i])
			prime.push_back(i);
}

void back_track(int x) {
	if (x == (int)valid.size()) {
		res = min(res, tempa + tempb);
		return ;
	}
	for (int i = 0; i <= 1; i++) {
		if (i == 0) tempa *= valid[x];
		else tempb *= valid[x];
		back_track(x + 1);
		if (i == 0) tempa /= valid[x];
		else tempb /= valid[x];
	}
}

void sol() {
	cin >> a >> b;
	memset(cnt, 0, sizeof(cnt));
	for (auto x : prime) {
		while (a % x == 0) {
			cnt[x] ^= 1;
			a /= x;
		}
		while (b % x == 0) {
			cnt[x] ^= 1;
			b /= x;
		}
	}
	valid.clear();
	for (auto x : prime) 
		if (cnt[x] & 1) 
			valid.push_back(x);
	if (a != 1) valid.push_back(a);
	if (b != 1 && a != b) valid.push_back(b);
	res = LINF,  tempa = 1, tempb = 1;
	back_track(0);
	cout << res << '\n';
}

main() {
	fast;
	//fre();
	sieve();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
