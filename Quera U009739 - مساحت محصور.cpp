// ITNOA
// O(n) using stack
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 6;
ll h[N];
int l[N], r[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> h[i];
	stack<pair<int, ll>>stk;
	stk.push({ -1,-1 });
	for (int i = 0;i < n;i++)
	{
		while (stk.top().second >= h[i])
			stk.pop();
		l[i] = stk.top().first;
		stk.push({ i,h[i] });
	}
	while (stk.size())
		stk.pop();
	stk.push({ n,-1 });
	for (int i = n - 1;i >= 0;i--)
	{
		while (stk.top().second >= h[i])
			stk.pop();
		r[i] = stk.top().first;
		stk.push({ i,h[i] });
	}
	ll ans = 0;
	for (int i = 0;i < n;i++)
		ans = max(ans, (r[i] - l[i] - 1)*h[i]);
	cout << ans;
}
