#include <bits/stdc++.h>

using namespace std;
const int tablleSize = 1000;

struct Node
{
	string nodeKey, nodeValue;
	Node *Next;
};

class List
{
	Node *Start;
public:
	List();
	void Insert(string key, string valuealue);
	void Delete(string key);
	Node* Search(string key);
};

List::List()
{
	Start = new Node();
	Start->nodeValue ="";
    Start->nodeKey = "";
	Start->Next = nullptr;
}

void List::Insert(string key, string value)
{
	Node *NewNode = Search(key);
	if (Search(key) == nullptr)
	{
		NewNode = new Node;
		NewNode->nodeKey = key;
		NewNode->nodeValue = value;
		NewNode->Next = Start->Next;
		Start->Next = NewNode;
	}
	else
	{
		NewNode->nodeValue = value;
	}
}

void List::Delete(string key)
{
	Node *CurNode = Start;
	while (CurNode->Next != nullptr)
	{
		if (CurNode->Next->nodeKey == key)
		{
			Node *NodeToDel = CurNode->Next;
			CurNode->Next = CurNode->Next->Next;
			delete NodeToDel;
			return;
		}
		else
		{
			CurNode = CurNode->Next;
		}
	}
}

Node* List::Search(string key)
{
	Node *CurNode = Start;
	while (CurNode->Next != nullptr)
	{
		if (CurNode->Next->nodeKey == key)
		{
			return CurNode->Next;
		}
		else
		{
			CurNode = CurNode->Next;
		}
	}
	return nullptr;
}

class Map
{
	vector<List> vectorMap;
	int hashF(string key);
public:
	Map();
	void Insert(string key, string value);
	void Delete(string key);
	string Search(string key);
};

Map::Map()
{
	vectorMap.resize(tablleSize);
}

int Map::hashF(string key)
{
	unsigned int HashV = 0, pow = 1, seed = 11;
	for (int i = 0; i < key.length(); ++i)
	{
		HashV += (key[i] - 'A') * pow;
		pow *= seed;
	}
	return HashV % tablleSize;
}

void Map::Insert(string key, string value)
{
	vectorMap[hashF(key)].Insert(key, value);
}

string Map::Search(string key)
{
	Node *Res = vectorMap[hashF(key)].Search(key);
	if (Res == nullptr)
		return "none";
	else
		return Res->nodeValue;
}

void Map::Delete(string key)
{
	vectorMap[hashF(key)].Delete(key);
}

int main()
{
    ifstream fin("map.in");
    ofstream fout("map.out");
	Map Map;
	string Command;
	while (fin >> Command)
	{
		string key, value;
		if (Command == "put")
		{
			fin >> key >> value;
			Map.Insert(key, value);
		}
		else if (Command == "delete")
		{
			fin >> key;
			Map.Delete(key);
		}
		else if (Command == "get")
		{
			fin >> key;
			fout<< Map.Search(key) << "\n";
		}
	}
	return 0;
}
