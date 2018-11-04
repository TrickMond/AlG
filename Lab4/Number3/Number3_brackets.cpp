#include <bits/stdc++.h>

using namespace std;

char c[10001]; // стек из символов
int rB = -1; // указатель на конец стека

bool isEmpty() // функция, проверяющая закончился ли стек
{
    return rB == -1;

}

void push(char ch) // добавление в стек символа
{
    rB++;
    c[rB] = ch;
}

void pop() // Если стек не пуст удаляет элемент
{
    if (!isEmpty())
        rB--;
}

bool check(string s) // проверка скобок
{
    char t;
    rB = -1;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '(' || s[i] == '[') // если открывающие скобки, то закидываем в стек
            push(s[i]);
        else if (s[i] == ')' && c[rB] == '(' || s[i] == ']' && c[rB] == '[') // иначе, проверяем верхний элемент стека, и заданую закрывающую скобку, если они одинаковы, то удаляем верхний эл. стека, иначе ошибка
        {
            pop();
        }
        else
        {
			return false;
        }
    if (isEmpty()) // если дошли до конца и файл оказался пуст, то возвращаем 1, иначе 0
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
