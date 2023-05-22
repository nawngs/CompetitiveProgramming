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
#define ull unsigned long long
#define nmax 2000000
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll n;
int prime[nmax + 7];
void sangnt()
{
    FOR(i, 2, nmax) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i = 2; i * i <= nmax; ++i)
        if(prime[i])
            for(int j = i * i; j <= nmax; j += i)
                prime[j] = 0;
    FOR(i, 1, nmax) prime[i] += prime[i - 1];
}
void solve()
{
    cin >> n;
    ull ans = n * (n - 1) * (n - 2) / 6;
    ull ans1 = 0;
    FOR(i, 1, n)
    { 
        ull tp = prime[n + i] - prime[i] - (i == 1);
        //cout << tp << '\n';
        ans1 += tp * (n - 2);
        ans1 -= tp * (tp - 1);
    }
    cout << ans1 << '\n';
    ans1 /= 2;
    cout << ans - ans1 << '\n';
}
int main()
{
    faster();
    sangnt();
    int ntest;
    cin >> ntest;
    while(ntest--) solve();
    return 0;
}
