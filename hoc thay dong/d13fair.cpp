#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define fi first
#define se second

using namespace std;

struct Edge {
	ll u, v, c;
} edges[100003];

ll n, s[100003], q;

vector < pll > adj[100003];

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n - 3; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].c;
		adj[edges[i].u].push_back({edges[i].v, w});
		
	}
}
