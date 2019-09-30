#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
char g[N][N];
int seen[N][N];
bool is_in_stack[N][N];
int n, m;
int nex['Z' + 10];
int dir[] = { 1,0,0,1,1,2,2,1 };
int MAX[N][N];
bool is_cyc(int u, int v)
{
	if (is_in_stack[u][v])
	{
		is_in_stack[u][v] = 0;
		return 1;
	}
	if (seen[u][v])
		return 0;
	seen[u][v] = is_in_stack[u][v] = 1;
	for (int i = 0;i < 8;i += 2)
	{
		int uu, vv;
		uu = u + dir[i] - 1;
		vv = v + dir[i + 1] - 1;
		if (nex[g[u][v]] == g[uu][vv])
			if (is_cyc(uu, vv))
			{
				is_in_stack[u][v] = 0;
				return 1;
			}
	}
	is_in_stack[u][v] = 0;
	return 0;
}
int dfs(int u, int v)
{
	if (seen[u][v])
		return MAX[u][v];
	seen[u][v] = 1;
	int dep = 1;
	for (int i = 0;i < 8;i += 2)
	{
		int uu, vv;
		uu = u + dir[i] - 1;
		vv = v + dir[i + 1] - 1;
		if (nex[g[u][v]] == g[uu][vv])
			dep = max(dep, dfs(uu, vv) + 1);
	}
	return MAX[u][v] = dep;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string eidy = "EYDI";
	for (int i = 0;i < 4;i++)
		nex[eidy[i]] = eidy[(i + 1) % 4];
	while (cin >> n >> m)
	{
		//memset(g, 0, sizeof g);
		//memset(seen, 0, sizeof seen);
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				cin >> g[i][j];
		bool cyc = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if (g[i][j] == 'E' && !seen[i][j] && is_cyc(i, j))
				{
					cout << "Poor Uncle!\n\n";
					cyc = 1;
					i = j = n + m;
				}
		if (!cyc)
		{
			memset(seen, 0, sizeof seen);
			int ans = 0;
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= m;j++)
					if (g[i][j] == 'E' && !seen[i][j])
						ans = max(ans, dfs(i, j));
			if (ans / 4)
				cout << ans / 4; // << ' ' << ans;
			else
				cout << "Poor Mobin!"; // << ' ' << ans;
			cout << "\n\n";
		}
	}
}
