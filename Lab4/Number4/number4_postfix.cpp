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

int pop() // Если стек не пуст удаляет элемент
{
    int i = c[rB];
    rB--;
    return i;
}

int main ()
{
    string s;
    int res = 0;


}
