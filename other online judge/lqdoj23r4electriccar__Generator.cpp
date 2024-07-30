#include <bits/stdc++.h>
using namespace std;

//types
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define pii pair<int, int>

#define fi first
#define se second
#define inf 0x3f3f3f3f

//lowercase 31, all 53
//(P/Q) % M = (P % M) * (Q^(M-2) % M)
//-------------------------------------------------------

const ld PI = 3.14159265359;
const ll mx = 1e5+5, mod = 1e9+7;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long get(long long l, long long r) {
    return l + (rd() % (r - l + 1));
}

int randomfunc(int j)
{
    return rd() % j;
}

pll a[mx];

int main()
{
    int n = get(5, 7);
    cout << n << ' ';
    int q; q = get(1, 3);
    cout << q << '\n';
    for (int i = 1; i <= n; i++) {
    	a[i] = {get(0, 1), get(1, 20)};
    	cout << a[i].fi << " " << a[i].se << '\n';
    }
    
    for (int t = 1; t <= q; t++) {
    	int i = get(1, n), j = get(1, n);
    	while (a[i].fi > a[j].fi || a[i].se > a[j].se) i = get(1, n), j = get(1, n);
    	cout << i << " " << j << '\n';
    }
}