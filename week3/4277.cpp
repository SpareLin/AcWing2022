/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/30 9:38
* @Description: 4277. 区块反转 来源：PAT甲级真题1165
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 4;

struct Node {
    int data, next;
}node[MAXN];

int main() {
    int addreFirst, n, k;
    scanf("%d%d%d", &addreFirst, &n, &k);
    while (n--) {
        int addre;
        scanf("%d", &addre);
        scanf("%d%d", &node[addre].data, &node[addre].next);
    }
    vector<int> v;
    for (int i = addreFirst; i != -1; i = node[i].next) {
        v.push_back(i);
    }
    /*
    for (int i = 0; i < v.size(); i += k) {
        reverse(v.begin() + i, min(v.begin() + i + k, v.end()));
    }
    reverse(v.begin(), v.end());
     */
    reverse(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i -= k) {
        reverse(v.begin() + max(0, i - k + 1), v.begin() + i + 1);
    }
    for (int i = 0; i < v.size() - 1; ++i) {
        printf("%05d %d %05d\n", v[i], node[v[i]].data, v[i + 1]);
    }
    printf("%05d %d -1\n", v[v.size() - 1], node[v[v.size() - 1]].data);
    return 0;
}