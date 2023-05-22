#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int x, y, k;
int rev[N];
pi r[N], c[N];
map<pi, int> dr, dc;

int Rev(int x){
    int res = 0;
    while ( x ){
        res = res * 10 + x%10;
        x /= 10;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // freopen("rev.inp", "r", stdin);
    // freopen("rev.out", "w", stdout);

    cin >> x >> y >> k;

    for (int i = 1; i <= max(x, y); i ++)
        rev[i] = Rev(i);

    for (int i = 1; i <= x; i ++){
        r[i].fi = i; r[i].se = rev[i];
        int g = __gcd(r[i].fi, r[i].se);
        r[i].fi /= g;
        r[i].se /= g;
    }

    for (int i = 1; i <= y; i ++){
        c[i].fi = i; c[i].se = rev[i];
        int g = __gcd(c[i].fi, c[i].se);
        c[i].fi /= g;
        c[i].se /= g;
        dc[{c[i].se, c[i].fi}] ++;
    }

    ll ans = oo, cnt = 0;
    pi res;
    int j = y;
    for (int i = 1; i <= x; i ++){
        cnt += dc[{r[i].fi, r[i].se}];
        dr[{r[i].fi, r[i].se}] ++;

        while ( cnt - dr[{c[j].se, c[j].fi}] >= k && j > 1 ){
            cnt -= dr[{c[j].se, c[j].fi}];
            dc[{c[j].se, c[j].fi}] --;
            j --;
        }

        if ( ans > 1LL * i * j ){
            ans = 1LL * i * j;
            res = {i, j};
        }
    }

    if ( ans == oo ) cout << -1 << '\n';
    else cout << res.fi << ' ' << res.se << '\n';

    return 0;
}