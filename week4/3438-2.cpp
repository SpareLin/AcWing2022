/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/1 21:26
* @Description: 3438. ����ת�� ��Դ��������ѧ���л�����
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    string n;
    cin >> a >> n >> b;
    int res = 0;    //a����ת��Ϊʮ����
    for (auto &x: n) {
        if(isupper(x)) res = res * a + x - 'A' + 10;
        if(islower(x)) res = res * a + x - 'a' + 10;
        if(isdigit(x)) res = res * a + x - '0';
    }
    string ans;     //ʮ����ת��Ϊb����
    while (res) {
        int tmp = res % b;
        if(tmp >= 10)
            ans += char(tmp + 'A' - 10);
        else
            ans += char(tmp + '0');
        res /= b;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}