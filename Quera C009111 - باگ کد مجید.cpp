#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int a[N];
bool seen[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int pos1, pos2;
	pos1 = pos2 = -1;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		seen[a[i]] = true;
		if (a[i] == 1)
			pos1 = i;
		else if (a[i] == 2)
			pos2 = i;
	}
	for (int i = n - 1;i >= 0;i--)
	{
		if (a[i] == 0)
			if (pos1 == -1)
			{
				a[i] = 1;
				pos1 = i;
			}
			else if (pos2 == -1)
			{
				a[i] = 2;
				pos2 = i;
			}
	}
	if (pos2 > pos1 || pos1 != n - 1)
		cout << "No\n";
	else
	{
		cout << "Yes\n";
		seen[1] = seen[2] = true;
		vector<int>unseens;
		for (int i = 1;i <= n;i++)
			if (!seen[i])
				unseens.push_back(i);
		for (int i = 0;i < n;i++)
			if (a[i] == 0)
			{
				a[i] = unseens.back();
				unseens.pop_back();
			}
		for (int i = 0;i < n;i++)
			cout << a[i] << ' ';
	}
}
