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

const string NAME = "minsum";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll a, b, cnt[nmax + 5], res, s1, s2, val1, val2;

vector < ll > prime;

vector < ll > left_prime;

bool check[nmax + 5];

void sang() {
	memset(check, 1, sizeof(check));
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (check[i]) for (int j = i * i; j <= nmax; j+=i) check[j] = false;
	for (int i = 1; i <= nmax; i++) if (check[i]) prime.push_back(i); 
}

void backtrack(ll pos) {
	if (pos == left_prime.size()) {
		if (res > s1 + s2) {
			res = s1 + s2;
			val1 = s1;
			val2 = s2;
		}
		return ;
	}
	for (int i = 1; i <= 2; i++) {
		if (i == 1) s1 *= left_prime[pos];
		else s2 *= left_prime[pos];
		backtrack(pos + 1);
		if (i == 1) s1 /= left_prime[pos];
		else s2 /= left_prime[pos];
	}
}

void sol() {
	cin >> a >> b;
	left_prime.clear();
	memset(cnt, 0, sizeof(cnt));
	for (auto x : prime) {
		while (a % x == 0) {
			cnt[x] ++;
			a /= x;
		}
		while (b % x == 0) {
			cnt[x] ++;
			b /= x;
		}
		cnt[x] %= 2;
		if (cnt[x]) left_prime.push_back(x);
	}
	if (a != 1) left_prime.push_back(a);
	if (b != 1) left_prime.push_back(b);
 	res = INF;
	s1 = 1;
	s2 = 1;
	backtrack(0);
	cout << max(val1, val2) << " " << min(val1, val2) << '\n';
}

int main() {
	fast;
	//fre();
	sang();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
