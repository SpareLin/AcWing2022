/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/29 21:47
* @Description: 3531. 哈夫曼树
 * 来源：北京邮电大学考研机试题
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    //关闭流同步
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    //相当于一个大顶堆 优先队列求哈夫曼树最短带权路径长度
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