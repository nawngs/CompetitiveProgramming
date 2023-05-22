#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "lift";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
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

ll a, b, c, l, r, dp[1000003];

bool minimize(ll &x, ll y) {
    if (x > y) {
        x = y;
        return 1;
    }
    return false;
}

int main() {
    fast;
    freopen("lift.inp", "r", stdin);
    freopen("lift.out", "w", stdout);
    cin >> a >> b >> c >> l >> r;
    // clock_t start, end;   
    // double time_use;     
    // start = clock();
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    for (int i = 0; i < a; i++) dp[i] = LINF;
    dp[1 % a] = 1;
    priority_queue < pll, vector < pll >, greater < pll > > heap;
    heap.push({1, (1 % a)});
    while (heap.size()) {
        auto u = heap.top(); heap.pop();
        if (u.fi != dp[u.se]) continue;
        if (minimize(dp[(u.se + b) % a], u.fi + b)) 
            heap.push({dp[(u.se + b) % a], (u.se + b) % a});
         if (minimize(dp[(u.se + c) % a], u.fi + c)) 
            heap.push({dp[(u.se + c) % a], (u.se + c) % a});
    }
    // end = clock();
    // time_use = double(end - start) / CLOCKS_PER_SEC;
    // cout << time_use << '\n';
    ll minv, maxv, num;
    vi res, temp2, temp3;
    get_big_num(0, res);
    for (int i = 0; i < a; ++i) {
        if (dp[i] == LINF) continue;
        minv = l / a * a + i;
        while (minv < l) 
            minv += a;
        minv = max(minv, dp[i]);
        maxv = r / a * a + i;
        while (maxv > r) 
            maxv -= a;
        if (minv > maxv) continue;
        num = (maxv - minv) / a + 1;
        maxv = maxv + minv;
        if (!(num & 1)) num >>= 1;
        else maxv >>= 1;
        get_big_num(maxv, temp2);
        get_big_num(num, temp3);
        res = res + ((temp3 * temp2));
    }
    cout << res;
}
