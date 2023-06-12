#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;

typedef vector<ll> vi;
const ll BASE = 100000000;

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

ostream &operator<<(ostream &cout, const vi &a) {
    printf("%d", a.back());
    for (int i = (int)a.size() - 2; i >= 0; i--)
        printf("%08d", a[i]);
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

vi dp[253][253];

string s;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> s; int n = sz(s); s = ' ' + s;
	get_big_num(1, dp[0][0]);
	vi res;
	get_big_num(0, res);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j <= n; j++) {
			for (int nxt = i + 1; nxt <= n; nxt++)
				if (s[nxt] == 'F') {
					dp[nxt][j + 1] = dp[nxt][j + 1] + dp[i][j];
					break;
				}
			if (j > 0) {
				for (int nxt = i + 1; nxt <= n; nxt++)
					if (s[nxt] == 'R') {
						dp[nxt][j - 1] = dp[nxt][j - 1] + dp[i][j];
						break;
					}
			}
		}
	for (int i = 1; i <= n; i++)
		res = res + dp[i][0];
	cout << res;
}