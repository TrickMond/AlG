#include <bits/stdc++.h>

using namespace std;

struct treeNode
{
    int val;
    treeNode* lCh;
    treeNode* rCh;
};

class binaryTree
{
    treeNode* root;
    binaryTree();
};

binaryTree::binaryTree()
{
    treeNode* newNode = new treeNode;
    newNode->val = 0;
    newNode->lCh = nullptr;
    newNode->rCh = nullptr;
}

int main()
{
    int n, leftCh, rightCh;
    scanf ("%d",n);
    scanf("%d");
	return 0;
}
