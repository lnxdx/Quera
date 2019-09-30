#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int a[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	vector<int>ans;
	for (int i = n - 1;i >= 0;i--)
		ans.insert(ans.begin() + a[i], i);
	cout << ans.front() + 1;
	for (int i = 1;i < ans.size();i++)
		cout << ',' << ans[i] + 1;
}
