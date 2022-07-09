/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/2 21:10
* @Description: dp×ö·¨
*/

#include <iostream>

using namespace std;

const int MAXN = 2e5 + 7;

int dp[MAXN], arr[MAXN], n, ans = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        dp[i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        if(arr[i] <= arr[i - 1] * 2) {
            dp[i] = max(dp[i], dp[i - 1] + 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
