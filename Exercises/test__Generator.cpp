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

string gen(int sz)
{
    string tmp = "";
    for (int i = 1; i <= sz; i++)
    {
        tmp += (char)(get('a', 'z'));
    }
    return tmp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << 5 << '\n';
    for (int i = 1; i <= 5; i++) cout << gen(get(10, 15)) << '\n' << gen(get(10, 15)) << '\n';
}