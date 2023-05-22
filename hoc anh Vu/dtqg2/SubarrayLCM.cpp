#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 60;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q;

vector < int > res[20003];

bool IsPrime[63];

vector < int > prime;

void sieve() {
	memset(IsPrime, 1, sizeof(IsPrime));
	IsPrime[1] = IsPrime[0] = false;
	for (int i = 2; i * i <= NMAX; i++)
		if (IsPrime[i]) 
			for (int j = i * i; j <= NMAX; j+=i) IsPrime[j] = false;
	for (int i = 2; i <= NMAX; i++)
		if (IsPrime[i]) prime.push_back(i);
}

vector < int > a[20003], st[20003][16];

vector < int > Change(int x) {
	vector < int > res;
	for (auto p : prime) {
		int dem = 0;
		while (x % p == 0) {
			dem ++;
			x /= p;
		}
		res.push_back(dem);
	}
	return res;
}

vector < int > LCM(const vector < int > &x, const vector < int > &y) {
	vector < int > res;
	for (int i = 0; i < sz(prime); i++) {
		int v = max(x[i], y[i]);
		res.push_back(v);
	}
	return res;
}

vector < int > get(int l, int r) {
	int k = log2(r - l + 1);
	return LCM(st[l][k], st[(r - (1 << k)) + 1][k]);
}

bool cmp(const vector < int > &x, const vector < int > &y) {
	double resx = 0, resy = 0;
	for (int i = 0; i < sz(prime); i++) {
		for (int j = 0; j < x[i]; j++) 
			resx += 1.0 * log(prime[i]);
		for (int j = 0; j < y[i]; j++)
			resy += 1.0 * log(prime[i]);
	}
	return resx < resy;
}

void Print(vector < int > x) {
	for (int i = 0; i < sz(prime); i++) cout << "prime " << prime[i] << " " << x[i] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	sieve();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a[i] = Change(x);
		st[i][0] = a[i];
	}
	for (int i = 0; i <= n; i++)
		while (sz(res[i]) < sz(prime)) res[i].push_back(100);
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st[i][j] = LCM(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	for (int i = 1; i <= n; i++) {
		int l = i;
		vector < int > cur = st[i][0];
		while (l < n) {
			int low = l, high = n, mid, ans;
			while (low <= high) {
				mid = (low + high) / 2;
				if (get(i, mid) == cur) {
					ans = mid;
					low = mid + 1;
				}
				else high = mid - 1;
			}
			res[ans - i + 1] = min(res[ans - i + 1], cur, cmp);
			l = min(n, ans + 1);
			cur = get(i, l);
		}
		res[n - i + 1] = min(res[n - i + 1], cur, cmp);
	}
	for (int i = n - 1; i >= 0; i--) {
		res[i] = min(res[i], res[i + 1], cmp);
	}
	for (int i = 0; i <= n; i++) {
		ll val = 1;
		for (int j = 0; j < sz(prime); j++) {
			while (res[i][j] --) val = (val * 1ll * prime[j]) % MOD;
		}
		res[i].clear(); res[i].push_back(val);	
	}
	while (q--) {
		int id; cin >> id; cout << res[id].back() << '\n';
	}
}