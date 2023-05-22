#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second.
#define ll long long
#define pb push_back
#define db(val) "[" #val " = " << (val) << "] "
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 4;
const int INF = 1e9;
int L, R, tot[maxn], prime [maxn], cur[maxn];
bool isSquare(int x) {
	int s = sqrt(x);
	return s * s == x;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie (0); cout.tie(0);
	// freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	cin >> L >> R;
	if ((L < 0 && R > 0) || L == -1 || R == -1) return cout << -1, 0;
	L++, R++;
	int MAX = 1e6;
	for (int i = L; i <= R; i++) {
		tot[i - L] = 1;
		cur[i - L] = i;
	}
	for (int i = 2; i * i <= MAX; i++) if (!prime[i])
		for (int j = i * i; j <= MAX; j += i)
			prime[j] = 1;
	for (int i = 2; i <= MAX; i++)
		if (!prime[i]) {
			for (int j = (L / i + (L % i > 0)) * i; j <= R; j += i) {
				int x = j - L, cnt = 0;
				while (cur[x] % i == 0) cur[x] /= i, cnt++;
				tot[x] *= (cnt + 1);
				//cout << i << " " << j << " " << cur[x] << " " << tot[x] << '\n';
			}
		}
	int res = 0;
	for (int i = L; i <= R; i++) {
		int x = i - L;
		if (cur[x] != 1 && cur[x] != -1) tot[x] *= 2;
		res += tot[x] + isSquare(i);
	}
	cout << res;
}