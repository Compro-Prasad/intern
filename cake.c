#include <bits/stdc++.h>

using namespace std;

int lost_cake(int N, int E, int S, int D, int A[40001], int B[40001])
{
  vector<int> arr[10001];
  for (int i = 0; i < E; ++i) {
      arr[A[i]].push_back(B[i]);
      arr[B[i]].push_back(A[i]);
  }
  int path = 0;
  queue<int> q;
  vector<bool> nodes(0);
  q.push(S);
  for (int i = S; i != D && !q.empty();) {
    path++;
    for (vector<int>::iterator j = arr[i].begin(); j != arr[i].end(); ++j) {
      if (nodes[*j] == 0) {
        q.push(*j);
        nodes[*j] = 1;
      }
      if (*j == D)
        return path;
    }
    q.pop();
    i = q.front();
  }
  return path;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, e, s, d;
        int a[40001], b[40001];
        scanf("%d%d%d%d", &n, &e, &s, &d);
        for (int i = 0; i < e; ++i)
            scanf("%d%d", a + i, b + i);
        printf("%d\n", lost_cake(n, e, s, d, a, b));
    }
    return 0;
}
