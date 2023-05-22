#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FOD(i, a, b) for(int i = a; i >= b; --i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ll long long
#define ld long double
#define pii pair <int, int>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
const int nmax = 1007;

int getrand(const int& mi, const int& ma)
{
    return rng() % (ma - mi + 1) + mi;
}

bool minimize(int& x, const int& y)
{
    if(x > y)
    {
        x = y;
        return true;
    }
    return false;
}

bool maximize(int& x, const int& y)
{
    if(x < y)
    {
        x = y;
        return true;
    }
    return false;
}

struct Tpoint
{
    ll x, y;
    Tpoint()
    {
        x = y = 0;
    }
    Tpoint(const ll& _x, const ll& _y)
    {
        x = _x, y = _y;
    }
};

ll const INF = LONG_LONG_MAX;

ll const cur = 1e6;

using Tvector = Tpoint;

ld len(const Tvector& u)
{   
    return sqrt(u.x * u.x + u.y * u.y);
}

ll sqrlen(const Tvector& u)
{
    return u.x * u.x + u.y * u.y;
}

Tvector operator +(const Tvector& u, const Tvector& v)
{
    return {u.x + v.x, u.y + v.y};
}

Tvector operator -(const Tvector& u, const Tvector& v)
{
    return {u.x - v.x, u.y - v.y};
}

ll operator %(const Tvector& u, const Tvector& v)
{
    return u.x * v.x + u.y * v.y;
}

ll operator *(const Tvector& u, const Tvector& v)
{
    return u.x * v.y - u.y * v.x; 
}

int CCW(const Tpoint& a, const Tpoint& b, const Tpoint& c)
{
    ll tp = (b - a) * (c - b);
    if(tp > 0) return 1; // re trai
    if(tp < 0) return -1; // re phai
    return 0; // thang hang
}

tuple <ll, ll, ll> pt(const Tpoint& a, const Tpoint& b)
{
    ll A = a.y - b.y;
    ll B = b.x - a.x;
    ll C = a.x * b.y - a.y * b.x;
    return {A, B, C};
}

Tpoint giao(const Tpoint& a, const Tpoint& b, const Tpoint& c, const Tpoint& d)
{
    Tpoint res = Tpoint(INF, INF);
    if(CCW(a, b, c) * CCW(a, b, d) > 0 || CCW(c, d, a) * CCW(c, d, b) > 0) return res;
    ll A[2], B[2], C[2];
    tie(A[0], B[0], C[0]) = pt(a, b);
    tie(A[1], B[1], C[1]) = pt(c, d);
    ll tmp = A[0] * B[1] - A[1] * B[0];
    ll X = B[1] * C[0] - B[0] * C[1];
    ll Y = A[0] * C[1] - A[1] * C[0];
    if(X % tmp != 0) return res;
    if(Y % tmp != 0) return res;
    return Tpoint(X / tmp, Y / tmp);
}

int num_node(const Tpoint& a, const Tpoint& b)
{
    return __gcd(abs(a.x - b.x), abs(a.y - b.y)) + 1;
}

int n;
Tpoint a[nmax][2];
map <pii, int> nmap;
int main()
{
    faster();
    cin >> n;
    FOR(i, 1, n)
    FOR(j, 0, 1)
        cin >> a[i][j].x >> a[i][j].y;
    ll ans = 0;
    FOR(i, 1, n) 
    {
        ans += num_node(a[i][0], a[i][1]);
        //cout << num_node(a[i][0], a[i][1]) << endl;
    }
    FOR(i, 1, n - 1)
    FOR(j, i + 1, n)
    {
        Tpoint tam = giao(a[i][0], a[i][1], a[j][0], a[j][1]);
        if(tam.x < -cur || tam.x > cur || tam.y < -cur || tam.y > cur) continue;
        nmap[{tam.x, tam.y}]++;
        //cout << "H" << endl;
    }
    for(auto tmp: nmap)
    {
        int tam = sqrt(tmp.se * 2);
        ans -= tam;
    }
    cout << ans;
    return 0;
}