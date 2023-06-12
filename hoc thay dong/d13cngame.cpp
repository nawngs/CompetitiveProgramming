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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll nn, kk, M, a[23];

bool th[NMAX + 3];

vector < int > prime;

struct matran
{
	long long c[22][22];
	matran() {
		for (int i = 0; i <= 21; i++)
			for (int j = 0; j <= 21; j++) c[i][j] = 0;
	}
};

ll nhan(ll a, ll b) {
	if (b == 0) return 0;
	ll x = nhan(a, b / 2); x = (x + x) % M;
	if (b % 2 == 1) x = (x + a) % M;
	return x;
}

matran nhan(matran a, matran b){
	matran res;
	for(int i = 1; i <= nn + 1; i++){
		for(int j = 1; j <= nn + 1; j++){
			res.c[i][j] = 0;
			for(int k = 1; k <= nn + 1; k++){
				res.c[i][j] = (res.c[i][j] + nhan(a.c[i][k], b.c[k][j])) % M;
			}
		}
	}
	return res;
}

matran po(matran a, long long n){
	if(n == 1) return a;
	matran ha = po(a, n / 2);
	ha = nhan(ha, ha);
	if(n % 2 == 1) ha = nhan(ha, a);
	return ha;
}

bool check(ll x) {
	for (auto v : prime) if (x % v == 0 && x > v) return false;
	return true;
}

void sol() {
	cin >> nn >> kk >> M;
	for (int i = 1; i <= nn; i++) cin >> a[i];
	matran f;
	for (int i = 1; i <= nn; i++) {
		for (int j = 1; j <= nn; j++) {
			if (i != j && check(a[i] * 6 + a[j])) {
				f.c[i][j] = 1;
				if (j == nn) f.c[i][j + 1] = 1;
			}
		}
	}
	f.c[nn + 1][nn + 1] = 1;
	matran tam;
	tam = po(f, kk);
	matran temp;
	temp.c[1][1] = 1;
	temp = nhan(temp, tam);
	cout << (temp.c[1][nn + 1]) % M << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	for (int i = 2; i <= NMAX; i++) th[i] = 1;
	for (int i = 2; i * i <= NMAX; i++)
		if (th[i]) for (int j = i * i; j <= NMAX; j+=i) th[j] = false;
	for (int i = 2; i <= NMAX; i++) if (th[i]) prime.push_back(i);
	int t; cin >> t; while (t --) sol();
}