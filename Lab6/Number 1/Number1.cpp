#include <bits/stdc++.h>

using namespace std;

struct inputedNode
{
    long val;
    long leftCh;
    long rightCh;
};
vector <inputedNode> inNode;
int bypassBinaryTree(int v)
{
    int hei = 1;
    if (inNode[v].leftCh != 0)
        hei = max(hei, bypassBinaryTree(inNode[v].leftCh) + 1);
    if (inNode[v].rightCh != 0)
        hei = max(hei, bypassBinaryTree(inNode[v].rightCh) + 1);
    return hei;
}

int main()
{
    freopen ("height.in","r",stdin);
    freopen ("height.out","w",stdout);
    inNode.resize(200010);
    setlocale(LC_ALL,"RUS");
    int n;
    scanf ("%d",&n);
    if (n == 0) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d",&inNode[i].val,&inNode[i].leftCh,&inNode[i].rightCh);
    }
    for (int i = 1; i <= n; i++)
        if (u[i] != 1)
            printf("%d", bypassBinaryTree(i));
    return 0;
}
