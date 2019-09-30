#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 141072;
#define ll long long
int a[MAXN];

//sum and max till now
pair<ll, int> dq(int start, int end) {
	if (end - start == 1)
		return make_pair(a[start] + a[end], max(a[start], a[end]));

	int mid = (end + start) / 2;
	pair<ll, int> s1 = dq(start, mid);
	pair<ll, int> s2 = dq(mid + 1, end);
	ll k1 = s1.first + s2.second;
	ll k2 = s2.first + s1.second;
	return make_pair(max(k1, k2), max(s1.second, s2.second));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int k = 1;
	for (int i = 1; i <= n; i++)
		k *= 2;
	for (int i = 0; i < k; i++)
		cin >> a[i];
	cout << dq(0, k - 1).first;
}
