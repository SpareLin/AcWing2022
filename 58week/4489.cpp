/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/2 21:09
* @Description: AcWing 4489. 最长子序列
*/

#include <iostream>

using namespace std;

const int MAXN = 2e5 + 7;
int arr[MAXN], n, ans = 1, cnt = 1;

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        if (arr[i + 1] <= arr[i] * 2) {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    //注意最后ans为max(ans, cnt) 因为最后一次更新的cnt还未与ans进行比较
    cout << max(ans, cnt) << endl;

    return 0;
}