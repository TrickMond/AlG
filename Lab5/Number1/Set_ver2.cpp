#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Node
{
    int Value;
    Node *pNext;
};

class List
{
    Node *Start;
public:
    List();
    void Insert(int x);
    void Delete(int x);
    bool Search(int x);
};





List::List()
{
    Start = new Node();
    Start->Value = 0;
    Start->pNext = nullptr;
}

void List::Insert(int x)
{
    Node *NewNode = new Node;
    NewNode->Value = x;
    NewNode->pNext = Start->pNext;
    Start->pNext = NewNode;
}


void List::Delete(int x)
{
    Node *current = Start;
    while (current->pNext != nullptr)
    {
        if (current->pNext->Value == x)
            {
            Node *NodeToDel = current->pNext;
            current->pNext = current->pNext->pNext;
            delete NodeToDel;
            return;
            }
        else
            {
            current = current->pNext;
            }
    }
}
bool List :: Search(int x)
{
    Node *current = Start;
    while (current->pNext != nullptr)
    {
        if (current->pNext->Value == x)
        {
            return true;
        }
        else
        {
            current = current->pNext;
        }
    }
    return false;
}








class Set
{
    vector<List> vectorSet;
    int HashFunction(int x);
public:
    Set();
    void Insert(int x);
    bool Search(int x);
    void Delete(int x);
};






Set::Set()
{
    vectorSet.resize(100000);
}

int Set::HashFunction(int x)
{
    int res = x % (int)vectorSet.size();
    if (res < 0)
        res += vectorSet.size();
    return res;
}

void Set::Insert(int x)
{
    if (!Search(x)) vectorSet[HashFunction(x)].Insert(x);
}

bool Set::Search(int x)
{
    return vectorSet[HashFunction(x)].Search(x);
}

void Set::Delete(int x)
{
    vectorSet[HashFunction(x)].Delete(x);
}

int main()
{
    ifstream fin("set.in");
    ofstream fout("set.out");
    Set Set;
    string Command;
    while (fin >> Command)
    {
        int x;
        if (Command == "insert")
        {
            fin >> x;
            Set.Insert(x);
        }
        else
            if (Command == "delete")
            {
            fin >> x;
            Set.Delete(x);
            }
        else
            if (Command == "exists")
        {
            fin >> x;
            if (Set.Search(x))
            fout << "true" << endl; else
            fout << "false" << endl;
        }
    }
    return 0;
}
