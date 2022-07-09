/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/8 21:15
* @Description: 3598. 二叉树遍历 来源：华中科技大学考研机试题
*/

#include <iostream>
#include <unordered_set>

using namespace std;

string preOrder, midOrder;

void dfs(int l, int r) {
    if (l > r) return;

    unordered_set<char> s;

    for (int i = l; i <= r; i++) {
        s.insert(midOrder[i]);
    }

    for (int i = 0; i < preOrder.size(); ++i) {
        if (s.count(preOrder[i])) {
            dfs(l, midOrder.find(preOrder[i]) - 1);
            dfs(midOrder.find(preOrder[i]) + 1, r);
    while (cin >> preOrder >> midOrder) {
        dfs(0, midOrder.size() - 1);
        cout << endl;
    }
    cout << preOrder[i];
    break;
}
}
}

int main() {
    return 0;
}