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

struct point {
    ll x, y;

    point(ll x = 0, ll y = 0): x(x), y(y) {}

    point& operator += (const point &o) {
        x += o.x; y += o.y; return *this;
    }

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point& operator *= (const ll &k) {
        x *= k; y *= k; return *this;
    }

    bool operator != (const point &o) const {
        return x != o.x || y != o.y;
    }

    bool operator == (const point &o) const {
        return x == o.x && y == o.y;
    }

    point operator + (const point &o) const {
        return point(*this) += o;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
    }

    point operator * (const ll &k) const {
        return point(*this) *= k;
    }
};

ll dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

ll cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

ll orient(const point &a,
const point &b, const point &c) {
    return cross(b - a, c - b);
}

ll norm(const point &p) {
    return dot(p, p);
}

istream& operator >> (istream &is, point &p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream &os, const point &p) {
    return os << p.x << ' ' << p.y;
}

point p;

vector < point > a, b;

int n;

bool cmp(point const &x, point const &y) {
    if (x.y * y.y <= 0) {
        if (x.y == y.y) return x.x < y.x;
        return x.y < y.y;
    }
    return cross(x - p, y - p) > 0;
}

void solve(int id) {
    p = a[id];
    for (int i = 0; i < n; i++) b[i] = a[i] - p;
    sort(b.begin(), b.end(), cmp);
}

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) solve(i);
}