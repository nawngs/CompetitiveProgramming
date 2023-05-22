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
#define nmax 200007
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, k;

int pre[nmax];

int c[nmax] , a[nmax];

int num[nmax];

//vector < int > adj[nmax];

pair < int , int > b[nmax];

bool check(int x)
{
    FOR(i, 1, n)
    if(a[i] >= x)
        c[i] = 1;
    else c[i] = 0;

    pre[0] = 0;

    // num[j] - num[i] > (j - i) / 2
    // num[j] - num[i] > (j - i) / 2
    // 2num[j] - 2num[i] > j - i


    FOR(i, 1, k - 1)
    {
        num[i] = num[i - 1] + c[i];
        pre[i] = max(pre[i - 1] , i - 2 * num[i]);
    }

    FOR(i, k, n)
    {
        num[i] = num[i - 1] + c[i];
        if(pre[i - k] > i - 2 * num[i]) return true;
        pre[i] = max(pre[i - 1] , i - 2 * num[i]);
    }



    return false;
}

int main()
{
    faster();

    freopen("MaxMedian.inp","r",stdin);
    freopen("MaxMedian.out","w",stdout);

    cin >> n >> k;


    FOR(i, 1, n)
    {
        cin >> a[i];
        //adj[a[i]].eb(i);
    }

    //hh();

    int l, r, m;

    l = 1;

    r = 1e9;

    int ans = 0;

    while(l <= r)
    {
        m = (l + r) >> 1;

        if(check(m))
        {
            ans = max(ans, m);
            l = m + 1;
        }
        else r = m - 1;
    }

    //bool ok = check(3);

    cout << ans;

    return 0;
}