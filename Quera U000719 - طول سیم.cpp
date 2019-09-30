// by Amirhossein Jeddi
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define ll long long
const int MAX = 1000005;
struct Point {
	ll x, y;
	ll xplusy;
	ll xminusy;
};
Point a[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll maxplus = -9999999, maxid = 0;
	ll minplus = 9999999, minid = 0;
	ll maxminues = -9999999, maxidm = 0;
	ll minminues = 9999999, minidm = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		if (a[i].x + a[i].y > maxplus) {
			maxplus = a[i].x + a[i].y;
			maxid = i;
		}
		else if (a[i].x + a[i].y < minplus) {
			minplus = a[i].x + a[i].y;
			minid = i;
		}
		if (a[i].x - a[i].y > maxminues) {
			maxminues = a[i].x - a[i].y;
			maxidm = i;
		}
		else if (a[i].x - a[i].y < minminues) {
			minminues = a[i].x - a[i].y;
			minidm = i;
		}
	}
	//
	ll a1 = abs(a[maxid].x - a[minid].x) + abs(a[maxid].y - a[minid].y);
	ll a2 = abs(a[maxidm].x - a[minidm].x) + abs(a[maxidm].y - a[minidm].y);
	cout << max(a1, a2);
}
