/*依次判断每个结点的父节点是否相同*/

#include <iostream>

using namespace std;

const int MAXN = 1e3 + 7;
int p[MAXN], n, m;

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    while(cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        while(m--) {
            int x, y;
            cin >> x >> y;
            int fx = find(x), fy = find(y);
            if(fx != fy) p[fx] = fy;
        }
        bool flag = false;
        int ans = p[find(1)];
        for (int i = 2; i <= n; ++i) {
            if(p[find(i)] != ans) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "NO\n" : "YES\n");
    }
    return 0;
}