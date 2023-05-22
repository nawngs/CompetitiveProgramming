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

const string NAME = "primelcm";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, x, res;

int tich[664579], l, low, high, mid, ans;

vector < int > prime;

vector < ll > val[664579];

bool isprime[nmax + 5];

void sang() {
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (isprime[i]) for (int j = i * i; j <= nmax; j += i) isprime[j] = false;
	for (int i = 1; i <= nmax; i++) if (isprime[i]) prime.push_back(i);
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll chia(ll x, ll y) {
	return (x * mu(y, MOD - 2)) % MOD;
} 

int main() {
	//fast;
	//fre();
	cin >> n;
	sang();
	for (int i = 0; i < prime.size(); i++) {
		tich[i] = prime[i];
		if (i != 0) tich[i] = (1ll * tich[i] * 1ll * tich[i - 1]) % MOD;
		val[i].push_back(1);
		for (int j = 1; j <= 46; j++) {
			if (val[i].back() > 1e14 / prime[i]) break;
			val[i].push_back(val[i].back() * 1ll * prime[i]);
		}
	}
	//cout << "ok" << '\n';
	while (n--) {
		cin >> x;
		res = 1;
		l = 0;
		for (int i = 46; i >= 2; i--) {
			if (val[l][i] == -1 || val[l][i] > x) continue;
			low = l; 
			high = prime.size() - 1;
			ans = l;
			while (low <= high) {
				//cout << mid << '\n';
				mid = (low + high) / 2;
				if (val[mid].size() > i && val[mid][i] <= x) {
					ans = mid;
					low = mid + 1;
				}
				else high = mid - 1;
			}
			if (l == 0) res = (res * mu(tich[ans], i - 1)) % MOD;
			else res = (res * mu(chia(tich[ans], tich[l - 1]), i - 1)) % MOD;
			l = ans + 1;
		}
		cout << res << " ";
	}
}
