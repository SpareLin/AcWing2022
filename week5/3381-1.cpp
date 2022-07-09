/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/7 22:56
* @Description: 3381. 手机键盘 打表
*/

#include <iostream>

using namespace std;

int nums[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3,
              1, 2, 3, 4
};

int pos[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7,
             8, 8, 8, 9, 9, 9, 9
};

int Solution(const string &str) {
    int ans = 0;
    int lastPos = 0;
    for (auto &x: str) {
        int i = x - 'a';
        ans += nums[i];
        if (pos[i] == lastPos) ans += 2;
        lastPos = pos[i];
    }
    return ans;
}

int main() {
    string str;
    while (cin >> str) {
        cout << Solution(str) << '\n';
    }
    return 0;
}
