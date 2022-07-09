/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/30 21:26
* @Description: 3438. ����ת�� ��Դ��������ѧ���л�����
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, char> um = {
        {0,  '0'}, {1,  '1'}, {2,  '2'}, {3,  '3'},
        {4,  '4'}, {5,  '5'}, {6,  '6'}, {7,  '7'},
        {8,  '8'}, {9,  '9'}, {10, 'A'}, {11, 'B'},
        {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}
};

int main() {
    int a, b;    //��a������nת��Ϊb������
    string n;
    cin >> a >> n >> b;
    //�Ƚ�a����תΪʮ����
    int res = 0;
    for (int i = 0, j = 0; i < n.length(); ++i, ++j) {
        if (isdigit(n[i])) {
            res += pow(a, n.size() - i - 1) * (n[i] - '0');
        } else if (isupper(n[i])) {
            res += pow(a, n.size() - i - 1) * (n[i] - 'A' + 10);
        } else if (islower(n[i])) {
            res += pow(a, n.size() - i - 1) * (n[i] - 'a' + 10);
        }
    }
    //ʮ����תb����
    string ans;
    while (res != 0) ans += um[res % b], res /= b;
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}