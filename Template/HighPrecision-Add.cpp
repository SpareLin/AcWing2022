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

//vector
vector<int> add(vector<int> &a, vector<int> &b) {
    if(a.size() < b.size()) swap(a, b);
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++) {
        t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if(t) c.push_back(t);
    return c;
}
//string
string add(const string &a, const string &b) {
    string ans;
    int carry = 0;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
        if(i >= 0) carry += (a[i] - '0');
        if(j >= 0) carry += (b[j] - '0');
        ans = char((carry % 10) + '0') + ans;
        carry /= 10;
    }
    return ans;
}


int main() {
    string a, b;
    while(cin >> a >> b) {
        vector<int> A, B;
        for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
        auto C = add(A, B);
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
        cout << endl;
        //cout << add(a, b) << endl;
    }
    return 0;
}
