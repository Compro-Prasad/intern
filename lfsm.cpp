#include <bits/stdc++.h>

using namespace std;

int maxDiameterSum(int nodes, int tree[511])
{
    int height = 0;
    int max = -10000000, next_max = -10000000;
    for (int i = nodes; i; height++, i >>= 1);
    for (int i = 1 << (height - 1); i < nodes; ++i) {
        if (tree[i] < tree[i + 1])
            max = tree[i + 1];
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, tree[512];
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", tree + i);
        printf("%d\n", maxDiameterSum(n, tree));
    }
    return 0;
}
