// ITNOA
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
const int N = 1e3 + 10;
int INF = 1e8;
string s[N];
int adj[N][N];
int pre[N][N];
int n, l;
void floyd()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					pre[i][j] = k;
					adj[i][j] = adj[i][k] + adj[k][j];
				}
}
void path(int i, int j, vector<string>&v)
{
	if (pre[i][j] != -1)
	{
		path(i, pre[i][j], v);
		v.push_back(s[pre[i][j]]);
		path(pre[i][j], j, v);
	}
}
bool dif1(string a, string b)
{
	bool seena['z' + 10] = { 0 }, seenb['z' + 10] = { 0 };
	for (int i = 0;i < a.size();i++)
		for (int j = 0;j < b.size();j++)
			if (!seena[i] && !seenb[j] && a[i] == b[j])
				seena[i] = seenb[j] = 1;
	int cnt = 0;
	for (int i = 0;i < l;i++)
		cnt += (seena[i] == 0);
	return cnt == 1;
}
bool diffall(string a, string b)
{
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
			if (a[i] == b[j])
				return 0;
	return 1;
}
int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			pre[i][j] = pre[j][i] = -1;
			if (i != j)
				adj[i][j] = adj[j][i] = INF;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i - j && dif1(s[i], s[j]))
			{
				adj[i][j] = adj[j][i] = 1;
			}
	floyd();
	int ans = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (diffall(s[i], s[j]))
				ans = min(ans, adj[i][j]);
	string ansn = string(30, 'z');
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n;j++)
				if (diffall(s[i], s[j]) && i - j && ans == adj[i][k] + adj[k][j])
				{
					vector<string>v;
					v.push_back(s[i]);
					path(i, k, v);
					v.push_back(s[k]);
					path(k, j, v);
					v.push_back(s[j]);
					v.resize(unique(v.begin(), v.end()) - v.begin());
					string nard;
					for (int i = 0; i < v.size(); i++)
						for (int j = 0; j < l; j++)
							nard += v[i][j];
					ansn = (min(ansn, nard));
				}
	int K = 0;
	for (int i = 0; i < ansn.size(); i++)
	{
		if (i%l == 0 && i)
			cout << " ";
		cout << ansn[i];
	}
}
