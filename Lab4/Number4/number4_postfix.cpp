#include <bits/stdc++.h>

using namespace std;

char c[10001]; // ���� �� ��������
int rB = -1; // ��������� �� ����� �����
bool isEmpty() // �������, ����������� ���������� �� ����
{
    return rB == -1;

}

void push(char ch) // ���������� � ���� �������
{
    rB++;
    c[rB] = ch;
}

int pop() // ���� ���� �� ���� ������� �������
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
