/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/9 23:54
* @Description: 高精度算法加减乘除
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//判断是否 有 a >= b
bool cmp(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return true;
}

// c = a - b
vector<int> sub(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int t = 0; //表示当前位置的值
    for (int i = 0; i < a.size(); i++) {
        t = a[i] - t;
        if (i < b.size()) t -= b[i]; //判断b有没有这1位
        c.push_back((t + 10) % 10); //若 t >= 0 为 t本身  若 t < 0 则 t + 10
        if (t < 0) t = 1;   //若t < 0 则需要借位
        else t = 0;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();    //去前导0
    return c;
}

int main() {
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(A, B)) {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    } else {
        auto C = sub(B, A);
        cout << '-';
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    }
    return 0;
}
