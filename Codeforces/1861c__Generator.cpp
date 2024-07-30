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

vector < int > p;


int main()
{
    int n = 10; cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        int k = get(1, 15), cur = 0;
        while (k --) {
            while (1) {
                int x = get(1, 4);
                if (x == 4) {
                    cout << 1;
                    break;
                }
                if (x == 3) {
                    cout << 0;
                    break;
                }
                if (x == 1) {
                    cout << '+'; cur++;
                    break;
                }
                if (cur > 0) {
                    cout << '-'; cur --;
                    break;
                }
            }
        }
        cout << '\n';
    }
}