#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FOD(i, a, b) for(int i = a; i >= b; --i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ll long long
#define ld long double
#define nmax 5007
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const string name1 = "test";
const string name2 = "bao";

void fre() {
    string finp = name1 + ".inp";
    string fout = name2 + ".out";
    freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

ll const mod = 998244353;

int n, k;

ll mu(ll a, ll b)
{
    if(b == 0) return 1;

    ll x = mu(a , b / 2);

    x = (x * x) % mod;

    if(b % 2 != 0) x = (x * a) % mod;

    return x;
}

ll gt[nmax];


ll Ckn(ll k, ll n)
{
    ll tp = (gt[k] * gt[n - k]) % mod;

    return (gt[n] * mu(tp , mod - 2)) % mod;
}


string s;

int dem = 0;

vector < pair < int , int > > p;

int main()
{
    fre();
    cin >> n >> k >> s;

    s = ' ' + s;

    if(k == 0)
    {
        cout << 1;

        return 0;
    }

    FOR(i, 1, n) dem += (s[i] == '1');

    if(dem < k) 
    {
        cout << 1;
        return 0;
    }


    gt[0] = 1;

    FOR(i, 1, n) gt[i] = (gt[i - 1] * 1ll * i) % mod;

    ll ans = 1;

    FOR(i, 1, n)
    {
        if(s[i] == '0' && s[i - 1] == '0') continue;

        if(s[i] == '1' && s[i - 1] == '0') continue;

        // 00

        // 01

        // 11

        // 10

        int jp = i;

        int val = s[i] - '0';

        FOR(j, i + 1, n)
        {
            if(val + s[j] - '0' > k) break;
            val += s[j] - '0';
            jp = j;
        }

        if(val != k) continue;

        ans = (ans + Ckn(val , jp - i + 1)) % mod ;

        //cout << Ckn(val , jp - i + 1) << endl;

        if(p.size() > 0)
        {
            ans = (ans - Ckn(val - 1, p[p.size() - 1].se - i + 1) + mod) % mod;

            ans = (ans + 1) % mod;
        }

        p.pb({i, jp});


    }

    //for(auto z: p) cout << z.fi << " " << z.se << endl;

    cout << (ans - p.size() + mod) % mod;

    return 0;





    return 0;
}