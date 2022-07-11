/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/9 19:08
* @Description: 4491. 数组操作 AcWing,第59场周赛
*/

#include <iostream>

using namespace std;

const int MAXN = 1e2 + 7;
int n, sum, x, a[MAXN], s[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 0; i <= n; ++i) {
        x = min(x, s[i]);
    }
    cout << sum - x << endl;
    return 0;
}