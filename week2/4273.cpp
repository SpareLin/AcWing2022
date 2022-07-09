/*
* @Author: Spare Lin
* @Project: Project
* @Date: 2022/6/28 13:59
* @Description: 4273. ����ϲ� ��Դ��PAT�׼�����1161
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 7;

int address1, address2, n; //L1 L2ͷ�ڵ�ĵ�ַ �������

struct node{
    int data, next;
}nodep[MAXN];

int main() {
    scanf("%d %d %d", &address1, &address2, &n);
    while(n--) {
        int add;
        scanf("%d", &add);
        scanf("%d %d", &nodep[add].data, &nodep[add].next);
    }
    vector<int> a, b;
    //�����洢��������
    for (int i = address1; i != -1; i = nodep[i].next) {
        a.push_back(i);
    }
    for (int i = address2; i != -1; i = nodep[i].next) {
        b.push_back(i);
    }
    if(a.size() < b.size())  {
        swap(a, b);
    }
    //���϶̵���������
    if(a.size() >= b.size() * 2) {
        reverse(b.begin(), b.end());
    }
    //����ת���L2���������L1
    for (int i = 2, j = 0; j < b.size() ; i += 3, j++) {
        a.insert(a.begin() + i, b[j]);
    }
    for (int i = 0; i < a.size() - 1; i++) {
        printf("%05d %d %05d\n", a[i], nodep[a[i]].data, a[i + 1]);
    }
    printf("%05d %d -1\n", a[a.size() - 1], nodep[a[a.size() - 1]].data);
    return 0;
}