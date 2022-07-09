/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/29 21:47
* @Description: 3531. ��������
 * ��Դ�������ʵ��ѧ���л�����
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    //�ر���ͬ��
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    //�൱��һ���󶥶� ���ȶ��������������̴�Ȩ·������
    priority_queue<int, vector<int>, greater<int> > heap;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        heap.push(x);
    }
    int ans = 0;
    while(heap.size() > 1) {
        int t1 = heap.top();
        heap.pop();
        int t2 = heap.top();
        heap.pop();
        heap.push(t1 + t2);
        ans += t1 + t2;
    }
    cout << ans << endl;
    return 0;
}