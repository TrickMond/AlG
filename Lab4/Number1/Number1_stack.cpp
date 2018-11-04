#include <bits/stdc++.h>

using namespace std;

int rightB = -1, // указатель на крайний элемент стека
    v[1000001]; // стек

void push (int value) // функция, добавления элемента в конец стека
{
    rightB++;
    v[rightB] = value;
}

void pop() // функция, удаления элемента из конца стека, и вывода этого элемента на экран / в файл
{
    printf("%d\n", v[rightB]);
    rightB--;
}


int main()
{
    char s;
    freopen ("stack.in","r",stdin);
    freopen("stack.out","w",stdout);
    int number,value;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        scanf("\n%c", &s);
        if (s=='+') // Если встречаем +, считываем еще стоку
        {
            scanf("%d", &value);
            push (value);
        } else
        {
            pop(); // Иначе удаляем элемент
        }
    }
    return 0;
}
