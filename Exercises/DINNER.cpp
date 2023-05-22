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

const string NAME = "dinner";
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

typedef vector<int> vi;
const int BASE = 10000;

void fix(vi &a) {
    a.push_back(0);
    for (int i = 0; i < a.size() - 1; ++i) {
        a[i + 1] += a[i] / BASE;
        a[i] %= BASE;
        if (a[i] < 0) {
            a[i] += BASE;
            a[i + 1]--;
        }
    }
    while (a.size() >= 2 && a.back() == 0) a.pop_back();
}

vi operator*(const vi &a, const vi &b) {
    vi c(a.size() + b.size() + 1);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i + j] / BASE;
            c[i + j] %= BASE;
        }
    return fix(c), c;
}

vi to_vi(int x) {  // x < Base
    assert(x < BASE);
    return vi(1, x);
}

vi operator+(vi a, const vi &b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); ++i)
        a[i] += b[i];
    return fix(a), a;
}
vi operator-(vi a, const vi &b) {
    for (int i = 0; i < b.size(); ++i)
        a[i] -= b[i];
    return fix(a), a;
}
vi operator*(vi a, int x) {  // x < BASE
    assert(x < BASE);
    for (int i = 0; i < a.size(); ++i)
        a[i] *= x;
    return fix(a), a;
}

bool operator<(const vi &a, const vi &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i])
            return a[i] < b[i];
    return false;
}

vi operator/(vi a, int x) {  // x < BASE
    assert(x < BASE);
    for (int i = (int)a.size() - 1, r = 0; i >= 0; --i, r %= x) {
        r = r * BASE + a[i];
        a[i] = r / x;
    }
    return fix(a), a;
}
int operator%(const vi &a, int x) {  //x < BASE
    int r = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i)
        r = (r * BASE + a[i]) % x;
    return r;
}

istream &operator>>(istream &cin, vi &a) {
    string s;
    cin >> s;
    a.clear();
    a.resize(s.size() / 4 + 1);
    for (int i = 0; i < s.size(); ++i) {
        int x = (s.size() - 1 - i) / 4;  // <- log10(BASE)=4
        a[x] = a[x] * 10 + (s[i] - '0');
    }
    return fix(a), cin;
}

ostream &operator<<(ostream &cout, const vi &a) {
    printf("%d", a.back());
    for (int i = (int)a.size() - 2; i >= 0; i--)
        printf("%04d", a[i]);
    return cout;
}

void get_big_num(ll x, vi &a) {
    string s = "";
    while (x > 0) {
        char c = (x % 10) + '0';
        s = c + s;
        x /= 10;
    }
    a.clear();
    a.resize(s.size() / 8 + 1);
    for (int i = 0; i < s.size(); ++i) {
        ll x = (s.size() - 1 - i) / 8;  // <- log10(BASE)=8
        a[x] = a[x] * 10 + (s[i] - '0');
    }
    return fix(a);
}

vi Ckn[103][103], dp[103][103];

int n, k;

int main() {
	fast;
	//fre();
	cin >> k >> n;
	for (int i = 0; i <= 100; i++) {
		for (int j = i; j <= 100; j++) {
			if (i == 0 || i == j) get_big_num(1, Ckn[i][j]);
			else Ckn[i][j] = Ckn[i][j - 1] + Ckn[i - 1][j - 1];
		}
	}
	get_big_num(1, dp[0][0]);
	for (int i = 1; i <= k; i++) 
		for (int j = i; j <= n; j++) 
			for (int p = i - 1; p < j; p++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][p] * Ckn[j - p][n - p]);
			}
	cout << dp[k][n];
}
