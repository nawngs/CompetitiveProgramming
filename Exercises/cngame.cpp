#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "cngame";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {   
    string finp = NAME + ".inp";
    string fout = NAME + ".out";
    freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

ll n, x[20], k, m;

bool check(ll x, ll y) {
    ll tam = 6 * x + y;
    for (int i = 2; i * i <= tam; i++) if (tam % i == 0) return false;
    return true;
}

struct Matrix {
    ll a[21][21];
    void init1() {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) a[i][j] = check(x[i], x[j]);
            }
            a[i][n] = a[i][n - 1];
        }
        a[n][n] = 1;
    }

    void init() {
        memset(a, 0, sizeof(a));
        a[0][0] = 1;
    }
};

long long nhan(long long A, long long B, long long M)
{
    if (B == 0)
        return 0;

    long long T = nhan(A, B / 2, M) % M;

    if (B & 1)
        return ((T + T) % M + A % M) % M;
    else
        return (T + T) % M;
}

Matrix nhan(Matrix a, Matrix b) {
    Matrix res;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            res.a[i][j] = 0;
            for(int p = 0; p <= n; p++) res.a[i][j] = (res.a[i][j] + nhan(a.a[i][p], b.a[p][j], m)) % m;
            //cout << res.a[i][j] << ' ';
        }
      // cout << '\n';
    }
    return res;
}

Matrix mu(Matrix a, ll b) {
    if (b == 1) return a;
    Matrix x = mu(a, b / 2);
    x = nhan(x, x);
    if (b % 2 == 1) x = nhan(x, a);
    return x;
}

void sol() {
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) cin >> x[i];
    Matrix f;
    f.init1();
    Matrix tam = mu(f, k);
    f.init();
    f = nhan(f, tam);
    /*for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) cout << f.a[i][j] << " ";
        cout << '\n';
    }*/
    cout << f.a[0][n] << '\n';
}

int main() {
    fast;
    fre();
    int t = 1;
    cin >> t;
    while (t --) sol();
}

/*
 3 1 35097868
    11289 5873 10445 
*/