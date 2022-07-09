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
    int l, r;   //���Һ���
    string v;   //Ȩֵ
} Node;

Node node[MAXN];
int n, root, flag[MAXN];

void dfs(int index) {
    cout << '(';
    //���Һ��Ӷ������� ֱ������ڵ�Ȩֵ
    if (node[index].l == -1 && node[index].r == -1) {
        cout << node[index].v;
    }
        //���Һ��Ӷ����� ����к������
    else if (node[index].l != -1 && node[index].r != -1) {
        dfs(node[index].l);
        dfs(node[index].r);
        cout << node[index].v;
    }
        //�����е�-��Ϊ����ʱ ����������� �����Ӳ����� �Һ��Ӵ��� �ȷ��ʽڵ�Ȩֵ�ٷ����Һ���
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
        if (node[i].l != -1) flag[node[i].l] = 1;  //��ǰ��������Ƿ����
        if (node[i].r != -1) flag[node[i].r] = 1;  //��ǰ����Һ����Ƿ����
    }
    //�����Ҹ��ڵ�
    for (int i = 1; i <= n; ++i) {
        if (flag[i] == 0) {
            root = i;
        }
    }

    //dfs(root);

    cout << DFS(root);

    return 0;
}

