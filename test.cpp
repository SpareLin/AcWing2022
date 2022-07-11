#include <iostream>

using namespace std;

const int N = 10;
int n, q[N];
bool st[N];

void dfs(int u)
{
    if(u == n)
    {
        for (int i = 0; i < n; ++i) {
            cout << q[i] << ' ';
        }
        cout << '\n';
        return ;
    }

    for (int i = 1; i <= n; i++) {
        if(!st[i])
        {
            q[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;

    dfs(n);

    return 0;
}