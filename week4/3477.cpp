/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/29 16:53
* @Description: 3477. 简单排序 来源：上海交通大学考研机试题
*/

#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (auto &x: s) {
        cout << x << ' ';
    }
}
