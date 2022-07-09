/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/1 11:46
* @Description: 4278. 峰会 来源：PAT甲级真题1166
*/

#include <iostream>

using namespace std;

const int MAXN = 210;
int n, m, k;
bool g[MAXN][MAXN]; //邻接矩阵
int arr[MAXN];    //休息区

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }

    cin >> k;   //k个区域

    for (int i = 1; i <= k; ++i) {
        int l;  //l个首脑
        cin >> l;
        for (int j = 0; j < l; ++j) {
            cin >> arr[j];
        }
        //如果安排无法满足其中的任意两人之间都是直接朋友关系，则输出 Area X needs help.
        bool flag = false;   //判断是否满足
        for (int j = 0; j < l - 1; ++j) {
            for (int k = j + 1; k < l; ++k) {
                if (!g[arr[j]][arr[k]])  //如果arr[j] arr[k]不是朋友
                    flag = true;
            }
        }
        if (flag) {
            cout << "Area " << i << " needs help.\n";
            continue;
        }

        flag = false;   //能否安排更多的人在这一区域休息
        int id; //安排的人的编号
        for (int j = 1; j <= n; ++j) {
            bool f = true;
            for (int k = 0; k < l; ++k) {
                if (!g[j][arr[k]]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                flag = true, id = j;
                break;
            }
        }
        if (flag) cout << "Area " << i << " may invite more people, such as " << id << ".\n";
        else cout << "Area " << i << " is OK.\n";
    }
    return 0;
}