#include <bits/stdc++.h>

using namespace std;

char c[10001];
int rB = -1;

bool isEmpty()
{
    return rB == -1;

}

void push(char ch)
{
    rB++;
    c[rB] = ch;
}

void pop()
{
    if (!isEmpty())
        rB--;
}

bool check(string s)
{
    char t;
    rB = -1;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '(' || s[i] == '[')
            push(s[i]);
        else if (s[i] == ')' && c[rB] == '(' || s[i] == ']' && c[rB] == '[')
        {
            pop();
        }
        else
        {
			return false;
        }
    if (isEmpty())
    {
        return true;
    }
    else
        return false;
}

int main()
{
    bool checked;
    string str;
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
	while (cin >> str)
	{
		if (check(str))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
