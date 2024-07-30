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

int a[mx];


int main()
{
    int n = get(1, 10);
    cout << n << '\n';
    for (int i = 1; i <= n; i++) a[i] = get(1, 20);
	sort(a + 1, a + n + 1, greater < int >());
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	int q = get(1, 10);
	cout << q << '\n';
	while (q--) {
		if (get(0, 1)) cout << 2 << " " << get(1, n) << " " << get(1, 100) << '\n';
		else cout << 1 << " " << get(1, n) << " " << get(1, 20) << '\n';
	}
}