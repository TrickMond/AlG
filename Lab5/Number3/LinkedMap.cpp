#include <bits/stdc++.h>


using namespace std;
const int tabbleSize = 1000;

struct Node
{
	string nodeKey;
	string nodeValue;
	Node *NextInChain;
	Node *Next, *Prev;
};

class List
{
	Node *Start;
public:
	List();
	void Insert(string key, string value, Node *Head);
	void Delete(string key, Node *Head);
	Node* Search(string key);
};

List::List()
{
	Start = new Node();
	Start->nodeValue ="";
    Start->nodeKey = "";
	Start->NextInChain = nullptr;
}

Node* List::Search(string K)
{
	Node *CurNode = Start;
	while (CurNode->NextInChain != nullptr)
	{
		if (CurNode->NextInChain->nodeKey == K)
		{
			return CurNode->NextInChain;
		}
		else
		{
			CurNode = CurNode->NextInChain;
		}
	}
	return nullptr;
}

void List::Insert(string key, string value, Node *Head)
{
	Node *NewNode = Search(key);
	if (Search(key) == nullptr)
	{
		NewNode = new Node;
		NewNode->nodeKey = key;
		NewNode->nodeValue = value;
		NewNode->NextInChain = Start->NextInChain;
		Start->NextInChain = NewNode;
		Node *Tail = Head->Prev;
		Tail->Next = NewNode;
		Head->Prev = NewNode;
		NewNode->Next = Head;
		NewNode->Prev = Tail;
	}
	else
	{
		NewNode->nodeValue = value;
	}
}

void List::Delete(string K, Node *Head)
{
	Node *CurNode = Start;
	while (CurNode->NextInChain != nullptr)
	{
		if (CurNode->NextInChain->nodeKey == K)
		{
			Node *NodeToDel = CurNode->NextInChain;
			CurNode->NextInChain = CurNode->NextInChain->NextInChain;
			Node *PrevNode = NodeToDel->Prev, *NextNode = NodeToDel->Next;
			NodeToDel->Prev->Next = NextNode;
			NodeToDel->Next->Prev = PrevNode;
			delete NodeToDel;
			return;
		}
		else
		{
			CurNode = CurNode->NextInChain;
		}
	}
}



class LinkedMap
{
	vector<List> vectorLink;
	Node *Head;
	int hashF(string key);
public:
	LinkedMap();
	void Insert(string key, string value);
	void Delete(string key);
	string Search(string key);
	string Next(string key);
	string Prev(string key);
	void Print()
	{
		Node *CurNode = Head->Next;
		while (CurNode != Head)
		{
			CurNode = CurNode->Next;
		}
	}
};

LinkedMap::LinkedMap()
{
	vectorLink.resize(tabbleSize);
	Head = new Node;
	Head->Next = Head->Prev = Head;
	Head->nodeValue = "HEAD";
    Head->nodeKey = "HEAD";
}

int LinkedMap::hashF(string key)
{
	unsigned int hashV = 0, pow = 1, seed = 11;
	for (int i = 0; i < key.length(); ++i)
	{
		hashV += (key[i] - 'A') * pow;
		pow *= seed;
	}
	return hashV % tabbleSize;
}

void LinkedMap::Insert(string key, string value)
{
	vectorLink[hashF(key)].Insert(key, value, Head);
}

string LinkedMap::Search(string key)
{
	Node *Pointer = vectorLink[hashF(key)].Search(key);
	if (Pointer== nullptr)
		return "none";
	else
		return Pointer->nodeValue;
}

void LinkedMap::Delete(string key)
{
	vectorLink[hashF(key)].Delete(key, Head);
}

string LinkedMap::Next(string key)
{
	Node *Pointer= vectorLink[hashF(key)].Search(key);
	if (Pointer== nullptr || Pointer->Next == Head)
		return "none";
	else
		return Pointer->Next->nodeValue;
}

string LinkedMap::Prev(string key)
{
	Node *Pointer= vectorLink[hashF(key)].Search(key);
	if (Pointer== nullptr || Pointer->Prev == Head)
		return "none";
	else
		return Pointer->Prev->nodeValue;
}

int main()
{
	ifstream fin("linkedmap.in");
	ofstream fout("linkedmap.out");
	LinkedMap LM;
	string Command;
	while (fin >> Command)
	{
		string key, value;
		if (Command == "put")
		{
			fin >> key >> value;
			LM.Insert(key, value);
		}
		else if (Command == "delete")
		{
			fin >> key;
			LM.Delete(key);
		}
		else if (Command == "get")
		{
			fin >> key;
			fout << LM.Search(key) << "\n";
		}
		else if (Command == "next")
		{
			fin >> key;
			fout << LM.Next(key) << "\n";
		}
		else if (Command == "prev")
		{
			fin >> key;
			fout << LM.Prev(key) << "\n";
		}
	}
	return 0;
}
