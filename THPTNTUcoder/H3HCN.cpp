#include <bits/stdc++.h>

using namespace std;

struct point {
	long long x, y;
};

struct rect {
	point p1;
	point p2;
} a, b, c;

long long area(rect a) {
	return abs(a.p1.x - a.p2.x) * abs(a.p1.y - a.p2.y);
}

rect overlap(rect a, rect b) {
	rect ans;
	ans.p1.x = -1;
	ans.p2.x = -1;
	ans.p1.y = -1;
	ans.p2.y = -1;
	if (a.p1.x > b.p2.x || a.p2.x < b.p1.x) return ans;
	if (a.p1.y > b.p2.y || a.p2.y < b.p1.y) return ans;
	ans.p1.x = max(a.p1.x, b.p1.x);
	ans.p1.y = max(a.p1.y, b.p1.y);
	ans.p2.x = min(a.p2.x, b.p2.x);
	ans.p2.y = min(a.p2.y, b.p2.y);
	return ans;
}

int main() {
	cin >> a.p1.x >> a.p1.y >> a.p2.x >> a.p2.y; 
	cin >> b.p1.x >> b.p1.y >> b.p2.x >> b.p2.y; 
	cin >> c.p1.x >> c.p1.y >> c.p2.x >> c.p2.y;
	rect ab = overlap(a, b);
	rect bc = overlap(b, c);
	rect ca = overlap(c, a);
	rect abc = overlap(bc, a);
	//cout << area(a) << " " << area(b) << " " << area(c) << " " << area(ab) << " " << area(bc) << " " << area(ca) << " " << area(abc) << '\n';
	cout << area(a) + area(b) + area(c) - area(ab) - area(bc) - area(ca) + area(abc);
}