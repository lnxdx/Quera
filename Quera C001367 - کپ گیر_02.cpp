// ITNOG
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<string> >s[3];

void init_vec(int text, int sent, int word)
{
	if ((int)s[text].size() - 1 != sent)
		s[text].push_back(vector<string>());
	if ((int)s[text][sent].size() - 1 != word)
		s[text][sent].push_back("");
}
void add(char c, int text, int sent, int word)
{
	init_vec(text, sent, word);
	c = tolower(c);
	s[text][sent][word] += c;
}
int main()
{
	int text, sent, word;
	text = sent = word = 0;
	char c;
	while ((c = getchar()) != -1)
	{
		if (c == '*')
		{
			sent = word = 0;
			text++;
		}
		else if (c == ' ' || c == '\n' || c == ',')
		{
			if ((int)s[text].size() - 1 == sent)
				word = s[text][sent].size();
			else
				word = 0;
		}
		else if (c == '.')
		{
			word = 0;
			sent = s[text].size();
		}
		else
			add(c, text, sent, word);
	}
	text++;

	for (int i = 0;i<text;i++)
		for (int j = 0;j < s[i].size();j++)
			sort(s[i][j].begin(), s[i][j].end());

	for (int i = 0;i<text;i++)
		sort(s[i].begin(), s[i].end());

	bool equal = s[0].size() == s[1].size();
	for (int i = 0;equal && i < s[0].size();i++)
		if (s[0][i] != s[1][i])
			equal = false;

	if (equal)
		cout << "this is cop\n";
	else
		cout << "this is not cop\n";
}
