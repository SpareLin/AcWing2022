/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/28 14:28
* @Description: PAT (Advanced Level) 1162 Postfix Expression
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 25;

typedef struct {
    int l, r;   //左右孩子
    string v;   //权值
} Node;

Node node[MAXN];
int n, root, flag[MAXN];

void dfs(int index) {
    cout << '(';
    //左右孩子都不存在 直接输出节点权值
    if (node[index].l == -1 && node[index].r == -1) {
        cout << node[index].v;
    }
        //左右孩子都存在 则进行后序遍历
    else if (node[index].l != -1 && node[index].r != -1) {
        dfs(node[index].l);
        dfs(node[index].r);
        cout << node[index].v;
    }
        //样例中的-作为负号时 进行先序遍历 即左孩子不存在 右孩子存在 先访问节点权值再访问右孩子
    else {
        cout << node[index].v;
        dfs(node[index].r);
    }
    cout << ')';
}

string DFS(int index) {
    if(node[index].l == -1 && node[index].r == -1) {
        return "(" + node[index].v + ")";
    }
    if(node[index].l != -1 && node[index].r != -1) {
        return "(" + DFS(node[index].l) + DFS(node[index].r) + node[index].v + ")";
    }
    if(node[index].l == -1 && node[index].r != -1) {
        return "(" + node[index].v + DFS(node[index].r) + ")";
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> node[i].v >> node[i].l >> node[i].r;
        if (node[i].l != -1) flag[node[i].l] = 1;  //当前结点左孩子是否存在
        if (node[i].r != -1) flag[node[i].r] = 1;  //当前结点右孩子是否存在
    }
    //遍历找根节点
    for (int i = 1; i <= n; ++i) {
        if (flag[i] == 0) {
            root = i;
        }
    }

    //dfs(root);

    cout << DFS(root);

    return 0;
}

