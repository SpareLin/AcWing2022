/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/6 22:32
* @Description: 3587. 连通图 来源：吉林大学考研机试题
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e3 + 7;
int g[MAXN][MAXN], n, m;
bool vis[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int i = 1; i <= n; ++i) {
        if(!vis[i] && g[i][u] != 0)
            dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(cin >> n >> m) {
        fill(g[0], g[0] + MAXN * MAXN, 0);
        fill(vis, vis + MAXN, false);
        while(m--) {
            int x, y;
            cin >> x >> y;
            g[x][y] = g[y][x] = 1;
        }
        dfs(1);
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "NO\n" : "YES\n");
    }
    return 0;
}