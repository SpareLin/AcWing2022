/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/9 19:10
* @Description: 4492. ¼õ·¨²Ù×÷
*/
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    bool flag = 0;
    ll x;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            x = i;
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << 1 + (n - x) / 2 << '\n';
    else
        cout << '1' << '\n';
    return 0;
}