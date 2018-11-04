#include <bits/stdc++.h>

using namespace std;

int c[10001]; // ���� �� �����
int rB = -1; // ��������� �� ����� �����

void push(int ch) // ���������� � ���� �����
{
    rB++;
    c[rB] = ch;
}

int pop() // �������� + ����������� �����
{
    int i = c[rB];
    rB--;
    return i;
}

int main ()
{
    string s;
    freopen("postfix.in","r",stdin);
    freopen("postfix.out","w",stdout);
    while (cin >> s)
    {
        int res = 0, var1, var2;
        if (s[0] - 48 >= 0) // ���� ����� �������� ������, ��
        {
            push (s[0] - 48); // ����� �����
        }
        else //���� ���, �� ��������� ��������
        {
            var2 = pop ();
            var1 = pop ();
            switch (s[0])
            {
                case '+':
                    res = var1 + var2;
                    push(res);
                    break;

                case '-':
                    res = var1 - var2;
                    push(res);
                    break;

                case '*':
                    res = var1 * var2;
                    push(res);
                    break;

                case '/':
                    res = var1 / var2;
                    push(res);
                    break;

            }

        }

    }
    cout << pop();
    return 0;

}
