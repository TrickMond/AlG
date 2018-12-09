#include <stdio.h>
#include <vector>

using namespace std;

struct inputedNode
{
    long val;
    long leftCh;
    long rightCh;
};
vector <inputedNode> inNode;



bool bypassBinaryTree(int v)
{
    bool b = 0;


    if (inNode[v].leftCh != 0)
        if (inNode[v].val > inNode[inNode[v].leftCh].val)

        {
            b = (b && bypassBinaryTree(inNode[v].leftCh));
            printf (">Roots value: %d LeftChild value: %d Ifs value: %d\n",inNode[v].val, inNode[inNode[v].leftCh].val, b);
        }
        else
        {
            return 0;
        }




    if (inNode[v].rightCh != 0)
        if (inNode[v].val < inNode[inNode[v].rightCh].val)
        {
            b = (b && bypassBinaryTree(inNode[v].rightCh));
            printf ("Roots value: %d RightChild value: %d Ifs value: %d\n",inNode[v].val, inNode[inNode[v].rightCh].val, b);
        }
        else
        {
            return 0;
        }
    return b;
}




int main()
{
//    freopen ("check.in","r",stdin);
//    freopen ("check.out","w",stdout);
    inNode.resize(200010);
    int n;
    scanf ("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d",&inNode[i].val,&inNode[i].leftCh,&inNode[i].rightCh);
    }
        if (bypassBinaryTree(1) == 1)
            puts("YES");
        else
            puts("NO");
    return 0;
}
