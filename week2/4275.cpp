/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/28 18:44
* @Description: 4275. Dijkstra���� ��Դ��PAT�׼�����1163
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3 + 7;
int n, m; //��ͱ�
int dis[MAXN], g[MAXN][MAXN];
bool vis[MAXN];
int q[MAXN];//���������

bool Dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    dis[q[0]] = 0;

    for (int i = 0; i < n; ++i) {
        int t = q[i];
        for (int j = 1; j <= n; ++j) {
            //����ǰ��û�����ʹ��Ҵ���һ����ȵ�ǰ���С
            if (!vis[j] && dis[j] < dis[t]) {
                return false;
            }
        }
        vis[t] = true;
        //���µ�ǰ���ĵ�
        for (int j = 1; j <= n; ++j) {
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    while (m--) {
        int x, y, val;
        scanf_s("%d%d%d", &x, &y, &val);
        g[x][y] = g[y][x] = val;
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &q[i]);
        }
        printf(Dijkstra() ? "Yes\n" : "No\n");
    }
    return 0;
}
