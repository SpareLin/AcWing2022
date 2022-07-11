/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/10 22:31
* @Description: AcWing 3715. 最少交换次数
* @URL: https://www.acwing.com/problem/content/3718/
*/

#include <iostream>

using namespace std;

const int N = 1e3 + 9;
int a[N], b[N], n, ans = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                b[a[i]]++;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                ans++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
    cout << '\n' << ans << endl;
}