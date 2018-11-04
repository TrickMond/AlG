#include <bits/stdc++.h>

using namespace std;

int c[10001]; // стек из чисел
int rB = -1; // указатель на конец стека

void push(int ch) // добавление в стек числа
{
    rB++;
    c[rB] = ch;
}

int pop() // удаление + возвращение числа
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
        if (s[0] - 48 >= 0) // Если стока является числом, то
        {
            push (s[0] - 48); // Пушим число
        }
        else //Если нет, то выполняем операцию
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
