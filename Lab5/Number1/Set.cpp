#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int tabbleSize = 100000;
struct Node //knot
{
    int Value;
    Node *Next;
};

class List
{
    //squares
    Node *Start; //pointer for the first knot of the list

public:


    //Methods
    List(); //Constructor
    void Insert(int data);
    void Delete(int data);
    bool Search(int data);
};

List::List()
{
    Start = new Node(); // Started knot
    Start->Value = 0;
    Start->Next = nullptr; //Pointer is pointing to NULL
}

void List::Insert(int data)
{
    Node *NewNode = new Node;
    NewNode->Value = data;
    NewNode->Next = Start->Next; //NewNode is pointing for the Start pointer
    Start->Next = NewNode; //Start is pointing for the NewNode
}

void List::Delete(int data)
{
    Node *CurNode = Start;  // CurNode is pointing for Start of the List
    while (CurNode->Next != nullptr) //walking for list
    {
        if (CurNode->Next->Value == data)
        {
            Node *NodeToDel = CurNode->Next;
            CurNode->Next = CurNode->Next->Next;
            delete NodeToDel;
            return;
        }
        else
        {
            CurNode = CurNode->Next; // goto next
        }
    }
}

bool List :: Search(int data)
{
    Node *CurNode = Start;
    while (CurNode->Next != nullptr)
    {
        if (CurNode->Next->Value == data)
        {
        return true;
        }
        else
        {
        CurNode = CurNode->Next;
        }
    }
    return false;
}

class Set
{
    //square
    vector<List> vectorSet; //our LIST

    //methods
    int hashFunction(int data); // our hashFunction
public:
    Set();//Constructor
    void Insert(int data);
    bool Search(int data);
    void Delete(int data);
};

Set::Set()
{
    vectorSet.resize(100000);//set size of vector
}

int Set::hashFunction(int data)//Create hash for SET
{
    int hashValue = data ^ (data >> 16)%(int)vectorSet.size();
    return hashValue;
}

void Set::Insert(int data)
{
    if (!Search(data)) //If value x no in the LIST
        vectorSet[hashFunction(data)].Insert(data);
}

bool Set::Search(int data)
{
    return vectorSet[hashFunction(data)].Search(data); //Search just in list with that hashFunctionValue
}

void Set::Delete(int data)
{
    vectorSet[hashFunction(data)].Delete(data);
}

int main()
{
    Set Set;
    string Command;
    int x;

//    freopen("set.in","r",stdin);
//    freopen("set.out","w",stdout);
    while (cin >> Command)
    {
        if (Command == "insert")
        {
        scanf("%d",&x);
        Set.Insert(x);
        }
        else
            if (Command == "delete")
        {
            scanf("%d",&x);
            Set.Delete(x);
        }
        else
            if (Command == "exists")
        {
            scanf("%d",&x);
            if (Set.Search(x))
                printf("true\n");
            else
                printf("false\n");
        }
    }
    return 0;
}
