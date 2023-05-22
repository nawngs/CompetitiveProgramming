#include <bits/stdc++.h>
#define FNAME ""
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(a, b)(rnd);
#define rd(a, b) uniform_int_distribution<int>(a, b)(rng)

#define BIT(x, i) (x >> i & 1)
using ll = long long;

typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

const int nmx = 7;
const int vmx = 20;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n = nmx, s = rd(0, n-1), d = rd(1, 2*n);
	cout << n << ' ' << s << ' ' << d << '\n';
	for (int i = 0; i < n; ++i)
		cout << rd(1, vmx) << ' ';
 	return 0;
}






