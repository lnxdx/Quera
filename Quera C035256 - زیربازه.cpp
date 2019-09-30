// ITNOA
// O(n.log(n)) Binary Search
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int INF = 2e9;
const int N = 3e5 + 35;
ll W;
ll psum[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n >> W;
	for (int i = 1;i <= n;i++)
	{
		ll w;
		cin >> w;
		psum[i] = psum[i - 1] + w;
	}
	ll ans = 0;
	set<ll>st;
	for (int i = 0;i <= n;i++)
	{
		auto it = st.lower_bound(psum[i] - W);
		if (it != st.end())
			ans = max(ans, psum[i] - *it);
		st.insert(psum[i]);
	}
	cout << ans;
}
